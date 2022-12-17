int buzzer = 8;



void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, 435);
  delay(500);
  tone(buzzer,580);
  delay(500);
 

}
