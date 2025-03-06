#!/bin/bash

source /opt/ros/humble/setup.bash

colcon build

source /home/jetson/Multitask-Drone/install/setup.bash

ros2 launch drone_controller drone_controller.launch.py