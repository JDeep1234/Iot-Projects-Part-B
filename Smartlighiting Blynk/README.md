# Smart Lighting System

This project implements a Smart Lighting system that dynamically adjusts lighting based on environmental conditions and user activity.

## **IoT Design Methodology**

### **Step 1: Purpose & Requirements Specification**
- **Purpose**: Automatically control lighting in a smart home based on occupancy and ambient light.
- **Requirements**:
  - Use motion sensors to detect occupancy.
  - Adjust lighting intensity based on ambient light sensors.
  - Remote control via a mobile app or web interface.

### **Step 2: Process Specification**
- Monitor ambient light with LDR sensors.
- Control lighting intensity through connected dimmable LEDs.
- Provide a user interface for manual control and override via an app.

### **Step 3: Domain Model Specification**
- **Actors**:
  - **User**: Person who manually controls the lights or sets automatic modes.
  - **System**: Smart lighting system consisting of sensors and lighting devices.
- **Entities**:
  - **Light**: Dimmable LED controlled by the system.
  - **Sensors**: PIR and LDR for occupancy and ambient light detection.

### **Step 4: Information Model Specification**
- **Data**: 
  - Occupancy status: Boolean (True/False).
  - Ambient light level: Integer (lux value).
  - Light intensity: Integer (0-100%).

### **Step 5: Service Specifications**
- **Ambient Light Monitoring Service**: Continuously monitor light levels and adjust LED intensity.
- **Manual Control Service**: Allow manual override via a mobile/web interface.

### **Step 6: IoT Level Specification**
- **IoT Level**: Level 2 (Sensing and Actuation).
- Sensors provide input, and the system controls output (LEDs).

### **Step 7: Functional View Specification**
- **Functions**:
  - Read sensor values.
  - Adjust LED brightness based on ambient light.
  - Trigger on/off based on motion detection.

### **Step 8: Operational View Specification**
- **Operation**:
  - When motion is detected, the light turns on.
  - If ambient light is sufficient, the light dims or turns off.
  - Manual control allows users to override these settings.

### **Step 9: Device & Component Integration**
- **Components**:
  - LDR sensor.
  - Dimmable LED.
  - Esp 32
- **Integration**: All components are integrated through GPIO pins, using Wi-Fi for remote access.

### **Step 10: Application Development**
- **Mobile App**: A simple mobile app built using Blynk to allow manual control and monitor sensor data.

  # Setting Up Datastreams in Blynk for ESP32

## 1. Create a Blynk Account and Project
- Go to the **[Blynk IoT platform](https://blynk.io/)**.
- Create an account or log in.
- Create a new project and name it.
- Select **ESP32** as your hardware.
- Copy the **Authentication Token** generated for the project (you will need this in your code).

## 2. Create Datastreams
- In the **Blynk Console**, select your project.
- Click on **"Datastreams"** in the sidebar or while editing a device.
- Select **"New Datastream"**.

## 3. Select Datastream Type
- Choose the type of datastream based on your needs:
  - **Virtual Pin**: Used for communication between hardware and the Blynk platform via virtual pins.
  - **Digital Pin**: Direct control of hardware digital pins.
  - **Analog Pin**: Direct control of hardware analog pins.
  
  For this project, select **Virtual Pin** for the LDR and LED.

## 4. Configure Datastream for the LDR (Sensor Input)
- **Type**: Virtual Pin
- **Pin**: V5 (to match your code)
- **Label**: LDR Sensor
- **Data Type**: Integer
- **Min/Max Values**: 0 to 4095 (typical range for ESP32 ADC)
- **Units**: (optional) lux or raw value

## 5. Configure Datastream for the LED (Output Control)
- **Type**: Virtual Pin
- **Pin**: V0 (to match your code)
- **Label**: LED Control
- **Data Type**: Integer
- **Min/Max Values**: 0 (LED OFF) and 1 (LED ON)
- **Widget**: Button or Switch (for controlling the LED)

## 6. Configure Data Visualization in the Dashboard
- Go to your project’s **Dashboard** in the Blynk Console.
- Add a **Chart** or **Gauge** widget to visualize LDR sensor readings:
  - **Link**: Virtual Pin V5
  - **Data Range**: 0–4095
- Add a **Button** or **Switch** widget to control the LED:
  - **Link**: Virtual Pin V0

## 7. Deploy and Run the Project
- Make sure your ESP32 code includes the correct **BLYNK_AUTH_TOKEN**, WiFi credentials, and virtual pins.
- Upload the code to your ESP32.
- Once the ESP32 is running, the LDR readings will be sent to Blynk, and you can control the LED from the dashboard.

---

## Summary of Datastreams:
### LDR Datastream:
- **Type**: Virtual Pin
- **Pin**: V5
- **Data Type**: Integer
- **Min/Max**: 0–4095
- **Widget**: Chart/Gauge (for visualizing LDR values)

### LED Control Datastream:
- **Type**: Virtual Pin
- **Pin**: V0
- **Data Type**: Integer (0 = OFF, 1 = ON)
- **Widget**: Button/Switch (for controlling the LED)

  
