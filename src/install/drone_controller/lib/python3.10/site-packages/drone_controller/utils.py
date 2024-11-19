import sys
import os
import math

from geopy.distance import geodesic

from drone_controller.config import *
from drone_controller.constant import *


def calculate_yaw(latitude1, longitude1, latitude2, longitude2):
    """
    Calculate the heading angle (yaw) between two waypoints.
    """
    lat1, lon1 = math.radians(latitude1), math.radians(longitude1)
    lat2, lon2 = math.radians(latitude2), math.radians(longitude2)
    
    delta_lon = lon2 - lon1
    x = math.sin(delta_lon) * math.cos(lat2)
    y = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * math.cos(lat2) * math.cos(delta_lon)

    target_yaw = math.atan2(x, y)
    target_yaw = (target_yaw + math.pi) % (2 * math.pi) - math.pi
    
    yaw = math.degrees(target_yaw)

    if yaw < 0:
        yaw = 360 + yaw
    
    return yaw

def calculate_rotation_speed(angle_diff, min_speed=0.1, max_speed=0.5, k_p=0.008):
    rotation_speed = k_p * abs(angle_diff)
    
    rotation_speed = max(min(rotation_speed, max_speed), min_speed)
    rotation_speed *= -1 if angle_diff >= 0 else 1
    
    return rotation_speed

def calculate_body_speed(pos_diff, min_speed=0.1, max_speed=1.0, k_p=0.005):
    move_speed = k_p * abs(pos_diff)
    
    move_speed = max(min(move_speed, max_speed), min_speed)
    move_speed *= 1 if pos_diff >= 0 else -1
    
    return move_speed

def is_valid_latitude(lat) -> bool:
    if not isinstance(lat, float):
        return False
    return MIN_LATITUDE <= lat <= MAX_LATITUDE

def is_valid_longitude(lon) -> bool:
    if not isinstance(lon, float):
        return False
    return MIN_LONGITUDE <= lon <= MAX_LONGITUDE

def is_valid_altitude(alt) -> bool:
    if not isinstance(alt, (float, int)):
        return False
    return MIN_ALTITUDE <= alt <= MAX_ALTITUDE

def is_valid_velocity(vel) -> bool:
    if not isinstance(vel, (float, int)):
        return False
    return MIN_VELOCITY <= vel <= MAX_VELOCITY

def is_valid_type(type) -> bool:
    if not isinstance(type, int):
        return False
    return type == TYPE_START or type == TYPE_NAVIGATION or type == TYPE_LAND

def is_valid_mission(mission) -> bool:
    if not isinstance(mission, int):
        return False
    return mission == MISSION_NONE or mission == MISSION_LOCAL_CLEAN or mission == MISSION_GLOBAL_CLEAN

def is_valid_distance(waypoint1, waypoint2) -> bool:
    wp1 = (waypoint1.latitude, waypoint1.longitude)
    wp2 = (waypoint2.latitude, waypoint2.longitude)

    distance = geodesic(wp1, wp2).meters

    if distance > MAX_DISTANCE:
        return False
    
    return True