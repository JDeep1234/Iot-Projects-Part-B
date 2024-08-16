import os 
import firebase_admin
from firebase_admin import db
from gpiozero  import InputDevice
from time import sleep


credObj = firebase_admin.credentials.Certificate('./key.json')
defaultApp = firebase_admin.initialize_app(credObj, {
        'databaseURL':"https://esp32-bms-a0e26-default-rtdb.firebaseio.com/"
        })
ref = db.reference("/")
# data = ref.get() # Gets full firebase

parkingSpot1 = InputDevice(5)
parkingSpot2 = InputDevice(6)

occupiedSpots = {}
prevOccupiedSpots = {}


def updateParkingSpots():
    isOccupied = {}

    isOccupied["spot1"] = parkingSpot1.is_active
    isOccupied["spot2"] = parkingSpot2.is_active
    
    return isOccupied


def writeToFirebase(occupiedSpots):
    ref.update(occupiedSpots)

while True:
    prevOccupiedSpots = occupiedSpots
    occupiedSpots = updateParkingSpots()
    if(occupiedSpots != prevOccupiedSpots):
        writeToFirebase(occupiedSpots)
        print("Parking Spots have Changed " + str(occupiedSpots))
    sleep(1)