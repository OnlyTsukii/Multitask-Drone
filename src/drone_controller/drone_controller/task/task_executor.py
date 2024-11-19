import time
import rclpy

from queue import Queue
from rclpy.node import Node
from drone_interfaces.srv import TaskDispatch
from drone_interfaces.msg import Task, RawWaypoint
from drone_interfaces.action import ExecuteWaypoint
from rclpy.action import ActionClient
from std_msgs.msg import Float64
from geometry_msgs.msg import PoseStamped, Vector3
from sensor_msgs.msg import NavSatFix, NavSatStatus
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from drone_controller.utils import *
from drone_controller.constant import *


class TaskExecutor(Node):
    def __init__(self):
        super().__init__('task_executor')

        qos_profile = QoSProfile(reliability=ReliabilityPolicy.BEST_EFFORT, history=HistoryPolicy.KEEP_LAST, depth=10)
        self.gps_sub = self.create_subscription(NavSatFix, '/mavros/global_position/global', self.gps_callback, qos_profile)
        self.yaw_sub = self.create_subscription(Float64, '/mavros/global_position/compass_hdg', self.yaw_callback, qos_profile)
        self.rel_alt_sub = self.create_subscription(Float64, '/mavros/global_position/rel_alt', self.rel_alt_callback, qos_profile)

        self.task_srv = self.create_service(TaskDispatch, '/drone/dispatch_task', self.handle_task_request)

        qos_profile = QoSProfile(reliability=ReliabilityPolicy.RELIABLE, history=HistoryPolicy.KEEP_LAST, depth=10)
        self.waypoint_action_client = ActionClient(self, ExecuteWaypoint, '/drone/execute_waypoint', \
                                                   goal_service_qos_profile=qos_profile, cancel_service_qos_profile=qos_profile)

        self.pending_tasks = Queue()

        self.gps_fix = None
        self.yaw = float('nan')
        self.rel_alt = 0.0

        self.goal_finished = False
        self.has_takeoff = False

        self.get_logger().info("Task Executor Initialized and Waiting for Requests.")

    def gps_callback(self, msg):
        self.gps_fix = msg

    def yaw_callback(self, msg):
        self.yaw = msg.data
    
    def rel_alt_callback(self, msg: Float64):
        self.rel_alt = msg.data
    
    def handle_task_request(self, request, response):
        """
        Handle incoming task dispatch requests and add the task to the pending queue.
        """
        try:
            self.pending_tasks.put(request.task)
            self.get_logger().info(f"Task added to the pending queue: {request.task}")

            response.success = True
        except Exception as e:
            self.get_logger().error(f"Failed to add task to queue: {e}")
            response.success = False

        return response

    def execute_takeoff(self, id, altitude=DEFAULT_TAKEOFF_ALTITUDE):
        rclpy.spin_once(self)

        takeoff_wp = RawWaypoint(
            id = id,
            type = TYPE_TAKEOFF,
            mission = MISSION_NONE,
            latitude=self.gps_fix.latitude,
            longitude=self.gps_fix.longitude,
            altitude=float(altitude),
            velocity=DEFAULT_VERTICAL_VEL
        )

        self.send_waypoint_action(takeoff_wp)

        self.get_logger().info('Drone takeoff successfully.')
        self.has_takeoff = True

    def execute_land(self, id):
        rclpy.spin_once(self)

        land_wp = RawWaypoint(
            id = id,
            type = TYPE_LAND,
            mission = MISSION_NONE,
            latitude=self.gps_fix.latitude,
            longitude=self.gps_fix.longitude,
            altitude=0.0,
            velocity=-1*DEFAULT_VERTICAL_VEL
        )

        self.send_waypoint_action(land_wp)

        self.get_logger().info('Drone land successfully.')
        self.has_takeoff = False

    def execute_rotate(self, id, target_wp):
        """
        Create an yaw_adjust waypoint based on a given waypoint and yaw.
        """
        rclpy.spin_once(self)

        yaw = calculate_yaw(
                self.gps_fix.latitude, 
                self.gps_fix.longitude, 
                target_wp.latitude, 
                target_wp.longitude
            )

        rotate_wp = RawWaypoint(
            id = id,
            type = TYPE_ROTATE,
            mission = MISSION_NONE,
            latitude=self.gps_fix.latitude,
            longitude=self.gps_fix.longitude,
            altitude=target_wp.altitude,
            yaw=yaw
        )

        self.send_waypoint_action(rotate_wp)

    def process_pending_tasks(self):
        """
        Process the pending tasks in the queue.
        """
        while rclpy.ok():
            rclpy.spin_once(self)

            if self.pending_tasks.qsize() > 0:
                task = self.pending_tasks.get()

                next_waypoint_id = 0

                length = len(task.waypoints)
                index = 0

                if not self.has_takeoff:
                    self.execute_takeoff(next_waypoint_id)
                    next_waypoint_id += 1

                    self.execute_rotate(next_waypoint_id, task.waypoints[0])
                    next_waypoint_id += 1
            
                while index < length:
                    self.get_logger().info(f'{length, index}')
                    waypoint = task.waypoints[index]
                    waypoint.id = next_waypoint_id
                    self.send_waypoint_action(waypoint)
                    next_waypoint_id += 1
                    
                    if (waypoint.type == TYPE_START or waypoint.type == TYPE_NAVIGATION) and index < length - 1:
                        self.execute_rotate(next_waypoint_id, task.waypoints[index+1])
                        next_waypoint_id += 1

                    index += 1

                if self.has_takeoff:
                    self.execute_land(next_waypoint_id)
                    next_waypoint_id += 1

                self.get_logger().info(f"Task completed.")
            else:
                time.sleep(1.0)

    def send_waypoint_action(self, waypoint):
        """
        Send a waypoint action to the waypoint handler and return the feedback.
        """
        goal_msg = ExecuteWaypoint.Goal()
        goal_msg.waypoint = waypoint

        if not self.waypoint_action_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('Waypoint Action Server not available!')
            return

        goal_future = self.waypoint_action_client.send_goal_async(goal_msg)
        goal_future.add_done_callback(self.goal_response_callback)

        while not self.goal_finished:
            rclpy.spin_once(self, timeout_sec=0.1)

        self.goal_finished = False
    
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return

        self.get_logger().info('Goal accepted')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result: {result}')
        self.goal_finished = True

    # def cancel_goal(self):
    #     if self._goal_handle:
    #         cancel_future = self._goal_handle.cancel_goal_async()
    #         cancel_future.add_done_callback(self.cancel_done_callback)

    # def cancel_done_callback(self, future):
    #     cancel_response = future.result()
    #     if cancel_response.goals_cancel_response.return_code == 1: 
    #         self.get_logger().info('Goal canceled successfully')
    #     else:
    #         self.get_logger().info('Goal cancelation failed')


def main(args=None):
    rclpy.init(args=args)

    task_executor = TaskExecutor()

    task_executor.process_pending_tasks()

    task_executor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
