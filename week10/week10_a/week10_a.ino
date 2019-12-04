unsigned int i, line = 0;
int rx, num = 0;
char col = 0;
const char pin_col[5] = {13, 3, 10, 7, 8};
const char pin_row[7] = {12, 11, 2, 9, 4, 5, 6};
const char col_table[8] = {0, 1, 2, 3, 4, 3, 2, 1};

void setup() {
  for(i = 0; i < 5; i++) pinMode(pin_col[i], OUTPUT);
  for(i = 0; i < 7; i++) pinMode(pin_row[i], OUTPUT);
}

void loop() {
  unsigned int wk = line % 5;

  for(i = 0; i < 5; i++) digitalWrite(pin_col[i], LOW);
  for(i = 0; i < 7; i++) digitalWrite(pin_row[i], HIGH);

  digitalWrite(pin_col[wk], HIGH);

  if(wk == col_table[col])
    for(i = 0; i < 7; i++) digitalWrite(pin_row[i], LOW);

  line++;
  delay(2);

  if(!(line % 256))
    if(col == 7) col = 0;
    else col++;
}
