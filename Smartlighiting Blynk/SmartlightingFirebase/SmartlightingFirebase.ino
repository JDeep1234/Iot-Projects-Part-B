#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <addons/TokenHelper.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor 
#define DHTTYPE DHT11     // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);
/* 1. Define the WiFi credentials */
#define WIFI_SSID "Death"
#define WIFI_PASSWORD "12345678"

//For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyCE8CaByUXl7IILcpgcpxYeE6IlIEhfzSs"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://test-project-7c1be-default-rtdb.firebaseio.com/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "eshaan123@gmail.com"
#define USER_PASSWORD "123456"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

String prevUser2Data = "";
unsigned long lastReadTime = 0;
unsigned long lastLedReadTime = 0;
void setup()
{

  Serial.begin(115200);

  pinMode(16,OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  dht.begin();
}

void loop()
{
  sensors_event_t event;


  if (millis() - lastReadTime > 5000)
  {
    dht.humidity().getEvent(&event);
    Serial.print(event.relative_humidity);
    Serial.printf("\nsending hum data :  %s\n", Firebase.setFloat(fbdo, "/Sensor/Humidity", event.relative_humidity) ? "ok" : fbdo.errorReason().c_str());
    dht.temperature().getEvent(&event);
    Serial.print(event.temperature);
    Serial.printf("sending temp data : %s\n", Firebase.setFloat(fbdo, "/Sensor/Temperature", event.temperature) ? "ok" : fbdo.errorReason().c_str());
    lastReadTime = millis();
  }

  if(millis() - lastLedReadTime > 1000)
  {
    readData(); 
    lastLedReadTime = millis(); 
  }
}

void readData()
{
  if (Firebase.getInt(fbdo, "/led")) {

    if (fbdo.dataTypeEnum() == fb_esp_rtdb_data_type_integer) {
      int data = fbdo.to<int>();
      Serial.println(data);
      digitalWrite(16,data);
    }

  } else {
    Serial.println(fbdo.errorReason());
  }
}