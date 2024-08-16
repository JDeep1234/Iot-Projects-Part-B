import cv2
import numpy as np
import os 
from picamera2 import Picamera2
import firebase_admin
from firebase_admin import db


cred_obj = firebase_admin.credentials.Certificate('./key.json')
default_app = firebase_admin.initialize_app(cred_obj, {
        'databaseURL':"https://esp32-bms-a0e26-default-rtdb.firebaseio.com/"
        })
ref = db.reference("/")
# data = ref.get() # Gets full firebase

picam2 = Picamera2()
camera_config = picam2.create_still_configuration(main={"size": (640, 480)})
picam2.configure(camera_config)

picam2.start()
recognizer = cv2.face.LBPHFaceRecognizer_create()
recognizer.read('./trainer/trainer.yml')
cascadePath = "./haarcascade_frontalface_default.xml"
faceCascade = cv2.CascadeClassifier(cascadePath)
font = cv2.FONT_HERSHEY_SIMPLEX
id = 0
names = ['unknown', 'Aswarth', 'person2'] 
detectedNames = []

# Define min window size to be recognized as a face
minW = 0.1*640
minH = 0.1*480

def detectFaces(img):
    global detectedNames
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
    faces = faceCascade.detectMultiScale( 
        gray,
        scaleFactor = 1.2,
        minNeighbors = 5,
        minSize = (int(minW), int(minH)),
       )
    detectedNames = []
    for(x,y,w,h) in faces:
        cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)
        id, confidence = recognizer.predict(gray[y:y+h,x:x+w])
        if (confidence < 100):
            id = names[id]
            confidence = "  {0}%".format(round(100 - confidence))
        else:
            id = names[0]
            confidence = "  {0}%".format(round(100 - confidence))
        detectedNames.append(id)
        cv2.putText(img, str(id), (x+5,y-5), font, 1, (255,255,255), 2)
        cv2.putText(img, str(confidence), (x+5,y+h-5), font, 1, (255,255,0), 1)
    
    writeToFirebase(names)  
    return img

def gen_frames():
    while(True):
        img = picam2.capture_array()
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        img = detectFaces(img)
        ret, buffer = cv2.imencode('.jpg', img)
        img = buffer.tobytes()
        yield(b'--frame\r\n Content-Type: image/jpeg\r\n\r\n' + img + b'\r\n')


def writeToFirebase(names):
    ref.update({"names": detectedNames})