#include <Servo.h> //Librairie du Servo moteur
#include <LiquidCrystal_I2C.h>
int buzzer = 8;
const int trigPin = 9;
const int echoPin = 10;


LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//Variables
long temps; //Duree sur 4 octets
int distance = 0; //Distance sur 2 octets
int previousDistance = 0;

Servo myServo; // Création d'un objet "servo" qui nous permettra de contrôler le moteur


void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(trigPin, OUTPUT); // trigPin en Output
  pinMode(echoPin, INPUT); //EchoPin en Input
  
  myServo.attach(3); //Sortie moteur

  lcd.init(); // Print a message to the LCD.
  lcd.backlight();

}


void loop() {
  //On fait tourner le moteur de 0 à 180 degrés
  for(int i=0;i<=180;i++){  
    myServo.write(i);
    delay(30);

    previousDistance = distance;
    distance = calculerDistance();// On appelle la fonction pour calculer la distance mesuré par le capteur ultra-sons(pour chaque degré)
    if (previousDistance < 10 && distance < 10) {
      tone(buzzer, 435);
      delay(500);
      tone(buzzer,580);
      delay(500);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Intrus");
      lcd.setCursor(2,1);
      lcd.print("detecte");}
       
    else {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Tout va");
      lcd.setCursor(2,1);
      lcd.print("Bien");
      //eteindre le buzzer
      noTone(8);
  }
  
  Serial.print(i); // Envoi le degré de rotation actuel dans le port série (pour l'IDE processing)
  Serial.print(","); 
  Serial.print(distance); // Envoi la distance dans le port série (pour l'IDE processing)
  Serial.print(".");
  }
  delay(10);
  // Moteur de 180 à 0 degrés
  for(int i=180;i>0;i--){  
    myServo.write(i);
    delay(30);

    
    previousDistance = distance;
    distance = calculerDistance();
    if (previousDistance < 10 && distance < 10) {
      tone(buzzer, 435);
      delay(500);
      tone(buzzer,580);
      delay(500);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Intrus");
      lcd.setCursor(2,1);
      lcd.print("detecte");}
       
    else {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Tout va");
      lcd.setCursor(2,1);
      lcd.print("Bien");
      //eteindre le buzzer
      noTone(8);
  }
  }
}
  // Fonction de mesure de la distance par ultra-sons
  int calculerDistance(){ 
  
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); // génération de l'impulsion Trig de 10 µs
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    temps = pulseIn(echoPin, HIGH); // lecture de la durée de l'impulsion Echo en µs
   
    distance= temps*0.034/2;


    return distance;
  }
