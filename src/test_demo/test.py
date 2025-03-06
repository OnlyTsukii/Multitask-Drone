from ultralytics import YOLO

# # Load a YOLO11n PyTorch model
# model = YOLO("/home/jetson/Multitask-Drone/src/drone_vision/weights/new_panel.pt")

# # Export the model to TensorRT
# model.export(format="engine")  # creates 'yolo11n.engine'

# Load the exported TensorRT model
trt_model = YOLO("/home/jetson/Multitask-Drone/src/drone_vision/weights/new_panel.engine" ,task='detect')

# Run inference
results = trt_model("/home/jetson/Multitask-Drone/src/drone_vision/images")

for i, result in enumerate(results):
    result.save(filename=f"/home/jetson/Multitask-Drone/src/drone_vision/results/result_{i}.jpg")
