import cv2
import numpy as np
import math


def calc_angle_by_canny(frame):
    gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    edges = cv2.Canny(gray_image, threshold1=700, threshold2=100)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        epsilon = 0.04 * cv2.arcLength(contour, True)
        approx = cv2.approxPolyDP(contour, epsilon, True)

        if len(approx) == 4 and cv2.contourArea(contour) > 100:
            point_list = []

            for point in approx:
                point_list.append([point[0][0], point[0][1]])

            l1 = (abs(point_list[2][0]-point_list[1][0]))**2 + (abs(point_list[2][1]-point_list[1][1])**2)
            l2 = (abs(point_list[2][0]-point_list[3][0]))**2 + (abs(point_list[2][1]-point_list[3][1])**2)

            if l1 > l2:
                longest_edge = [point_list[2], point_list[1]]
            else:
                longest_edge = [point_list[2], point_list[3]]
            
            dy = longest_edge[1][1] - longest_edge[0][1]
            dx = longest_edge[1][0] - longest_edge[0][0]

            angle_with_y_axis = 90 - abs(math.degrees(math.atan2(dy, dx)))

            return angle_with_y_axis
        
    return float('nan')
