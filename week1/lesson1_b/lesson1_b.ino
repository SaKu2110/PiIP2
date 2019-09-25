int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  if (digitalRead(7) == HIGH) i = 1;
  else                        i = 0;
  
  // put your main code here, to run repeatedly:
  if (i == 1) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(900);
  }
  else {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }
}
