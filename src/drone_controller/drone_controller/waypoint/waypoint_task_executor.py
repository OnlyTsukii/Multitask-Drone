import rclpy
import time
import math

from typing import Optional
from rclpy.node import Node
from geometry_msgs.msg import Vector3, Point
from mavros_msgs.msg import PositionTarget
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import Header
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from drone_interfaces.msg import PanelBox, Yaw

from drone_controller.utils import *
from drone_controller.constant import *


class WaypointTaskExecutor(Node):

    def __init__(self):
        super().__init__('waypoint_task_executor')
        
        self.gps_fix = None
        self.panel_yaw = float('nan')
        self.max_retries = 0
        self.panel_found = 0
        self.panel_loss = 0

        self.panel_detected = False
        self.panel_pos = None
        self.task_finished = False
        self.task_pending = False
        self.task_point_reached = False
        self.panel_center_reached = False
        self.task_ready = False

        self.local_point_publisher = self.create_publisher(PositionTarget, '/mavros/setpoint_raw/local', 10)

        qos_profile = QoSProfile(reliability=ReliabilityPolicy.BEST_EFFORT, history=HistoryPolicy.KEEP_LAST, depth=10)
        self.global_pos_sub = self.create_subscription(NavSatFix, '/mavros/global_position/global', self.global_pos_callback, qos_profile)
        self.panel_sub = self.create_subscription(PanelBox, '/drone/panel_box', self.panel_callback, 10)
        self.panel_yaw_sub = self.create_subscription(Yaw, '/drone/panel_yaw', self.panel_yaw_callback, 10)

    def global_pos_callback(self, msg):
        self.gps_fix = msg

    def panel_yaw_callback(self, msg):
        self.panel_yaw = msg.yaw

    def panel_callback(self, msg):
        if msg.x == 0 and msg.y == 0 and msg.w == 0 and msg.h == 0:
            if not self.panel_detected:
                self.panel_pos = None
            self.panel_loss += 1
            self.panel_found = 0
            if self.panel_loss == 20:
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

    def execute_clean_task(self):
        if not self.panel_detected:
            while self.gps_fix == None:
                rclpy.spin_once(self)
                self.body_move(BODY_HOLD)
                time.sleep(0.3)

            prev_altitude = self.gps_fix.altitude

            timestamp = time.time()
            while rclpy.ok():
                rclpy.spin_once(self)
                if time.time() - timestamp < 0.1:
                    continue
                if self.gps_fix.altitude - prev_altitude > 10.0:
                    self.panel_yaw = float('nan')
                    self.get_logger().info('panel not found, navigate to next waypoint')
                    return
                self.body_move(BODY_CLIMB)
                if self.panel_detected:
                    break
                timestamp = time.time()
            
        panel_center_reached = False
        task_point_reached = False
        
        timestamp = time.time()

        while rclpy.ok():
            rclpy.spin_once(self)
            if time.time() - timestamp < 0.3:
                continue

            if not self.panel_detected:
                return 
            
            panel_pos = self.panel_pos
            
            if task_point_reached:
                top_edge_pos_y = panel_pos.h / 2 + panel_pos.y
                if top_edge_pos_y > -50:
                    self.get_logger().info("executing task ...")
                    # TODO: CLEAN
                    self.body_move(BODY_FORWARD)
                else:
                    break
                    
                timestamp = time.time()
                continue
            
            if panel_center_reached:
                if not math.isnan(self.panel_yaw):
                    self.max_retries = 0
                    if self.panel_yaw > PANEL_YAW_THRES:
                        self.body_move(BODY_ROTATE_CLOCKWISE)
                    elif self.panel_yaw < -1 * PANEL_YAW_THRES:
                        self.body_move(BODY_ROTATE_COUNTERCW)
                    else:
                        bottom_edge_pos_y = panel_pos.y - panel_pos.h / 2
                        if bottom_edge_pos_y < 0:
                            self.body_move(BODY_BACKWARD)
                        elif bottom_edge_pos_y > 100:
                            self.body_move(BODY_FORWARD)
                        elif panel_pos.w < IMAGE_WIDTH/1.5 or panel_pos.h < IMAGE_HEIGHT/1.5:
                            self.body_move(BODY_DOWN)
                        else:
                            task_point_reached = True
                            self.get_logger().info("task point reached") 
                else:
                    self.body_move(BODY_HOLD)
                    self.max_retries += 1
                    if self.max_retries == 20:
                        self.max_retries = 0
                        self.get_logger().info('panel edge not found, navigate to next waypoint')
                        self.panel_yaw = float('nan')
                        return
                
                timestamp = time.time()
                continue

            if panel_pos.x > PANEL_POS_THRES_X:
                self.body_move(BODY_LEFT)
            elif panel_pos.x < -1 * PANEL_POS_THRES_X:
                self.body_move(BODY_RIGHT)
            elif panel_pos.y > PANEL_POS_THRES_Y:
                self.body_move(BODY_FORWARD)
            elif panel_pos.y < -1 * PANEL_POS_THRES_Y:
                self.body_move(BODY_BACKWARD)
            elif panel_pos.w < IMAGE_WIDTH/5 or panel_pos.h < IMAGE_HEIGHT/5:
                self.body_move(BODY_DOWN)
            else:
                panel_center_reached = True
                self.get_logger().info("panel center reached")

            timestamp = time.time()

        self.panel_yaw = float('nan')
        self.get_logger().info("task finished")
    
    def body_move(self, direction):
        point = PositionTarget()
        point.header = Header()
        point.header.stamp = self.get_clock().now().to_msg()   
        point.coordinate_frame = FRAME_BODY_NED

        point.type_mask = IGNORE_YAW_RATE | IGNORE_YAW | IGNORE_AFX | IGNORE_AFY | IGNORE_AFZ

        if direction == BODY_CLIMB:
            point.velocity = Vector3(x=0.0, y=0.0, z=0.5)
            point.position = Point(x=0.0, y=0.0, z=0.5)
        elif direction == BODY_DOWN:
            point.velocity = Vector3(x=0.0, y=0.0, z=-0.5)
            point.position = Point(x=0.0, y=0.0, z=0.5)
        elif direction == BODY_FORWARD:
            point.velocity = Vector3(x=0.3, y=0.0, z=0.0)
            point.position = Point(x=0.3, y=0.0, z=0.0)
        elif direction == BODY_BACKWARD:
            point.velocity = Vector3(x=-0.3, y=0.0, z=0.0)
            point.position = Point(x=0.3, y=0.0, z=0.0)
        elif direction == BODY_LEFT:
            point.velocity = Vector3(x=0.0, y=0.3, z=0.0)
            point.position = Point(x=0.0, y=0.3, z=0.0)
        elif direction == BODY_RIGHT:
            point.velocity = Vector3(x=0.0, y=-0.3, z=0.0)
            point.position = Point(x=0.0, y=0.3, z=0.0)
        elif direction == BODY_HOLD:
            point.velocity = Vector3(x=0.0, y=0.0, z=0.0)
            point.position = Point(x=0.0, y=0.0, z=0.0)
        else:
            point.type_mask = IGNORE_YAW | IGNORE_AFX | IGNORE_AFY | IGNORE_AFZ
            point.velocity = Vector3(x=0.0, y=0.0, z=0.0)
            point.position = Point(x=0.0, y=0.0, z=0.0)
            if direction == BODY_ROTATE_CLOCKWISE:
                point.yaw_rate = -1 * 0.2
            else:
                point.yaw_rate = 0.2
            
        self.local_point_publisher.publish(point)

# def main(args=None):
#     rclpy.init(args=args)

#     waypoint_task_executor = WaypointTaskExecutor()

#     rclpy.spin(waypoint_task_executor)

#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()
