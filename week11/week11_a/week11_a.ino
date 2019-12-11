int x, y, z;
int rx, flag = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  rx = Serial.read();
  if      (rx == '1') flag = 1;
  else if (rx == '0') flag = 0;

  if (flag) {
    x = analogRead(A0);
    y = analogRead(A1);
    z = analogRead(A2);

    Serial.print(x);
    Serial.print(',');
    Serial.print(y);
    Serial.print(',');
    Serial.print(z);
    Serial.print(',');
    Serial.print('\n');
  }

  delay(100);
}
