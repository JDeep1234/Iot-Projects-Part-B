# Weather Monitoring and Reporting Bot

This project implements a Weather Monitoring system that collects and reports environmental data (temperature, humidity, and atmospheric pressure) in real-time using AWS/ThingSpeak and the ESP32 microcontroller.

## **IoT Design Methodology**

### **Step 1: Purpose & Requirements Specification**
- **Purpose**: To monitor and report real-time weather data to users and provide historical data for analysis.
- **Requirements**:
  - Use DHT11/DHT22 sensors for temperature and humidity measurement.
  - Send data to AWS IoT or ThingSpeak for real-time data visualization.
  - Allow users to access weather data through a web interface.

### **Step 2: Process Specification**
- Collect data from temperature, humidity, and pressure sensors.
- Process and send data to AWS IoT or ThingSpeak.
- Provide a web interface for users to view real-time and historical weather data.

### **Step 3: Domain Model Specification**
- **Actors**:
  - **User**: Wants to monitor weather conditions.
  - **System**: Collects and processes weather data.
- **Entities**:
  - **Sensors**: DHT11/DHT22 for temperature and humidity, BMP180 for pressure.
  - **User Interface**: Web interface displaying weather data.

### **Step 4: Information Model Specification**
- **Data**:
  - Temperature: Float (°C).
  - Humidity: Float (%).
  - Pressure: Float (hPa).
  - Timestamp of data collection.

### **Step 5: Service Specifications**
- **Data Collection Service**: Continuously collects data from sensors.
- **Data Reporting Service**: Sends data to AWS IoT or ThingSpeak for storage and visualization.
- **User Interface Service**: Displays weather data for user access.

### **Step 6: IoT Level Specification**
- **IoT Level**: Level 2 (Sensing and Actuation).
- Sensors provide input, and the system sends data to the cloud for processing and visualization.

### **Step 7: Functional View Specification**
- **Functions**:
  - Read data from DHT11/DHT22 and BMP180 sensors.
  - Process and format data for cloud reporting.
  - Send data to AWS IoT or ThingSpeak.
  - Retrieve and display data on the web interface.

### **Step 8: Operational View Specification**
- **Operation**:
  - The ESP32 continuously reads data from the sensors.
  - The data is sent to AWS IoT or ThingSpeak every specified interval.
  - Users can access the web interface to view real-time data.

### **Step 9: Device & Component Integration**
- **Components**:
  - ESP32 microcontroller.
  - DHT11/DHT22 sensor (for temperature and humidity).
  - BMP180 sensor (for atmospheric pressure).
  - Wi-Fi module (ESP32 built-in) for cloud connectivity.
- **Integration**: All components are connected to the ESP32 using GPIO pins.

### **Step 10: Application Development**
- **Web Interface**: A simple web interface built using HTML/CSS/JavaScript to display real-time weather data.
- **Cloud Service**: AWS IoT or ThingSpeak handles data storage and visualization. Choose between the two based on the project requirements:
  - **AWS IoT**: Offers scalability and integration with other AWS services.
  - **ThingSpeak**: Provides easy setup and built-in visualization tools.
  
## **Installation Instructions**

### **Hardware Setup**
1. Connect the DHT11/DHT22 sensor to the ESP32:
   - VCC to 3.3V
   - GND to GND
   - DATA to any GPIO pin (e.g., GPIO 23)



### **Software Setup**
1. **Install the Arduino IDE**: Make sure you have the latest version.
2. **Install ESP32 Board**: Follow the [ESP32 board installation guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
3. **Install Required Libraries**:
   - DHT sensor library: `DHT sensor library` by Adafruit.
   - HTTP client library (if using HTTP for ThingSpeak or AWS IoT).
