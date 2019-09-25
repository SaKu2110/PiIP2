int i = 0;
int lightHigh = 0;
int lightLow = 0;
unsigned long pushTime = 0;
unsigned long time;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  if (digitalRead(7) == HIGH) i = 1;
  else {
    if (i == 1) pushTime = millis();
    i = 0;
  }
  
  // put your main code here, to run repeatedly:
  if (i == 1) {
    lightHigh = 100;
    lightLow = 900;
  }
  else {
    if (millis() - pushTime >= 3000) {
      lightHigh = 100;
      lightLow = 100;
    }
    else {
      lightHigh = 100;
      lightLow = 400;
    }
  }
    digitalWrite(13, HIGH);
    delay(lightHigh);
    digitalWrite(13, LOW);
    delay(lightLow);
}
