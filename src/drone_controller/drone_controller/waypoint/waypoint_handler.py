import rclpy
import time

from rclpy.node import Node
from drone_interfaces.action import ExecuteWaypoint
from drone_interfaces.srv import YoloRequest
from rclpy.action import ActionServer, GoalResponse
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from std_msgs.msg import Header, Float64
from mavros_msgs.msg import GlobalPositionTarget, PositionTarget
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import PoseStamped, Vector3

from drone_controller.utils import *
from drone_controller.constant import *
from drone_controller.waypoint.waypoint_task_executor import WaypointTaskExecutor


class WaypointHandler(Node):
    def __init__(self):
        super().__init__('waypoint_handler')

        self.waypoint_task_executor = WaypointTaskExecutor()

        self.yolo_client = self.create_client(YoloRequest, '/drone/yolo_request')

        while not self.yolo_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Yolo service to be available...")

        qos_profile = QoSProfile(reliability=ReliabilityPolicy.RELIABLE, history=HistoryPolicy.KEEP_LAST, depth=10)

        self._action_server = ActionServer(self, ExecuteWaypoint, '/drone/execute_waypoint', self.execute_callback, goal_callback=self.goal_callback, \
                                           goal_service_qos_profile=qos_profile, cancel_service_qos_profile=qos_profile)

        self.pose_publisher = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', 10)
        self.global_point_publisher = self.create_publisher(GlobalPositionTarget, '/mavros/setpoint_raw/global', 10)

        qos_profile = QoSProfile(reliability=ReliabilityPolicy.BEST_EFFORT, history=HistoryPolicy.KEEP_LAST, depth=10)

        self.global_pos_sub = self.create_subscription(NavSatFix, '/mavros/global_position/global', self.global_pos_callback, qos_profile)
        self.local_pos_sub = self.create_subscription(PoseStamped, '/mavros/local_position/pose', self.local_pos_callback, qos_profile)
        self.yaw_sub = self.create_subscription(Float64, '/mavros/global_position/compass_hdg', self.yaw_callback, qos_profile)
        self.rel_alt_sub = self.create_subscription(Float64, '/mavros/global_position/rel_alt', self.rel_alt_callback, qos_profile)

        self.gps_fix = None
        self.local_pose = None
        self.yaw = 0.0
        self.rel_alt = 0.0

    def goal_callback(self, goal_request):
        self.get_logger().info(f'{goal_request}')
        return GoalResponse.ACCEPT

    def global_pos_callback(self, msg: NavSatFix):
        self.gps_fix = msg

    def local_pos_callback(self, msg: PoseStamped):
        self.local_pose = msg

    def yaw_callback(self, msg: Float64):
        self.yaw = msg.data
    
    def rel_alt_callback(self, msg: Float64):
        self.rel_alt = msg.data

    def execute_callback(self, goal_handle):
        waypoint = goal_handle.request.waypoint
        self.process_waypoint(waypoint)

        result_msg = ExecuteWaypoint.Result()
        result_msg.success = True

        goal_handle.succeed()
        return result_msg
    
    def yolo_request(self, start: bool):
        req = YoloRequest.Request()
        req.start = start
        future = self.yolo_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result().success:
            self.get_logger().info('Request yolo service successfully.')
        else:
            self.get_logger().error('Failed to request yolo service.')
    
    def process_waypoint(self, waypoint):
        target = GlobalPositionTarget()
        self.setup_params(waypoint, target)
        
        cur_time = time.time()
        while True:
            rclpy.spin_once(self)
            if time.time() - cur_time < 0.1:
                continue

            if self.reached_waypoint(waypoint):
                break

            target.header.stamp = self.get_clock().now().to_msg()
            if waypoint.type == TYPE_ROTATE:
                yaw_diff = waypoint.yaw - self.yaw
                target.yaw_rate = calculate_rotation_speed(yaw_diff)

            self.global_point_publisher.publish(target)
            cur_time = time.time() 

        if waypoint.mission == MISSION_GLOBAL_CLEAN:
            self.yolo_request(True)
            self.waypoint_task_executor.execute_clean_task()
            self.yolo_request(False)
        elif waypoint.mission == MISSION_LOCAL_CAPTURE:
            self.waypoint_task_executor.execute_capture_task()

    def reached_waypoint(self, waypoint) -> bool:
        reached = True
        
        if waypoint.type == TYPE_ROTATE:
            reached &= abs(waypoint.yaw - self.yaw) <= THRESHOLD_YAW
        elif waypoint.type == TYPE_NAVIGATION or waypoint.type == TYPE_HORIZONTAL or waypoint.type == TYPE_START:
            reached &= abs(waypoint.latitude - self.gps_fix.latitude) <= THRESHOLD_LATITUDE
            reached &= abs(waypoint.longitude - self.gps_fix.longitude) <= THRESHOLD_LONGITUDE
        elif waypoint.type == TYPE_TAKEOFF or waypoint.type == TYPE_VERTICAL:
            reached &= abs(waypoint.altitude - self.rel_alt) <= THRESHOLD_ALTITUDE
        elif waypoint.type == TYPE_LAND:
            reached &= abs(waypoint.altitude - self.rel_alt) <= 1
        else:
            reached &= abs(waypoint.latitude - self.gps_fix.latitude) <= THRESHOLD_LATITUDE
            reached &= abs(waypoint.longitude - self.gps_fix.longitude) <= THRESHOLD_LONGITUDE
            reached &= abs(waypoint.altitude - self.rel_alt) <= THRESHOLD_ALTITUDE

        if reached:
            self.get_logger().info(f'Drone has reached the {waypoint.type} target')
            self.get_logger().info(f'current {self.gps_fix, self.rel_alt, self.yaw}, \
                                target {waypoint.latitude, waypoint.longitude, waypoint.altitude, waypoint.yaw}')

        return reached

    def setup_params(self, raw_wp, target: GlobalPositionTarget):
        target.header = Header(stamp=self.get_clock().now().to_msg())
        target.coordinate_frame = FRAME_GLOBAL_REL_ALT
        target.latitude = raw_wp.latitude
        target.longitude = raw_wp.longitude
        target.altitude = raw_wp.altitude

        type_mask = PositionTarget.IGNORE_YAW | PositionTarget.IGNORE_AFX | PositionTarget.IGNORE_AFY | PositionTarget.IGNORE_AFZ

        if raw_wp.type == TYPE_TAKEOFF or raw_wp.type == TYPE_VERTICAL or raw_wp.type == TYPE_LAND:
            target.velocity = Vector3(x=0.0, y=0.0, z=raw_wp.velocity)
            type_mask |= PositionTarget.IGNORE_VX | PositionTarget.IGNORE_VY | PositionTarget.IGNORE_YAW_RATE
        elif raw_wp.type == TYPE_ROTATE:
            # target.yaw_rate = raw_wp.yaw_rate
            type_mask |= PositionTarget.IGNORE_VX | PositionTarget.IGNORE_VY | PositionTarget.IGNORE_VZ
        # else:
        #     target.velocity = Vector3(x=raw_wp.velocity, y=0.0, z=0.0)

        target.type_mask = type_mask

def main(args=None):
    rclpy.init(args=args)

    waypoint_handler = WaypointHandler()

    while rclpy.ok():
        rclpy.spin_once(waypoint_handler)

    waypoint_handler.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
