import cv2
import time
import rclpy
import threading
import sys
import os
import math

from ultralytics import YOLO
from rclpy.node import Node
from copy import deepcopy
from drone_interfaces.msg import PanelBox, Yaw
from drone_interfaces.srv import YoloRequest

from drone_vision.utils import calc_angle_by_canny

IMAGE_WIDTH         = 1920
IMAGE_HEIGHT        = 1080
FRAME_PER_SECOND    = 30
CONF_THRESHOLD      = 0.6
MODEL_PATH          = '/home/x650/Multitask-Drone/src/drone_vision/weights/new_panel.pt'
IMAGE_PATH          = '/home/x650/Multitask-Drone/src/drone_vision/images/'


class ObjectDetector(Node):
    def __init__(self):
        super().__init__('object_detector')

        self.yolo_srv = self.create_service(YoloRequest, '/drone/yolo_request', self.handle_yolo_request)

        self.panel_publisher = self.create_publisher(PanelBox, '/drone/panel_box', 10)
        self.panel_yaw_publisher = self.create_publisher(Yaw, '/drone/panel_yaw', 10)

        self.detect_model = YOLO(MODEL_PATH)

        self.counter = 0
        self.detect_counter = 0

        if not self.init_camera():
            return
        
        self.frame = None
        self.mutex = threading.Lock()

        self.yolo_enabled = False
        
        self.create_timer(0.09, self.detect)

    def handle_yolo_request(self, request, response):
        self.yolo_enabled = request.start
        response.success = True
        return response

    def init_camera(self) -> bool:
        self.cap = cv2.VideoCapture(0)

        if not self.cap.isOpened():
            return False

        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, IMAGE_WIDTH)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, IMAGE_HEIGHT)
        self.cap.set(cv2.CAP_PROP_FPS, 30)

        return True 
    
    def capture(self):
        while rclpy.ok():
            ret, frame = self.cap.read()
            if not ret:
                continue

            self.frame = frame
    
    def detect(self):
        if not self.yolo_enabled:
            return
        
        if self.counter % 30 == 0:
            cv2.imwrite(IMAGE_PATH+'img-'+str(time.time())+'.jpg', self.frame)
            self.counter = 0

        self.counter += 1
        
        self.mutex.acquire()
        results = self.detect_model(self.frame, True)
        self.mutex.release()

        has_result = False

        for result in results:
            if len(result.boxes.conf) == 0:
                continue
            conf = result.boxes.conf[0]
            if conf < CONF_THRESHOLD:
                continue

            if self.detect_counter % 10 == 0:
                cv2.imwrite(IMAGE_PATH+'yolo-'+str(time.time())+'.jpg', result.plot())
                self.detect_counter = 0

            self.detect_counter += 1
        
            x, y, w, h = result.boxes.xywh[0]
            center_x = IMAGE_WIDTH/2 - x
            center_y = IMAGE_HEIGHT/2 - y

            has_result = True

        panel_box = PanelBox()
        if has_result:
            panel_box.x = float(center_x)
            panel_box.y = float(center_y)
            panel_box.w = float(w)
            panel_box.h = float(h)
            self.get_logger().info(f'{panel_box, panel_box.y - panel_box.h / 2, panel_box.h / 2 + panel_box.y}')

        self.panel_publisher.publish(panel_box)

        yaw = calc_angle_by_canny(self.frame)
        if not math.isnan(yaw):
            panel_yaw = Yaw()
            panel_yaw.yaw = yaw
            self.panel_yaw_publisher.publish(panel_yaw)
            self.get_logger().info(f'{panel_yaw}')


def main(args=None):
    rclpy.init(args=args)

    yolo_detector = ObjectDetector()

    capture = threading.Thread(target=yolo_detector.capture)
    capture.start()

    rclpy.spin(yolo_detector)

    yolo_detector.cap.release()

    rclpy.shutdown()

if __name__ == "__main__":
    main()
