unsigned int i, rx, num = 0, line = 0, flag;
const char col[5] = {13, 3, 10, 7, 8};
const char row[7] = {12, 11, 2, 9, 4, 5, 6};
const char dot[11][5] = {
  {0x3e, 0x51, 0x49, 0x45, 0x3e},
  {0x00, 0x42, 0x7f, 0x40, 0x00},
  {0x42, 0x61, 0x51, 0x49, 0x46},
  {0x21, 0x41, 0x45, 0x4b, 0x31},
  {0x18, 0x14, 0x12, 0x7f, 0x10},
  {0x27, 0x45, 0x45, 0x45, 0x39},
  {0x3c, 0x4a, 0x49, 0x49, 0x30},
  {0x01, 0x71, 0x09, 0x05, 0x03},
  {0x36, 0x49, 0x49, 0x49, 0x36},
  {0x06, 0x49, 0x49, 0x29, 0x1e},
  {0x7f, 0x48, 0x44, 0x44, 0x38}
};
const int sn[8] = {10, 1, 0, 1, 8, 1, 0, 6};

void lightInit(){
  for(i = 0; i < 5; i++) digitalWrite(col[i], LOW);
  for(i = 0; i < 7; i++) digitalWrite(row[i], HIGH);
}

void setup(){
  for(i = 0; i < 5; i++) pinMode(col[i], OUTPUT);
  for(i = 0; i < 7; i++) pinMode(row[i], OUTPUT);
  Serial.begin(9600);

  flag = 0;
}

void loop(){
  unsigned int wk = line % 5;
  rx = Serial.read();
  if(rx == 63) flag = 1;

  lightInit();
  
  if (flag != 0){
    digitalWrite(col[wk], HIGH);

    if(line%5 == 2) digitalWrite(9, HIGH);
  
    digitalWrite(12, !(dot[sn[num]][wk] & 0x01));
    digitalWrite(11, !(dot[sn[num]][wk] & 0x02));
    digitalWrite(2, !(dot[sn[num]][wk] & 0x04));
    digitalWrite(9, !(dot[sn[num]][wk] & 0x08));
    digitalWrite(4, !(dot[sn[num]][wk] & 0x10));
    digitalWrite(5, !(dot[sn[num]][wk] & 0x20));
    digitalWrite(6, !(dot[sn[num]][wk] & 0x40));

    line++;
    if (line % 300 == 299) num++;
    if(num == 8){
      flag = 0; // 終了条件
      num  = 0;
      line = 0;
    }
    delay(2);
  }
}
