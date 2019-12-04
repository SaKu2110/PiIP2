unsigned int i, line;
int rx, num = 0;
char col, row, bar;
boolean flag;
const char pin_col[5] = {13, 3, 10, 7, 8};
const char pin_row[7] = {12, 11, 2, 9, 4, 5, 6};
const char col_table[8] = {0, 1, 2, 3, 4, 3, 2, 1};
const char row_table[12] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02};
const char bar_table[6] = {0x03, 0x06, 0x0c, 0x18, 0x30, 0x60};

void initPinMode() {
  for (i = 0; i < 5; i++) pinMode(pin_col[i], OUTPUT);
  for (i = 0; i < 7; i++) pinMode(pin_row[i], OUTPUT);
}

void initPin() {
  for (i = 0; i < 5; i++) digitalWrite(pin_col[i], LOW);
  for (i = 0; i < 7; i++) digitalWrite(pin_row[i], HIGH);
}

void initVars() {
  line = 0;
  col = 0;
  row = 0;
}

void setup() {
  initPinMode();
  initVars();

  flag = true;
}

void pinpon() {
  unsigned int wk = line % 5;

  initPin();

  digitalWrite(pin_col[wk], HIGH);

  for (i = 0; i < 7; i++) {
    if (wk == col_table[col])
      if (row_table[row] & (0x01 << i))
        digitalWrite(pin_row[i], LOW);
    if (wk == 4) {
      if (bar_table[bar] & (0x01 << i))
        digitalWrite(pin_row[i], LOW);
      if (col == 4)
        if (row_table[row] & (0x01 << i) && !(bar_table[bar] & (0x01 << i)))
          flag = false;
    }
  }

  line++;
  delay(2);

  bar = analogRead(A0) / 171;

  if (!(line % 256)) {
    if (col == 7) col = 0;
    else col++;
    if (row == 11) row = 0;
    else row++;
  }
}

void loop() {
  if (flag)
    pinpon();
  else {

    initPin();
    initVars();

    delay(4000);
    flag = true;
  }
}
