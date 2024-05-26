
#include <WiFiEspAT.h>

#include <SoftwareSerial.h>
SoftwareSerial Serial1(11,12);
#define AT_BAUD_RATE 9600


const char* server = "carduinodevelopers.com";
WiFiClient client;
char buffer[128];
int bufferIndex = 0; 
bool ileriFlag = false;
bool geriFlag = false;
bool sagFlag = false;
bool solFlag = false;
bool bosFlag = false;


const int Enable_A = 9;
const int Enable_B = 10;
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Enable_A, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  while (!Serial);

  Serial1.begin(AT_BAUD_RATE);
  WiFi.init(Serial1);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println();
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  Serial.println("Waiting for connection to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print('.');
  }
  Serial.println();
  Serial.println("Connected to WiFi network.");
  Serial.println("Starting connection to server...");
  if (client.connect(server,80)) {
    Serial.println("connected to server");

    client.println("GET /index.txt HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.flush();
  }
}

void loop() {

  while (client.available()) {
    char c = client.read();
   
    if (c == '\n') {
      if (strstr(buffer, "ileri") != NULL && !ileriFlag) {
        ileri();
        ileriFlag = true;
        geriFlag = false;
        sagFlag = false;
        solFlag = false;
        bosFlag = false;
      }
      if (strstr(buffer, "geri") != NULL && !geriFlag) {
        geri();
        ileriFlag = false;
        geriFlag = true;
        sagFlag = false;
        solFlag = false;
        bosFlag = false;
      }
      if (strstr(buffer, "sag") != NULL && !sagFlag) {
        sag();
        ileriFlag = false;
        geriFlag = false;
        sagFlag = true;
        solFlag = false;
        bosFlag = false;
      }
      if (strstr(buffer, "sol") != NULL && !solFlag) {
        sol();
        ileriFlag = false;
        geriFlag = false;
        sagFlag = false;
        solFlag = true;
        bosFlag = false;
      }
      if (strstr(buffer, "bos") != NULL && !bosFlag) {
        sol();
        ileriFlag = false;
        geriFlag = false;
        sagFlag = false;
        solFlag = false;
        bosFlag = true;
      }
     
     
      memset(buffer, 0, sizeof(buffer));
      bufferIndex = 0;
    } else {
      
      buffer[bufferIndex++] = c;
    }
  }

  if (!client.connected()) {
    client.stop();
    delay(100);
    client.connect(server,80);
    client.println("GET /index.txt HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.flush();
    delay(100);
  }
}
void ileri(){
  Serial.println("ileri komutu basariyla alindi");
  digitalWrite(Enable_A, 200);
  digitalWrite(Enable_B, 200);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3 ,1);
  digitalWrite(in4, 0);
}
void geri(){
    Serial.println("geri komutu basariyla alindi");
    digitalWrite(Enable_A, 200);
    digitalWrite(Enable_B, 200);
    digitalWrite(in1,0);
    digitalWrite(in2, 1);
    digitalWrite(in3 , 0);
    digitalWrite(in4, 1);
}
void sag(){
    Serial.println("sag komutu basariyla alindi");
    digitalWrite(Enable_A, 200);
    digitalWrite(Enable_B, 200);
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3 , 1);
    digitalWrite(in4, 0);
}
void sol(){
    Serial.println("sol komutu basariyla alindi");
    digitalWrite(Enable_A, 200);
    digitalWrite(Enable_B, 200);
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3 , 0);
    digitalWrite(in4, 1);
}