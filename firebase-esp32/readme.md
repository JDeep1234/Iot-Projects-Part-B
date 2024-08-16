
# Setup Guide for ESP-32 and Firebase

## Step 1: Install Firebase library for ESP-32

1. Open the library manager.
2. Search for `Firebase ESP32 Client` by `Mobizt` and **install the version `4.3.4`**

## Step 2: Install ESP32 for Arduino

1. Open the boards manager.
2. Search for `esp32` by `Espressif` and **install the version `1.0.6`**

## Step 3: Edit credentials for Firebase

1. Go to the [Firebase Console](https://console.firebase.google.com/).
2. Select your project.
3. Navigate to `Project settings` > `Serivce Accounts` > `Database Secrets`.
4. Click on "Show" and copy the `API KEY`.
5. This will be the `FIREBASE_AUTH` in Arduino code
6. Copy the database URL from the Realtime Database tab. It looks similar to `https://esp32-bms-a0e26-default-rtdb.firebaseio.com/`
7. This will be the `FIREBASE_HOST` in Arduino code

## Step 3: Edit credentials for WiFi Hotspot

1. Edit `WIFI_SSID` and `WIFI_PASSWORD` accordingly


## Step 4: Set Firebase Bucket
1. Set the `FIREBASE_BUCKET` to something unique


# Troubleshooting
- In case you come across an error that says `Architecture Incompatible` or anything related to `SD`, then delete the `SD` folder from the path that contains `Arduino` in its path and not the path that with `ESP32`