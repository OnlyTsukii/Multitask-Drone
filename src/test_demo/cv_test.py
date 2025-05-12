import cv2
import time
import os

home_dir = os.environ.get('HOME')

CAPTURE_IMAGE_PATH          = home_dir + '/Multitask-Drone/src/drone_vision/images/task_capture/'

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("can't open the camera")
    exit()

cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 3840)  
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 2880)  
cap.set(cv2.CAP_PROP_FPS, 20)  

print(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
print(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
print(cap.get(cv2.CAP_PROP_FPS))

start_time = time.time()

while True:
    ret, frame = cap.read()

    if not ret:
        print("can't read the frame")
        break

    if time.time() - start_time >= 1.0:
        res = cv2.imwrite(CAPTURE_IMAGE_PATH+str(time.time())+'.jpg', frame)
        start_time = time.time()

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()