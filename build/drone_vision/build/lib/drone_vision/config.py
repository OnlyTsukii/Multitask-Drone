
IMAGE_WIDTH         = 1024
IMAGE_HEIGHT        = 768
FRAME_PER_SECOND    = 30
CONF_THRESHOLD      = 0.6

RKNN_MODEL                  = '/home/orangepi/Multitask-Drone/src/drone_vision/weights/best.rknn'
YOLO_MODEL                  = '/home/orangepi/Multitask-Drone/src/drone_vision/weights/new_panel.pt'
CLEAN_RAW_IMAGE_PATH        = '/home/orangepi/Multitask-Drone/src/drone_vision/images/task_clean/raw'
CLEAN_LABELED_IMAGE_PATH    = '/home/orangepi/Multitask-Drone/src/drone_vision/images/task_clean/labeled'
CAPTURE_IMAGE_PATH          = '/home/orangepi/Multitask-Drone/src/drone_vision/images/task_capture'

OBJ_THRESH = 0.25
NMS_THRESH = 0.45

PLATFORM = 'rk3588'