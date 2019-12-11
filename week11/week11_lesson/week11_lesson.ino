unsigned int i, line = 0;
int rx, num = 0;
char col = 0, row = 0;
int x, y;
const char pin_col[5] = {13, 3, 10, 7, 8};
const char pin_row[7] = {12, 11, 2, 9, 4, 5, 6};
const char dot[5] = {0x22, 0x2a, 0x2a, 0x2a, 0x08};

void setup() {
  for (i = 0; i < 5; i++) pinMode(pin_col[i], OUTPUT);
  for (i = 0; i < 7; i++) pinMode(pin_row[i], OUTPUT);

  Serial.begin(9600);
}

void loop() {
  unsigned int wk = line % 5;

  for (i = 0; i < 5; i++) digitalWrite(pin_col[i], LOW);
  for (i = 0; i < 7; i++) digitalWrite(pin_row[i], HIGH);

  digitalWrite(pin_col[wk], HIGH);

  for (i = 0; i < 7; i++)
    digitalWrite(pin_row[i], !(dot[wk] & (0x01 << i)));

  if (line % 64 < 32)
    if(wk == col)
      for(i = 0; i < 7; i++)
        if (i == row)
          digitalWrite(pin_row[i], LOW);

  

  line++;
  delay(2);

  if (!(line % 256)) {
    x = analogRead(A0);
    y = analogRead(A1);

    int dx = (x - 204) / 88;
    int dy = (y - 204) / 123;
    if      (dx < 3 && row != 6) {
      if ((col == 4 && row != 2) || (col == 0 && row != 1 && row != 4)) row ++;
    }
    else if (dx > 3 && row != 0) {
      if ((col == 4 && row != 4) || (col == 0 && row != 2 && row != 6)) row --;
    }
    if      (dy < 2 && col != 4) {
      if (row % 2 == 0) col ++;
    }
    else if (dy > 2 && col != 0) {
      if (row % 2 == 0) col --;
    }
    Serial.print(dx);
    Serial.print(',');
    Serial.print(dy);
    Serial.print('\n');
  }
}
