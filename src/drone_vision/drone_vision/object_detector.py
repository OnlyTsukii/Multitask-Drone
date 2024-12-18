import cv2
import time
import rclpy
import threading
import sys
import os
import math

from rclpy.node import Node
from copy import deepcopy
from drone_interfaces.msg import PanelBox, Yaw
from drone_interfaces.srv import YoloRequest

from drone_vision.config import *
from drone_vision.utils.bound_detector import calc_angle_by_canny
from drone_vision.utils.rknn_helper import RKNN_Helper


class ObjectDetector(Node):
    def __init__(self):
        super().__init__('object_detector')

        self.yolo_srv = self.create_service(YoloRequest, '/drone/yolo_request', self.handle_yolo_request)
        self.capture_srv = self.create_service(YoloRequest, '/drone/capture_request', self.handle_capture_request)

        self.panel_publisher = self.create_publisher(PanelBox, '/drone/panel_box', 10)
        self.panel_yaw_publisher = self.create_publisher(Yaw, '/drone/panel_yaw', 10)

        self.detect_model = RKNN_Helper(RKNN_MODEL, PLATFORM)

        self.counter = 0
        self.detect_counter = 0

        if not self.init_camera():
            return
        
        self.frame = None
        self.mutex = threading.Lock()

        self.yolo_enabled = False
        self.has_frame = False
        
        self.create_timer(0.1, self.detect)

    def handle_yolo_request(self, request, response):
        self.yolo_enabled = request.start
        response.success = True
        return response
    
    def handle_capture_request(self, request, response):
        res = cv2.imwrite(CAPTURE_IMAGE_PATH+str(time.time())+'.jpg', self.frame)
        response.success = res
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
            self.has_frame = True

    def save_img(self, folder, img) -> str:
        if not os.path.exists(folder):
            os.makedirs(folder, exist_ok=True)
        image_name = str(time.time()) + '.jpg'
        cv2.imwrite(folder+'/'+image_name, img)
        return image_name
    
    def detect(self):
        # if not self.yolo_enabled:
        #     return
        
        if not self.has_frame:
            return

        if self.counter % 5 == 0:
            self.save_img(CLEAN_RAW_IMAGE_PATH, self.frame)
            self.counter = 0

        self.counter += 1
        
        self.mutex.acquire()
        boxes, scores, img = self.detect_model.detect(self.frame)
        self.mutex.release()

        has_result = False

        if boxes is not None:
            # if self.detect_counter % 5 == 0:
            #     self.save_img(CLEAN_LABELED_IMAGE_PATH, img)
            #     self.detect_counter = 0

            # self.detect_counter += 1

            for box, score in zip(boxes, scores):
                if score < CONF_THRESHOLD:
                    continue
                
                left, top, right, bottom = [int(_b) for _b in box]
                image_name = self.save_img(CLEAN_LABELED_IMAGE_PATH, img)
                self.get_logger().info(f'{image_name}: {left, top, right, bottom}')
                center_x = IMAGE_WIDTH/2 - (left+right)/2
                center_y = IMAGE_HEIGHT/2 - (top+bottom)/2
                width = right - left
                height = bottom - top

                has_result = True

        panel_box = PanelBox()
        if has_result:
            panel_box.x = float(center_x)
            panel_box.y = float(center_y)
            panel_box.w = float(width)
            panel_box.h = float(height)
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
    yolo_detector.detect_model.release()

    rclpy.shutdown()

if __name__ == "__main__":
    main()
