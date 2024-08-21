#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>
#include "MPU6050.h"

// AP credentials
const char *ssid = "gyroCar";
const char *password = "getout12";

struct rotationData {
  int x;
  int y;
};

struct steerData {
  int leftMotorSpeed;
  int rightMotorSpeed;
};

MPU6050 accelgyro;

int16_t ax, ay, az;

WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length) {
  if (type == WStype_DISCONNECTED) {
    Serial.println("WebSocket Disconnected");
  } else if (type == WStype_CONNECTED) {
    Serial.println("WebSocket Connected");
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  // Connect to the AP
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");
  accelgyro.initialize();

  // Connect to WebSocket server
  webSocket.begin("192.168.4.1", 81, "/");
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED){
    connecting();
  }
  webSocket.loop();
  
  rotationData rot = getData();
  steerData move = processData(rot);
  sendData(move);


  delay(200);
}

rotationData getData() {
  rotationData posData;
  accelgyro.getAcceleration(&ax, &ay, &az);

  posData.x = -ax/70;
  posData.y = -ay/90;
  return posData;
}

steerData processData(rotationData rot) {
  steerData data;

  int left = abs(rot.x - rot.y) < 60 ? 0 : rot.x-rot.y;
  int right = abs(rot.x + rot.y) < 60 ? 0 : rot.x+rot.y;

  
  left = constrain(left, -220 , 220); 
  right = constrain(right, -220 , 220);

  data.leftMotorSpeed = left;
  data.rightMotorSpeed = right;

  Serial.print(left); Serial.print("\t");
  Serial.print(right); Serial.print("\n");
  return data;
}

void sendData(steerData data){
  String message = "{\"leftMotorSpeed\":" + String(data.leftMotorSpeed) + ",\"rightMotorSpeed\":" + String(data.rightMotorSpeed) + "}";
  webSocket.sendTXT(message);
}


void connecting() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("Connected to WiFi");
}