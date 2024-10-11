# Forest Fire Detection System

This project implements a Forest Fire Detection system using temperature and smoke sensors connected to an ESP32 microcontroller. The system monitors environmental conditions and sends alerts through a Flask web application for real-time monitoring.

## **IoT Design Methodology**

### **Step 1: Purpose & Requirements Specification**
- **Purpose**: To detect forest fires by monitoring temperature and smoke levels and alerting users in real-time.
- **Requirements**:
  - Use temperature and smoke sensors to detect fire conditions.
  - Use the ESP32 for processing sensor data.
  - Develop a Flask web application to display sensor data and alerts.

### **Step 2: Process Specification**
- Continuously monitor temperature and smoke levels.
- Trigger alerts when fire conditions are detected.
- Provide a web interface for users to view current sensor data and alert statuses.

### **Step 3: Domain Model Specification**
- **Actors**:
  - **User**: Wants to monitor fire conditions in forested areas.
  - **System**: Monitors sensors and provides alerts.
- **Entities**:
  - **Temperature Sensor**: Measures ambient temperature.
  - **Smoke Sensor**: Detects smoke particles in the air.
  - **Flask Web Application**: Displays sensor readings and alerts.

### **Step 4: Information Model Specification**
- **Data**:
  - Temperature: Float (degrees Celsius).
  - Smoke Level: Integer (analog value).
  - Alert Status: Boolean (true/false).

### **Step 5: Service Specifications**
- **Temperature Monitoring Service**: Monitors temperature levels.
- **Smoke Detection Service**: Detects smoke levels.
- **Alert Service**: Sends alerts to the Flask application when conditions are met.
- **Web Interface Service**: Provides a web interface to display data.

### **Step 6: IoT Level Specification**
- **IoT Level**: Level 3 (Data Processing and Analysis).
- The system processes data from sensors to make decisions regarding fire alerts.

### **Step 7: Functional View Specification**
- **Functions**:
  - Read data from temperature and smoke sensors.
  - Send alerts to the Flask web application.
  - Display current sensor readings and alert status.

### **Step 8: Operational View Specification**
- **Operation**:
  - The ESP32 continuously reads data from sensors.
  - If the temperature exceeds a certain threshold or smoke is detected, the system triggers an alert.
  - Sensor data and alert status are sent to the Flask web application.

### **Step 9: Device & Component Integration**
- **Components**:
  - ESP32 microcontroller.
  - Temperature sensor (e.g., LM35 or DHT11).
  - Smoke sensor (e.g., MQ-2).
  - Wi-Fi module (ESP32 built-in) for connectivity.
- **Integration**: All components are connected to the ESP32 using GPIO pins.

### **Step 10: Application Development**
- **Flask Application**: A web application to display real-time data and alerts from the ESP32.

## **Installation Instructions**

### **Hardware Setup**
1. Connect the temperature sensor to the ESP32:
   - VCC to 3.3V
   - GND to GND
   - Analog output (e.g., GPIO 34 for LM35 or DHT11)

2. Connect the smoke sensor to the ESP32:
   - VCC to 5V
   - GND to GND
   - Analog output to any GPIO pin (e.g., GPIO 35 for MQ-2)

### **Software Setup**
1. **Install the Arduino IDE**: Ensure you have the latest version.
2. **Install ESP32 Board**: Follow the [ESP32 board installation guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
3. **Install Flask**: Use pip to install Flask for your web application.

   ```bash
   pip install Flask
