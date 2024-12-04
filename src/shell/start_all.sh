#!/bin/bash

# SCRIPT_DIR="/home/x650/UAV/Shell"

# SCRIPTS=(
#     "start_camera.sh"
#     "start_mavros.sh"
#     "start_ros2.sh"
# )

# for SCRIPT in $SCRIPTS; do
#     SCRIPT_PATH=$SCRIPT_DIR/$SCRIPT
#     if [[ -x $SCRIPT_PATH ]]; then
#         echo "Starting $SCRIPT_PATH..."
#         $SCRIPT_PATH &
#         /bin/sleep 3
#     else
#         echo "Cannot execute $SCRIPT_PATH: not found or not executable"
#     fi
# done

# wait

# echo "All scripts have been started."

# /bin/sleep 3

# export TERM=xterm-256color
# /home/x650/UAV/Camera/Demo &


/bin/sleep 2

python3 /home/x650/Multitask-Drone/src/scripts/http_server.py &

source /opt/ros/humble/setup.bash
ros2 launch mavros px4.launch &

/bin/sleep 2

source /home/x650/Multitask-Drone/src/install/setup.bash
ros2 launch drone_controller drone_controller.launch.py