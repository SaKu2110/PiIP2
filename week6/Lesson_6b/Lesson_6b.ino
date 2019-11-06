// 0x80: 10000000
// 0x40: 01000000
// 0x20: 00100000
// 0x10: 00010000
// 0x08: 00001000
// 0x04: 00000100
// 0x02: 00000010
// 0x01: 00000001

// 0x3*:
// 0x2*:
// 


void lcd(char x) {
  
  digitalWrite(6, HIGH);
  if (x & 0x80)  digitalWrite(11, HIGH);
  else           digitalWrite(11, LOW);
  if (x & 0x40)  digitalWrite(10, HIGH);
  else           digitalWrite(10, LOW);
  if (x & 0x20)  digitalWrite(9, HIGH);
  else           digitalWrite(9, LOW);
  if (x & 0x10)  digitalWrite(8, HIGH);
  else           digitalWrite(8, LOW);
  digitalWrite(6, LOW);
}

void lcd2(char x) {
  digitalWrite(6, HIGH);
  if (x & 0x80)  digitalWrite(11, HIGH);
  else           digitalWrite(11, LOW);
  if (x & 0x40)  digitalWrite(10, HIGH);
  else           digitalWrite(10, LOW);
  if (x & 0x20)  digitalWrite(9, HIGH);
  else           digitalWrite(9, LOW);
  if (x & 0x10)  digitalWrite(8, HIGH);
  else           digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  digitalWrite(6, HIGH);
  if (x & 0x08)  digitalWrite(11, HIGH);
  else           digitalWrite(11, LOW);
  if (x & 0x04)  digitalWrite(10, HIGH);
  else           digitalWrite(10, LOW);
  if (x & 0x02)  digitalWrite(9, HIGH);
  else           digitalWrite(9, LOW);
  if (x & 0x01)  digitalWrite(8, HIGH);
  else           digitalWrite(8, LOW);
  digitalWrite(6, LOW);
}

void setup() {

  // Setup pin mode
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delayMicroseconds(40);
  lcd("00110000");
  delayMicroseconds(37);
  lcd("00110000");
  delayMicroseconds(37);
  lcd("00110000");
  delayMicroseconds(37);
  lcd("00100000");
  delayMicroseconds(37);
  lcd2("00101000");
  delayMicroseconds(37);
  lcd2("00001100");
  delayMicroseconds(37);
  lcd2("00000001");
  delayMicroseconds(1520);
  lcd2("00000110");
  delayMicroseconds(37);
}

int i = 0;        // 変数の定義と初期化

void loop() {;
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  lcd2('0'+ '1');
  delayMicroseconds(37);
  i++;
  if (i == 80) {
    i = 0;
  }
}
