#include "FirebaseESP32.h"  // Install Firebase ESP32 library by Mobizt v4.3.4

#define FIREBASE_HOST "esp32-bms-a0e26-default-rtdb.firebaseio.com"  //Without http:// or https:// schemes
#define FIREBASE_AUTH "1hXJjWKbQ2CzUoeWBnPdQlxq7w9rXouUayVXiUJK"
#define WIFI_SSID "test"
#define WIFI_PASSWORD "12345678"

String FIREBASE_BUCKET = "1RV21CS076";  //Replace with your USN

FirebaseData firebaseData;

int humidity = 0;
int temp = 0;

void setupWiFi() {

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {

  Serial.begin(115200);
  while (!Serial)
    ;

  setupWiFi();
  pinMode(2, OUTPUT);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void readHumidity() {
  humidity = random(0, 100);
}
void readTemp() {
  temp = random(0, 40);
}
void setLamp(String status) {
  if (status == "false") {
    digitalWrite(2, LOW);
    Serial.println("Turned off lamp");
  } else if (status == "true") {
    digitalWrite(2, HIGH);
    Serial.println("Turned on lamp");
  }
}

void loop() {

  readHumidity();
  readTemp();
  Serial.println("Current Humidity: " + String(humidity) + " and Temperature: " + String(temp));
  Firebase.setInt(firebaseData, String(FIREBASE_BUCKET) + "/hum", humidity);
  Firebase.setInt(firebaseData, String(FIREBASE_BUCKET) + "/temp", temp);
  Firebase.getString(firebaseData, String(FIREBASE_BUCKET) + "/lamp");
  setLamp(firebaseData.stringData());
  delay(100);
}




