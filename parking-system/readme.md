
# Parking Management System

### Installation

First, navigate into the project directory:

```bash
cd parking-system
```

Setup a virtual environment
```bash
python -m venv venv --system-site-packages
. venv/bin/activate
```
Install requirements

```bash
pip install -r requirements.txt
```
## Download `key.json` from Firebase

1. Go to the [Firebase Console](https://console.firebase.google.com/).
2. Select your project.
3. Navigate to `Project settings` > `Firebase Admin SDK`.
4. Click on "Generate new private key" and save the file as `key.json` to your project directory.

## Run the application

Finally, run the application:

```bash
python app.py
```

## Pinout for Raspberry Pi 4 GPIOs  
  
![Pinout for Raspberry Pi 4](pin_layout.svg "Pinout for Raspberry Pi 4")  

# Smart Parking System

This project implements a Smart Parking system that utilizes IR sensors to detect the availability of parking slots. The system is managed using a Raspberry Pi and can be monitored through the MITM app, allowing users to check the status of parking slots in real-time.

## **IoT Design Methodology**

### **Step 1: Purpose & Requirements Specification**
- **Purpose**: To provide an efficient way to monitor parking space availability in real-time, reducing the time spent searching for parking.
- **Requirements**:
  - Use IR sensors to detect the presence or absence of vehicles in parking slots.
  - Use Raspberry Pi for data processing and communication.
  - Develop a user-friendly application using MITM for real-time parking status monitoring.

### **Step 2: Process Specification**
- Continuously monitor each parking slot using IR sensors.
- Send availability status to the MITM app.
- Allow users to check the availability of parking slots remotely.

### **Step 3: Domain Model Specification**
- **Actors**:
  - **User**: Wants to find available parking slots quickly.
  - **System**: Monitors parking slots and provides status updates.
- **Entities**:
  - **IR Sensors**: Detects vehicle presence in parking slots.
  - **Raspberry Pi**: Processes data from sensors and communicates with the app.
  - **MITM App**: Displays real-time parking availability.

### **Step 4: Information Model Specification**
- **Data**:
  - Slot Availability: Boolean (true/false).
  - Slot ID: Identifier for each parking slot.
  - Timestamp: When the status was last updated.

### **Step 5: Service Specifications**
- **Parking Monitoring Service**: Monitors the state of parking slots.
- **Data Communication Service**: Sends availability data to the MITM app.
- **User Interface Service**: Provides users access to parking slot statuses.

### **Step 6: IoT Level Specification**
- **IoT Level**: Level 2 (Sensing and Actuation).
- The system uses sensors to gather data and communicates the status to the app.

### **Step 7: Functional View Specification**
- **Functions**:
  - Read data from IR sensors.
  - Update parking slot availability status.
  - Send updates to the MITM app.

### **Step 8: Operational View Specification**
- **Operation**:
  - The Raspberry Pi reads the state of IR sensors at regular intervals.
  - If a vehicle is detected, the corresponding slot's status is updated to unavailable.
  - Availability data is sent to the MITM app for user access.

### **Step 9: Device & Component Integration**
- **Components**:
  - Raspberry Pi (Model 3 or later).
  - IR sensors (e.g., HC-SR501).
  - Jumper wires for connections.
  - Power supply for Raspberry Pi.
- **Integration**: All components are connected to the GPIO pins on the Raspberry Pi.

### **Step 10: Application Development**
- **MITM App**: A user-friendly application for monitoring parking slot availability in real-time.

## **Installation Instructions**

### **Hardware Setup**
1. Connect the IR sensors to the Raspberry Pi:
   - VCC to 5V (or appropriate voltage).
   - GND to GND.
   - Output pin to any GPIO pin (e.g., GPIO 17).

2. Repeat the connections for each additional IR sensor, ensuring each is connected to a different GPIO pin.

### **Software Setup**
1. **Install Raspbian OS**: Ensure you have the latest version of Raspbian installed on your Raspberry Pi.
2. **Install Required Libraries**: Use the following commands to install necessary libraries.

   ```bash
   sudo apt update
   sudo apt install python3 python3-flask
