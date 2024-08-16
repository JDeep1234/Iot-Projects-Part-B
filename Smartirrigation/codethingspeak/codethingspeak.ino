#include <WiFi.h>
#include <HTTPClient.h>

// Define pins
const int moisturePin = 34;   // Analog pin for soil moisture sensor
const int ledPin = 4;        // Digital pin for LED

// Threshold for soil moisture level
const int moistureThreshold = 3600;

// Wi-Fi credentials
const char* ssid = "Hello";            // Replace with your Wi-Fi SSID
const char* password = "12345678";    // Replace with your Wi-Fi password

// ThingSpeak settings
const char* server = "http://api.thingspeak.com/update";
const char* apiKey = "NXIMXONGXD4AV98C";       // Replace with your ThingSpeak Write API Key

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Turn off the LED initially
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");
}

void loop() {
  // Read the value from the soil moisture sensor
  int moistureValue = analogRead(moisturePin);
  
  // Print the moisture value for debugging
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureValue);
  
  // Debugging: Check if the sensor value is in the expected range
  if (moistureValue >= 0 && moistureValue <= 4095) {
    Serial.println("Sensor reading is valid");
  } else {
    Serial.println("Sensor reading out of range! Check sensor connection.");
  }
  
  // Check if the soil moisture is below the threshold
  if (moistureValue >  moistureThreshold) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
  }

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) { // Check Wi-Fi connection
    HTTPClient http;
    String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(moistureValue);
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Wi-Fi not connected");
  }

  // Wait for a while before the next reading
  delay(2000);
}