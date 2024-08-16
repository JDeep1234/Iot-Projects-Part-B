#define LED_PIN 2         // GPIO pin where the LED is connected
#define LDR_PIN 34        // GPIO pin where the LDR is connected (use an ADC1 pin)

#define BLYNK_TEMPLATE_ID "TMPL3Et5_xZQ5"
#define BLYNK_TEMPLATE_NAME "Smart LIGHTING"
#define BLYNK_AUTH_TOKEN "WXEh7I_38k8qfNSB00L34pmrrgkNDXeT"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Wi-Fi credentials
char ssid[] = "Hello";   // Your Wi-Fi name
char pass[] = "12345678";    // Your Wi-Fi password

BlynkTimer timer;

void setup() {
  // Initialize serial communication at a baud rate of 115200
  Serial.begin(115200);
  
  // Configure the LED_PIN as an output
  pinMode(LED_PIN, OUTPUT);

  // Configure the LDR_PIN as an input (no need for pinMode as analogRead handles it)

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Start with the LED turned off
  digitalWrite(LED_PIN, LOW);

  // Set a timer to send LDR values every 1 second
  timer.setInterval(1000L, sendLDR);
}

void sendLDR() {
  // Read the analog value from the LDR
  int ldrValue = analogRead(LDR_PIN);

  // Print the LDR value to the Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Send LDR value to Blynk app
  Blynk.virtualWrite(V5, ldrValue);  // V5 is a virtual pin for LDR value

  // Control the LED based on the LDR value
  if (ldrValue > 4080) {  // Adjust this threshold value as per your requirement
    digitalWrite(LED_PIN, LOW);  // Turn off the LED
    Serial.println("LED OFF");   // Print the LED status
  } else {
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
    Serial.println("LED ON");     // Print the LED status
  }
}

void loop() {
  Blynk.run();
  timer.run(); // Run the timer to send the LDR value at intervals
}

BLYNK_WRITE(V0) {
  int ledState = param.asInt(); // Get the state of the switch (1 for ON, 0 for OFF)
  if (ledState == 1) {
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
    Serial.println("LED ON");    // Print LED status
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn off the LED
    Serial.println("LED OFF");   // Print LED status
  }
}