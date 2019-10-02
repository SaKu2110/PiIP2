int i = 0;
int j = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  if (digitalRead(7) == HIGH) {
    if (j == 0) i = 1;
    if (j == 1) i = 0;
  }
  else {
  }
  
  // put your main code here, to run repeatedly:
  if (i == 0) {
    digitalWrite(13, LOW);
    if (digitalRead(7) == LOW) j = 0;
  }
  else {
    digitalWrite(13, HIGH);
    if (digitalRead(7) == LOW) j = 1;
  }
}
