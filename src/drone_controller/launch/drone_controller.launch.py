import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='drone_vision',
            executable='object_detector',
        ),
        Node(
            package='drone_controller',
            executable='waypoint_handler',
        ),
        Node(
            package='drone_controller',
            executable='task_executor',
        ),
        Node(
            package='drone_controller',
            executable='drone_controller',
        ),
    ])
