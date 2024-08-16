import cv2
import os
from picamera2 import Picamera2

picam2 = Picamera2()
camera_config = picam2.create_still_configuration(main={"size": (640, 480)})
picam2.configure(camera_config)

picam2.start()

face_detector = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')
face_id = input('\n enter user id end press <return> ==>  ')
print("\n [INFO] Initializing face capture. Look the camera and wait ...")
count = 0
while(True):
    img = picam2.capture_array()
    #img = cv2.flip(img, -1) # flip video image vertically
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    cv2.imshow('camera', img)
    faces = face_detector.detectMultiScale(gray, 1.3, 5)
    for (x,y,w,h) in faces:
        cv2.rectangle(img, (x,y), (x+w,y+h), (255,0,0), 2)     
        count += 1
        print (count)
        # Save the captured image into the datasets folder
        cv2.imwrite("./dataset/User." + str(face_id) + '.' + str(count) + ".jpg", gray[y:y+h,x:x+w])
    k = cv2.waitKey(100) & 0xff # Press 'ESC' for exiting video
    if k == 27:
        break
    elif count >= 30: # Take 30 face sample and stop video
         break
# Do a bit of cleanup
print("\n [INFO] Exiting Program and cleanup stuff")
cv2.destroyAllWindows()