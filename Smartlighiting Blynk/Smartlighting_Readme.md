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
  
