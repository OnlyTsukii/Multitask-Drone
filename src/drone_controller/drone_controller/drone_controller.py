import json
import websockets
import asyncio
import rclpy
import time
import rclpy.logging

from rclpy.node import Node
from mavros_msgs.msg import State
from drone_interfaces.srv import TaskDispatch
from geometry_msgs.msg import PoseStamped, Point, Quaternion
from std_msgs.msg import Header
from mavros_msgs.srv import CommandBool, SetMode, CommandTOL

from drone_controller.utils import *
from drone_controller.constant import *
from drone_controller.task.task_handler import TaskHandler


class DroneController(Node):
    def __init__(self):
        super().__init__('drone_controller')

        self.pose_pub = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', 10)
        self.state_sub = self.create_subscription(State, '/mavros/state', self.state_callback, 10)

        self.task_handler = TaskHandler()
        self.state = None

        self.task_client = self.create_client(TaskDispatch, '/drone/dispatch_task')
        self.arming_client = self.create_client(CommandBool, '/mavros/cmd/arming')
        self.mode_client = self.create_client(SetMode, '/mavros/set_mode')
        
        self.takeoff_client = self.create_client(CommandTOL, '/mavros/cmd/takeoff')
        self.land_client = self.create_client(CommandTOL, '/mavros/cmd/land')

        while not self.task_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for TaskDispatch service to be available...")

        while not self.arming_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Arming service not available, waiting...')
        
        while not self.mode_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Mode service not available, waiting...')
        
        self.get_logger().info('All services are available, ready to arm and take off.')


    def state_callback(self, msg: State):
        self.state = msg

    def preflight(self) -> bool:
        rclpy.spin_once(self)
        if self.state == None or not self.state.connected:
            return False
        
        # if self.state.mode == 'OFFBOARD' and self.state.armed:
        #     return True
        
        for _ in range(10):
            self.init_pose()
            res = self.set_mode('OFFBOARD')
            if res:
                break
            time.sleep(2)
        if not res:
            return False
        
        return self.arm_drone()

    def init_pose(self, time_sec=1.5):
        waypoint = PoseStamped()
        waypoint.header = Header()
        waypoint.header.stamp = self.get_clock().now().to_msg()
        waypoint.pose.position = Point(x=0.0, y=0.0, z=0.0)
        waypoint.pose.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)

        iter = int(time_sec / 0.05)
        for _ in range(iter):
            self.pose_pub.publish(waypoint)
            time.sleep(0.05)

    def send_task_request(self, task) -> bool:
        request = TaskDispatch.Request()
        request.task = task
        future = self.task_client.call_async(request)

        while not future.done():
            self.init_pose(0.5)
            rclpy.spin_once(self)

        res = future.result().success
        if res:
            self.get_logger().info('Task Dispatched successfully.')
        else:
            self.get_logger().info('Failed to dispatch task.')

        return res

    def arm_drone(self) -> bool:
        req = CommandBool.Request()
        req.value = True
        future = self.arming_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result().success:
            self.get_logger().info('Drone armed successfully.')
            return True
        else:
            self.get_logger().error('Failed to arm drone.')
            return False

    def disarm_drone(self):
        req = CommandBool.Request()
        req.value = False
        future = self.arming_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result().success:
            self.get_logger().info('Drone disarmed successfully.')
        else:
            self.get_logger().error('Failed to disarm drone.')

    def set_mode(self, mode) -> bool:
        req = SetMode.Request()
        req.custom_mode = mode
        future = self.mode_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result().mode_sent:
            self.get_logger().info(f'Mode set to {mode} successfully.')
            return True
        else:
            self.get_logger().error(f'Failed to set mode to {mode}.')
            return False

    async def send_response(self, socket, response):
        try:
            await socket.send(json.dumps(response))
        except Exception as e:
            self.get_logger().info(f"Failed to send response: {e}")

    async def start_websocket_server(self):
        async with websockets.serve(self.websocket_handler, SOCKET_IP, SOCKET_PORT):
            self.get_logger().info(f"WebSocket server started at ws://{SOCKET_IP}:{SOCKET_PORT}")
            await asyncio.Future() 

    async def websocket_handler(self, websocket, path):
        async for message in websocket:
            self.get_logger().info(f'receive websocket message: {message}')
            task, response = self.task_handler.handle_json_data(message, websocket)
            if response == None:
                res = self.preflight()
                if not res:
                    response = {"status": "error", "message": "Failed to preflight"}
                else:
                    res = self.send_task_request(task)
                    if res:
                        response = {"status": "success", "message": "Task dispatched successfully"}
                    else:
                        response = {"status": "error", "message": "Failed to dispatch task"}
            await self.send_response(websocket, response)

def main(args=None):
    rclpy.init(args=args)

    try:
        drone_controller = DroneController()
        drone_controller.get_logger().info("DroneController node initialized.")

        asyncio.run(drone_controller.start_websocket_server())

    except KeyboardInterrupt:
        drone_controller.get_logger().info("Shutting down DroneController node.")
    except Exception as e:
        drone_controller.get_logger().info(f"Unhandled exception: {e}")
    finally:
        if rclpy.ok():
            drone_controller.destroy_node()
            rclpy.shutdown()

if __name__ == "__main__":
    main()