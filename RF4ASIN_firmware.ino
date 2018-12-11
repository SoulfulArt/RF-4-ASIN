#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define LEDRED 16
#define LEDGREEN 12
#define LEDBLUE 2
#define LEDYELLOW 15
 
const char* ssid = "BOLSONAROLINDO";
const char* password = "PIC@NH@S";

void checkCmd();

void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDBLUE, LOW);
  digitalWrite(LEDYELLOW, LOW);

}
 
void loop() {

  checkCmd();
  delay(150);    //Send a request every 30 seconds
 
}

void checkCmd(){

  HTTPClient http;  //Declare an object of class HTTPClient
 
  http.begin("http://192.168.1.102/data");  //Specify request destination
  int httpCode = http.GET();

  String payload = http.getString();   //Get the request response payload
  Serial.println(payload);                     //Print the response payload

  if (!payload.compareTo("r0"))
    digitalWrite(LEDRED, LOW);

  if (!payload.compareTo("r1"))
    digitalWrite(LEDRED, HIGH);

  if (!payload.compareTo("g0"))
    digitalWrite(LEDGREEN, LOW);

  if (!payload.compareTo("g1"))
    digitalWrite(LEDGREEN, HIGH);

  if (!payload.compareTo("b0"))
    digitalWrite(LEDBLUE, LOW);

  if (!payload.compareTo("b1"))
    digitalWrite(LEDBLUE, HIGH);

  if (!payload.compareTo("y0"))
    digitalWrite(LEDYELLOW, LOW);

  if (!payload.compareTo("y1"))
    digitalWrite(LEDYELLOW, HIGH);

  http.end();   //Close connection

}
