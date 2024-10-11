# Intrusion Detection System (IDS)

This project implements an Intrusion Detection System using motion sensors and the ESP32 microcontroller, with real-time notifications sent to users via the Blynk app.

## **IoT Design Methodology**

### **Step 1: Purpose & Requirements Specification**
- **Purpose**: To detect unauthorized intrusions and notify users in real-time.
- **Requirements**:
  - Use PIR motion sensors to detect movement.
  - Use the ESP32 to process sensor data and send notifications.
  - Integrate with the Blynk app for real-time alerts.

### **Step 2: Process Specification**
- Continuously monitor the area for motion using PIR sensors.
- Trigger notifications to users through the Blynk app upon detecting movement.
- Allow users to view real-time status and history of detections.

### **Step 3: Domain Model Specification**
- **Actors**:
  - **User**: Receives notifications of potential intrusions.
  - **System**: Monitors motion and manages notifications.
- **Entities**:
  - **PIR Sensor**: Detects movement.
  - **Blynk App**: Interface for users to receive notifications and view system status.

### **Step 4: Information Model Specification**
- **Data**:
  - Motion detected: Boolean (true/false).
  - Timestamp of detection.
  - User notifications status.

### **Step 5: Service Specifications**
- **Motion Detection Service**: Monitors PIR sensors for movement.
- **Notification Service**: Sends alerts to the Blynk app when motion is detected.
- **User Interface Service**: Allows users to interact with the system via the Blynk app.

### **Step 6: IoT Level Specification**
- **IoT Level**: Level 2 (Sensing and Actuation).
- Sensors provide input, and the system triggers notifications.

### **Step 7: Functional View Specification**
- **Functions**:
  - Monitor PIR sensors for motion detection.
  - Send notifications to the Blynk app.
  - Provide a user interface to control settings.

### **Step 8: Operational View Specification**
- **Operation**:
  - The ESP32 continuously checks the PIR sensor for movement.
  - If motion is detected, a notification is sent to the user via the Blynk app.

### **Step 9: Device & Component Integration**
- **Components**:
  - ESP32 microcontroller.
  - PIR motion sensor.
  - Blynk app for mobile notifications.
  - Wi-Fi module (ESP32 built-in) for connectivity.
- **Integration**: All components are connected to the ESP32 using GPIO pins.

### **Step 10: Application Development**
- **Blynk App**: A mobile application to receive notifications and view the system status.
- **Backend**: Manages communication between the ESP32 and the Blynk app.

## **Installation Instructions**

### **Hardware Setup**
1. Connect the PIR motion sensor to the ESP32:
   - VCC to 3.3V
   - GND to GND
   - OUT to any GPIO pin (e.g., GPIO 23)

### **Software Setup**
1. **Install the Arduino IDE**: Ensure you have the latest version.
2. **Install ESP32 Board**: Follow the [ESP32 board installation guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
3. **Install Blynk Library**: Install the Blynk library from the Library Manager in Arduino IDE.
