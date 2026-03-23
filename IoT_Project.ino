#include <ArduinoJson.h>            
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SPI.h>
#include <MFRC522.h>

#define _SSID "PandaPhone"          
#define _PASSWORD "panda1760"      
#define REFERENCE_URL "iotproject-c5714-default-rtdb.europe-west1.firebasedatabase.app"  
WiFiClient client;

constexpr uint8_t RST_PIN = D3;     
constexpr uint8_t SS_PIN = D4;     

MFRC522 rfid(SS_PIN, RST_PIN); 
Firebase firebase(REFERENCE_URL);

String cardID;
String macAddress;
String tag;
int i = 1;

void setup() {
   Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
     WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(1000);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("RFID reader module tester...");
  
  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  digitalWrite(LED_BUILTIN, HIGH);
  macAddress = WiFi.macAddress(); 
}

void readCard() {
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (rfid.PICC_ReadCardSerial()) {
    tag = "";
    for (byte j = 0; j < 4; j++) {
      tag += rfid.uid.uidByte[j];
    }

    Serial.print("Read counter: ");
    Serial.println(i);
    Serial.println(tag);

    firebase.setString("floors/floor0/tables/table1/chairs/chair1/cardID", tag);
    firebase.setString("floors/floor0/tables/table1/chairs/chair1/status", "occupied");
    firebase.json(true);

    String data = firebase.getString(macAddress);

    const size_t capacity = JSON_OBJECT_SIZE(2) + 50;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, data);

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    i++;
  }
}

void loop() {
  readCard();

  if (millis() % 100 == 0) 
  {
    tag = "0";
    Serial.print("Read counter: ");
    Serial.println(i);
    Serial.println(tag);

    firebase.setString("floors/floor0/tables/table1/chairs/chair1/cardID", tag);
    firebase.setString("floors/floor0/tables/table1/chairs/chair1/status", "available");
    firebase.json(true);

    String data = firebase.getString(macAddress);

    const size_t capacity = JSON_OBJECT_SIZE(2) + 50;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, data);

    i++;
  }

  delay(1000);
}
