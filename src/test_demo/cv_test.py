import cv2
import time

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


while True:
    ret, frame = cap.read()

    if not ret:
        print("can't read the frame")
        break

    # print(time.time())

    cv2.imshow("test", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()