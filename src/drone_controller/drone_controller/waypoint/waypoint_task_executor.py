import rclpy
import time
import math

from rclpy.node import Node
from geometry_msgs.msg import Vector3, Point
from mavros_msgs.msg import PositionTarget
from geometry_msgs.msg import Point
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import Header, Float64
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from drone_interfaces.msg import PanelBox, Yaw
from drone_interfaces.srv import YoloRequest

from drone_controller.utils import *
from drone_controller.constant import *


class WaypointTaskExecutor(Node):

    def __init__(self):
        super().__init__('waypoint_task_executor')
        
        self.gps_fix = None
        self.panel_yaw = float('nan')
        self.rel_alt = 0.0

        self.max_retries = 0
        self.panel_found = 0
        self.panel_loss = 0

        self.panel_pos = None
        self.panel_detected = False
        self.task_finished = False
        self.task_pending = False
        self.task_point_reached = False
        self.panel_center_reached = False
        self.task_ready = False
        
        self.capture_client = self.create_client(YoloRequest, '/drone/capture_request')

        while not self.capture_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Capture service to be available...")

        self.local_point_publisher = self.create_publisher(PositionTarget, '/mavros/setpoint_raw/local', 10)

        qos_profile = QoSProfile(reliability=ReliabilityPolicy.BEST_EFFORT, history=HistoryPolicy.KEEP_LAST, depth=10)
        self.global_pos_sub = self.create_subscription(NavSatFix, '/mavros/global_position/global', self.global_pos_callback, qos_profile)
        self.rel_alt_sub = self.create_subscription(Float64, '/mavros/global_position/rel_alt', self.rel_alt_callback, qos_profile)

        self.panel_sub = self.create_subscription(PanelBox, '/drone/panel_box', self.panel_callback, 10)
        self.panel_yaw_sub = self.create_subscription(Yaw, '/drone/panel_yaw', self.panel_yaw_callback, 10)

    def global_pos_callback(self, msg):
        self.gps_fix = msg

    def panel_yaw_callback(self, msg):
        self.panel_yaw = msg.yaw

    def rel_alt_callback(self, msg: Float64):
        self.rel_alt = msg.data

    def panel_callback(self, msg):
        if msg.x == 0 and msg.y == 0 and msg.w == 0 and msg.h == 0:
            if not self.panel_detected:
                self.panel_pos = None
            self.panel_loss += 1
            self.panel_found = 0
            if self.panel_loss == 30:
                self.panel_detected = False
                self.panel_loss = 0
                self.panel_pos = None
        else:
            if self.panel_detected:
                self.panel_pos = msg
            self.panel_found += 1
            self.panel_loss = 0
            if self.panel_found == 5:
                self.panel_found = 0
                self.panel_detected = True
                self.panel_pos = msg

    def execute_capture_task(self):
        req = YoloRequest.Request()
        future = self.capture_client.call_async(req)

        while not future.done():
            self.body_move(BODY_HOLD)
            rclpy.spin_once(self)
            time.sleep(0.1)

        if future.result().success:
            self.get_logger().info('Request capture service successfully.')
        else:
            self.get_logger().error('Failed to request capture service.')

    def execute_clean_task(self):
        if not self.panel_detected:
            if not self.find_panel():
                self.panel_yaw = float('nan')
                return
            
        if not self.goto_panel_center():
            self.panel_yaw = float('nan')
            return
        
        if not self.adjust_yaw():
            self.panel_yaw = float('nan')
            return
        
        if not self.goto_task_point():
            self.panel_yaw = float('nan')
            return

        count = 0
        while rclpy.ok():
            self.body_move(BODY_HOLD)
            rclpy.spin_once(self)
            time.sleep(0.2)
            count += 1
            if count == 15:
                break
        
        if not self.goto_task_end():
            self.panel_yaw = float('nan')
            return
        
        self.panel_yaw = float('nan')

    def find_panel(self) -> bool:
        while self.gps_fix == None:
            rclpy.spin_once(self)
            self.body_move(BODY_HOLD)
            time.sleep(0.3)

        prev_altitude = self.gps_fix.altitude

        timestamp = time.time()
        while rclpy.ok():
            rclpy.spin_once(self)
            if time.time() - timestamp < 0.3:
                continue
            if self.gps_fix.altitude - prev_altitude > 10.0:
                self.get_logger().info('panel not found, navigate to next waypoint')
                return False
            self.body_move(BODY_UP)

            self.get_logger().info('drone climbing...')
                
            if self.panel_detected:
                self.get_logger().info('panel detected, go to panel center')
                return True
            timestamp = time.time()

    def goto_panel_center(self) -> bool:
        timestamp = time.time()

        while rclpy.ok():
            rclpy.spin_once(self)
            if time.time() - timestamp < 0.3:
                continue

            if not self.panel_detected:
                self.get_logger().info('panel edge not found, navigate to next waypoint')
                return False
            
            panel_pos = self.panel_pos

            px, py = calculate_panel_pos_thres(self.rel_alt)

            move_left_right = BODY_HOLD
            if panel_pos.x > px:
                move_left_right = BODY_LEFT
            elif panel_pos.x < -1 * px:
                move_left_right = BODY_RIGHT
            
            move_forward_backward = BODY_HOLD
            if panel_pos.y > py:
                move_forward_backward = BODY_FORWARD
            elif panel_pos.y < -1 * py:
                move_forward_backward = BODY_BACKWARD

            move_up_down = BODY_HOLD
            if panel_pos.w < IMAGE_WIDTH/4 or panel_pos.h < IMAGE_HEIGHT/4:
                move_up_down = BODY_DOWN

            move_direction = move_left_right | move_forward_backward | move_up_down
            if move_direction != BODY_HOLD:
                self.body_move(move_direction)
            else:
                self.get_logger().info("panel center reached") 
                return True
            pass
            timestamp = time.time()

    def adjust_yaw(self) -> bool:
        timestamp = time.time()

        while rclpy.ok():
            rclpy.spin_once(self)
            if time.time() - timestamp < 0.3:
                continue

            if not self.panel_detected:
                self.get_logger().info('panel edge not found, navigate to next waypoint')
                return False
            
            if not math.isnan(self.panel_yaw):
                self.max_retries = 0
                if self.panel_yaw > PANEL_YAW_THRES:
                    self.body_move(BODY_ROTATE_CLOCKWISE)
                elif self.panel_yaw < -1 * PANEL_YAW_THRES:
                    self.body_move(BODY_ROTATE_COUNTERCW)
                else:
                    self.get_logger().info("target yaw reached") 
                    return True
            else:
                self.body_move(BODY_HOLD)
                self.max_retries += 1
                if self.max_retries == 30:
                    self.max_retries = 0
                    self.get_logger().info('panel edge not found, navigate to next waypoint')
                    return False
            pass
            timestamp = time.time()

    def goto_task_point(self) -> bool:
        timestamp = time.time()
        while rclpy.ok():
            rclpy.spin_once(self)
            if time.time() - timestamp < 0.3:
                continue

            if not self.panel_detected:
                self.get_logger().info('panel edge not found, navigate to next waypoint')
                return False
            
            panel_pos = self.panel_pos

            px, _ = calculate_panel_pos_thres(self.rel_alt)

            move_left_right = BODY_HOLD
            if panel_pos.x > px:
                move_left_right = BODY_LEFT
            elif panel_pos.x < -1 * px:
                move_left_right = BODY_RIGHT
            
            move_forward_backward = BODY_HOLD
            bottom_edge_pos_y = panel_pos.y - panel_pos.h / 2
            if bottom_edge_pos_y < 0:
                move_forward_backward = BODY_BACKWARD
            elif bottom_edge_pos_y > 150:
                move_forward_backward = BODY_FORWARD

            move_up_down = BODY_HOLD
            if panel_pos.w < IMAGE_WIDTH/3 or panel_pos.h < IMAGE_HEIGHT/2.5:
                move_up_down = BODY_DOWN

            move_direction = move_left_right | move_forward_backward | move_up_down
            if move_direction != BODY_HOLD:
                self.body_move(move_direction, velocity=0.3)
            else:
                self.get_logger().info("task point reached") 
                return True
            pass
            timestamp = time.time()

    def goto_task_end(self) -> bool:
        timestamp = time.time()
        while rclpy.ok():
            rclpy.spin_once(self)
            if time.time() - timestamp < 0.3:
                continue

            if not self.panel_detected:
                self.get_logger().info('panel edge not found, navigate to next waypoint')
                return False
            
            panel_pos = self.panel_pos

            # px, _ = calculate_panel_pos_thres(self.rel_alt)
            move_left_right = BODY_HOLD
            # if panel_pos.x > px:
            #     move_left_right = BODY_LEFT
            # elif panel_pos.x < -1 * px:
            #     move_left_right = BODY_RIGHT
            
            move_forward_backward = BODY_HOLD
            top_edge_pos_y = panel_pos.h / 2 + panel_pos.y
            if top_edge_pos_y > 0:
                move_forward_backward = BODY_FORWARD
            else:
                self.get_logger().info("task finished")
                return True

            move_direction = move_left_right | move_forward_backward
            self.get_logger().info("executing task ...")
            # TODO: CLEAN
            self.body_move(move_direction)
            
            timestamp = time.time()
    
    def body_move(self, direction, velocity=DEFAULT_BODY_VEL):
        point = PositionTarget()
        point.header = Header()
        point.header.stamp = self.get_clock().now().to_msg()   
        point.coordinate_frame = FRAME_BODY_NED

        if direction == BODY_ROTATE_CLOCKWISE or direction == BODY_ROTATE_COUNTERCW:
            point.type_mask = PositionTarget.IGNORE_YAW | PositionTarget.IGNORE_AFX | PositionTarget.IGNORE_AFY | PositionTarget.IGNORE_AFZ
            point.velocity = Vector3(x=0.0, y=0.0, z=0.0)
            point.position = Point(x=0.0, y=0.0, z=0.0)
            if direction == BODY_ROTATE_CLOCKWISE:
                point.yaw_rate = -1 * 0.2
            else:
                point.yaw_rate = 0.2
        else:
            point.type_mask = PositionTarget.IGNORE_YAW_RATE | PositionTarget.IGNORE_YAW | PositionTarget.IGNORE_AFX | PositionTarget.IGNORE_AFY | PositionTarget.IGNORE_AFZ
            
            coeff_x = direction >> 2 & 3
            coeff_y = direction >> 4 & 3
            coeff_z = direction & 3

            if coeff_x == 2:
                coeff_x = -1
            if coeff_y == 2:
                coeff_y = -1
            if coeff_z == 2:
                coeff_z = -1

            # self.get_logger().info(f'direction: {direction}, parameter coefficients: x {coeff_x}, y {coeff_y}, z {coeff_z}')

            if not -1 <= coeff_x <= 1 or not -1 <= coeff_y <= 1 or not -1 <= coeff_z <= 1:
                self.get_logger().info('parameter coefficient too large')
                return

            point.velocity = Vector3(x=coeff_x*velocity, y=coeff_y*velocity, z=coeff_z*velocity)

            coeff_x *= coeff_x
            coeff_y *= coeff_y
            coeff_z *= coeff_z

            point.position = Point(x=coeff_x*0.5, y=coeff_y*0.5, z=coeff_z*0.5)
        
        self.local_point_publisher.publish(point)
        # self.get_logger().info(f'{point} {self.panel_pos} {self.panel_yaw}')
