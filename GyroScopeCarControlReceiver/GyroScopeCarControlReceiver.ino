#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

// AP credentials
const char *ssid = "gyroCar";
const char *password = "getout12";

#define rightmotorforward D6
#define rightmotorback D7
#define leftmotorback D1
#define leftmotorforward D2

// WebSocket server running on port 81
void steerCar(int motorspeedl, int motorspeedr, int delayTime = 0);
WebSocketsServer webSocket = WebSocketsServer(81);

void setup() {
  Serial.begin(115200);

  pinMode(rightmotorforward, OUTPUT);
  pinMode(rightmotorback, OUTPUT);
  pinMode(leftmotorback, OUTPUT);
  pinMode(leftmotorforward, OUTPUT);

  WiFi.softAP(ssid, password);
  Serial.println("AP started");

  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
  Serial.println("WebSocket server started");
}

void loop() {
  webSocket.loop();
  delay(20);
}

int lastMotorSpeedL = 0;
int lastMotorSpeedR = 0;

void steerCar(int motorspeedl, int motorspeedr, int delayTime) {
  if (motorspeedl != lastMotorSpeedL || motorspeedr != lastMotorSpeedR) {
    analogWrite(rightmotorforward, max(motorspeedr, 0));
    analogWrite(leftmotorforward, max(motorspeedl, 0));
    analogWrite(rightmotorback, max(0, -motorspeedr));
    analogWrite(leftmotorback, max(0, -motorspeedl));
    
    lastMotorSpeedL = motorspeedl;
    lastMotorSpeedR = motorspeedr;
  }

  delay(delayTime);
}

void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  if (type == WStype_TEXT) {
    String receivedData = String((char *)payload).substring(0, length);
    Serial.println("Received: " + receivedData);

    StaticJsonDocument<200> doc;

    DeserializationError error = deserializeJson(doc, receivedData);
    if (error) {
      Serial.print("Failed to parse JSON: ");
      Serial.println(error.c_str());
      return;
    }

    int leftMotorSpeed = doc["leftMotorSpeed"];
    int rightMotorSpeed = doc["rightMotorSpeed"];

    leftMotorSpeed = constrain(leftMotorSpeed, -200, 200);
    rightMotorSpeed = constrain(rightMotorSpeed, -200, 200);
      
    Serial.print(leftMotorSpeed); Serial.print("\t");
    Serial.print(rightMotorSpeed); Serial.print("\n");
    steerCar(leftMotorSpeed, rightMotorSpeed);
    delay(70);
  }
}