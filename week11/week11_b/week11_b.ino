unsigned int i, line = 0;
int rx, num = 0;
char col = 2, row = 3;
int x, y;
const char pin_col[5] = {13, 3, 10, 7, 8};
const char pin_row[7] = {12, 11, 2, 9, 4, 5, 6};

void setup() {
  for (i = 0; i < 5; i++) pinMode(pin_col[i], OUTPUT);
  for (i = 0; i < 7; i++) pinMode(pin_row[i], OUTPUT);
}

void loop() {
  unsigned int wk = line % 5;

  for (i = 0; i < 5; i++) digitalWrite(pin_col[i], LOW);
  for (i = 0; i < 7; i++) digitalWrite(pin_row[i], HIGH);

  digitalWrite(pin_col[wk], HIGH);

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

    row = (x - 204) / 88;
    col = (y - 204) / 123;
  }
}
