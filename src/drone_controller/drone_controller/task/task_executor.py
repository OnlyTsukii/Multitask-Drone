import time
import rclpy
import json

from queue import Queue
from rclpy.node import Node
from drone_interfaces.srv import TaskDispatch, YoloRequest
from drone_interfaces.msg import Task, RawWaypoint, TaskState, UavData
from drone_interfaces.action import ExecuteWaypoint
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from mavros_msgs.srv import CommandTOL, SetMode, CommandLong

from drone_controller.utils import *
from drone_controller.constant import *

home_dir = os.environ.get("HOME")
JSON_PATH = home_dir + "/Multitask-Drone/src/json_paths/path.json"


class TaskExecutor(Node):
    def __init__(self):
        super().__init__("task_executor")

        self.user = os.getenv("USER")

        self.task_srv = self.create_service(
            TaskDispatch, "/drone/dispatch_task", self.handle_task_request
        )

        self.land_client = self.create_client(CommandTOL, "/mavros/cmd/land")
        self.yolo_client = self.create_client(YoloRequest, "/drone/yolo_request")
        self.mode_client = self.create_client(SetMode, "/mavros/set_mode")

        while not self.land_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Land service to be available...")

        # while not self.yolo_client.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().info("Waiting for Yolo service to be available...")

        while not self.mode_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Mode service not available, waiting...")

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )
        self.waypoint_action_client = ActionClient(
            self,
            ExecuteWaypoint,
            "/drone/execute_waypoint",
            goal_service_qos_profile=qos_profile,
            cancel_service_qos_profile=qos_profile,
        )
        self.uav_data_hub_sub = self.create_subscription(
            UavData, "/uav/uav_data", self.data_callback, qos_profile
        )
        self.pending_tasks = Queue()
        self.feedback = []

        self.gps_fix = None
        self.yaw = float("nan")
        self.rel_alt = 0.0
        self.state = None

        self.goal_finished = False
        self.has_takeoff = False

        self.get_logger().info("Task Executor Initialized and Waiting for Requests.")

    def data_callback(self, msg: UavData):
        self.gps_fix = msg.gps_fix
        self.yaw = msg.yaw
        self.rel_alt = msg.rel_alt
        self.state = msg.state

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

    def set_mode(self, mode) -> bool:
        req = SetMode.Request()
        req.custom_mode = mode
        future = self.mode_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result().mode_sent:
            self.get_logger().info(f"Mode set to {mode} successfully.")
            return True
        else:
            self.get_logger().error(f"Failed to set mode to {mode}.")
            return False

    def execute_takeoff(self, id, altitude=DEFAULT_TAKEOFF_ALTITUDE):
        rclpy.spin_once(self)
        takeoff_wp = RawWaypoint(
            id=id,
            type=TYPE_TAKEOFF,
            mission=MISSION_NONE,
            latitude=self.gps_fix.latitude,
            longitude=self.gps_fix.longitude,
            altitude=float(altitude),
            velocity=DEFAULT_VERTICAL_VEL,
        )

        self.send_waypoint_action(takeoff_wp, True)

        self.get_logger().info("Drone takeoff successfully.")
        self.has_takeoff = True

    def execute_land(self,id):
        rclpy.spin_once(self)
        req = CommandTOL.Request()
        req.latitude = self.gps_fix.latitude
        req.longitude = self.gps_fix.longitude
        req.altitude = 0.0
        req.yaw = self.yaw
        req.min_pitch = 0.0

        future = self.land_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if self.user == "nx8g01":
            future = self.land_client.call_async(req)
            rclpy.spin_until_future_complete(self, future)

        if future.result().success:
            while self.state.armed:
                rclpy.spin_once(self)
                time.sleep(0.3)
            self.get_logger().info("Drone landed successfully.")
            self.has_takeoff = False
        else:
            self.get_logger().error("Failed to land.")

    def execute_rotate(self, id, target_wp:RawWaypoint):
        """
        Create an yaw_adjust waypoint based on a given waypoint and yaw.
        """
        rclpy.spin_once(self)

        yaw = calculate_yaw(
            self.gps_fix.latitude,
            self.gps_fix.longitude,
            target_wp.latitude,
            target_wp.longitude,
        )

        rotate_wp = RawWaypoint(
            id=id,
            type=TYPE_ROTATE,
            mission=MISSION_NONE,
            latitude=self.gps_fix.latitude,
            longitude=self.gps_fix.longitude,
            altitude=target_wp.altitude,
            yaw=yaw,
        )

        self.send_waypoint_action(rotate_wp)

    def process_pending_tasks(self):
        """
        Process the pending tasks in the queue.
        """
        while rclpy.ok():
            rclpy.spin_once(self)
            # self.state_pub.publish(TaskState(state=1))

            if self.pending_tasks.qsize() > 0:
                self.feedback = []

                task:Task = self.pending_tasks.get()

                next_waypoint_id = 0

                length = len(task.waypoints)
                index = 0

                if not self.has_takeoff:
                    self.execute_takeoff(next_waypoint_id, task.waypoints[0].altitude)
                    next_waypoint_id += 1

                # if self.user != "nx8g01":
                #     self.execute_rotate(next_waypoint_id, task.waypoints[0])
                #     next_waypoint_id += 1

                while index < length:
                    waypoint = task.waypoints[index]
                    waypoint.id = next_waypoint_id

                    self.send_waypoint_action(waypoint, True)
                    next_waypoint_id += 1

                    # if self.user != "nx8g01":
                    #     if (waypoint.type == TYPE_START or waypoint.type == TYPE_NAVIGATION) and index < length - 1:
                    #         self.execute_rotate(next_waypoint_id, task.waypoints[index+1])
                    #         next_waypoint_id += 1

                    index += 1

                self.get_logger().info(f"Task completed.")

                with open(JSON_PATH, "w") as json_file:
                    json.dump(self.feedback, json_file, indent=4)
            else:
                if self.has_takeoff:
                    self.execute_land(next_waypoint_id)
                    next_waypoint_id = 0
                    if self.user != "nx8g01":
                        self.set_mode("AUTO.LOITER")

    def send_waypoint_action(self, waypoint:RawWaypoint, join_feedback=False):
        """
        Send a waypoint action to the waypoint handler and return the feedback.
        """
        goal_msg = ExecuteWaypoint.Goal()
        goal_msg.waypoint = waypoint

        if not self.waypoint_action_client.wait_for_server(timeout_sec=3.0):
            self.get_logger().error("Waypoint Action Server not available!")
            return

        goal_future = self.waypoint_action_client.send_goal_async(goal_msg)
        goal_future.add_done_callback(self.goal_response_callback)

        while not self.goal_finished:
            rclpy.spin_once(self)
            time.sleep(0.01)
            # self.state_pub.publish(TaskState(state=0))

        if join_feedback:
            real_waypoint = {}
            real_waypoint["latitude"] = self.gps_fix.latitude
            real_waypoint["longitude"] = self.gps_fix.longitude
            real_waypoint["altitude"] = self.gps_fix.altitude
            real_waypoint["type"] = waypoint.type
            real_waypoint["mission"] = waypoint.mission
            real_waypoint["velocity"] = 1.0

            self.feedback.append(real_waypoint)

        self.goal_finished = False

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info("Goal rejected")
            return

        self.get_logger().info("Goal accepted")
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: {result}")
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


if __name__ == "__main__":
    main()
