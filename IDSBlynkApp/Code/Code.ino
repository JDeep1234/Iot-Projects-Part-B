#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

// Library includes
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Define your Wi-Fi credentials
char ssid[] = "YourSSID";
char pass[] = "YourPassword";

// Define GPIO pins
int pirPin = 27;  // PIR sensor output connected to GPIO 27
int ledPin = 26;  // LED connected to GPIO 26

boolean lockLow = true;
long unsigned int lowIn;
long unsigned int motionPause = 5000;

// Blynk virtual pins
#define VIRTUAL_BUTTON V0
#define VIRTUAL_LED V1

BlynkTimer timer;

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);

  // Set up the PIR sensor and LED pins
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Give the PIR sensor some time to calibrate
  Serial.print("Calibrating sensor ");
  for (int i = 0; i < 5; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);

  // Timer to check the PIR sensor state
  timer.setInterval(100L, checkPIRSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}

void checkPIRSensor() {
  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
    Blynk.virtualWrite(VIRTUAL_LED, 255);  // Turn on virtual LED in Blynk app

    if (lockLow) {
      lockLow = false;
      Serial.println("Intrusion detected🚨❗");
      Blynk.notify("Intrusion detected!🚨❗");
    }
  }

  if (digitalRead(pirPin) == LOW) {
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(VIRTUAL_LED, 0);  // Turn off virtual LED in Blynk app

    if (!lockLow && millis() - lowIn > motionPause) {
      lockLow = true;
      lowIn = millis();
      Serial.println("Detection Ended");
    }
  }
}

// Button widget function to control the LED manually
BLYNK_WRITE(VIRTUAL_BUTTON) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
