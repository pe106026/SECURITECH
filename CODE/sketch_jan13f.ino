#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);


int buzzer = 8;
const int led_rouge = 3;
const int led_orange = 4;
char Data;


void setup(){
  pinMode(led_rouge,OUTPUT);
  pinMode(led_orange,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour -Pret pour les commandes AT");
  BlueT.begin(9600);
  delay(500);}




void loop(){
  while (BlueT.available()) {
  Serial.print(char(BlueT.read())); }
  while (Serial.available()) {
  BlueT.write(char(Serial.read())); }
  if (BlueT.available()){
    Data=BlueT.read();
    if (Data=='R') {
    tone(buzzer, 435);
    analogWrite(led_rouge,LOW);
    analogWrite(led_orange,HIGH);
    delay(500);
    tone(buzzer,580);
    analogWrite(led_rouge,HIGH);
    analogWrite(led_orange,LOW);
    delay(500);
    }
  }
