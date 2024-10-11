# Smart Irrigation System

This project implements a Smart Irrigation system that monitors soil moisture and automates watering based on moisture levels, using the ESP32 microcontroller and ThingSpeak for data logging and visualization.

## **IoT Design Methodology**

### **Step 1: Purpose & Requirements Specification**
- **Purpose**: To automate irrigation based on soil moisture levels, ensuring optimal watering and water conservation.
- **Requirements**:
  - Use a soil moisture sensor to measure moisture levels.
  - Control a water pump based on moisture readings.
  - Send data to ThingSpeak for monitoring and visualization.

### **Step 2: Process Specification**
- Continuously monitor soil moisture using the sensor.
- Activate the water pump if moisture levels fall below a certain threshold.
- Log moisture data to ThingSpeak for remote monitoring.

### **Step 3: Domain Model Specification**
- **Actors**:
  - **User**: Wants to manage and monitor irrigation automatically.
  - **System**: Monitors soil moisture and controls irrigation.
- **Entities**:
  - **Soil Moisture Sensor**: Measures the moisture level in the soil.
  - **Water Pump**: Activates to irrigate when soil moisture is low.
  - **ThingSpeak**: Logs and visualizes moisture data.

### **Step 4: Information Model Specification**
- **Data**:
  - Soil Moisture Level: Integer (percentage).
  - Timestamp of data collection.

### **Step 5: Service Specifications**
- **Moisture Monitoring Service**: Continuously checks the moisture level.
- **Irrigation Control Service**: Activates the water pump based on moisture readings.
- **Data Logging Service**: Sends moisture data to ThingSpeak.

### **Step 6: IoT Level Specification**
- **IoT Level**: Level 2 (Sensing and Actuation).
- Sensors provide input to the system, which triggers the water pump as needed.

### **Step 7: Functional View Specification**
- **Functions**:
  - Read moisture levels from the soil moisture sensor.
  - Control the water pump based on moisture levels.
  - Send data to ThingSpeak for monitoring.

### **Step 8: Operational View Specification**
- **Operation**:
  - The ESP32 reads soil moisture levels at defined intervals.
  - If moisture levels are low, the system activates the water pump.
  - Moisture data is logged to ThingSpeak for visualization.

### **Step 9: Device & Component Integration**
- **Components**:
  - ESP32 microcontroller.
  - Soil moisture sensor (e.g., capacitive moisture sensor).
  - Relay module to control the water pump.
  - Wi-Fi module (ESP32 built-in) for connectivity.
- **Integration**: All components are connected to the ESP32 using GPIO pins.

### **Step 10: Application Development**
- **ThingSpeak**: Used for data storage and visualization.
- **User Interface**: ThingSpeak provides built-in visualizations for monitoring moisture levels.

## **Installation Instructions**

### **Hardware Setup**
1. Connect the soil moisture sensor to the ESP32:
   - VCC to 3.3V
   - GND to GND
   - Analog output (A0) to any GPIO pin (e.g., GPIO 34)

2. Connect the relay module to control the water pump:
   - VCC to 5V (or appropriate voltage)
   - GND to GND
   - IN to any GPIO pin (e.g., GPIO 26)

### **Software Setup**
1. **Install the Arduino IDE**: Ensure you have the latest version.
2. **Install ESP32 Board**: Follow the [ESP32 board installation guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
3. **Install Required Libraries**: No additional libraries are required for this project.
