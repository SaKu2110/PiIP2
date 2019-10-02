char id[] = "b1018106\n";
char name[] = "Shotaro Yamada\n";
int i = 0;

void setup() {
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(7) == HIGH) {
    if (i == 0) {
      Serial.print(name);
      i = 1;
    }
  }
  else {
    if (i == 1) {
      Serial.print(id);
      i = 0;
    }
  }
}

