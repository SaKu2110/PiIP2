unsigned int i, line = 0;
int rx, num = 0;
char row = 0;
const char pin_col[5] = {13, 3, 10, 7, 8};
const char pin_row[7] = {12, 11, 2, 9, 4, 5, 6};
const char row_table[12] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02};

void setup() {
  for(i = 0; i < 5; i++) pinMode(pin_col[i], OUTPUT);
  for(i = 0; i < 7; i++) pinMode(pin_row[i], OUTPUT);
}

void loop() {
  unsigned int wk = line % 5;

  for(i = 0; i < 5; i++) digitalWrite(pin_col[i], LOW);
  for(i = 0; i < 7; i++) digitalWrite(pin_row[i], HIGH);

  digitalWrite(pin_col[wk], HIGH);

  for(i = 0; i < 7; i++)
    if(row_table[row] & (0x01 << i))
      digitalWrite(pin_row[i], LOW);

  line++;
  delay(2);

  if(!(line % 256))
    if(row == 11) row = 0;
    else row++;
}
