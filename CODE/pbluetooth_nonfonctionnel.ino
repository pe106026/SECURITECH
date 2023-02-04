#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);

int buzzer = 8;
const int led_rouge = 3;
const int led_orange = 4;
char Data;


void setup() {
  pinMode(led_rouge, OUTPUT);
  pinMode(led_orange,OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour -Pret pour les commandes AT");
  BlueT.begin(9600);
  delay(500);
  }


  
void loop() {
  //Du module vers le moniteur
  while (BlueT.available()) {
    Serial.print(char(BlueT.read())); }
  //Du moniteur vers le module
  while (Serial.available()) {
    BlueT.write(char(Serial.read())); }


  Data=BlueT.read();
if (Data=='A') {
  digitalWrite(led_rouge, LOW);
  digitalWrite(led_orange,HIGH);
  tone(buzzer, 435);
  delay(500);
  digitalWrite(led_rouge,HIGH);
  digitalWrite(led_orange, LOW);
  tone(buzzer,580);
  delay(500);
}
   
  

  

}
