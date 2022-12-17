int buzzer = 8;



void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=100; i<2000; i++) {
    tone(buzzer,i);
    delay(10);
  }

  for (int i=2000; i>100 ; i++) {
    tone(buzzer, i);
    delay(10);
  }
 

}
