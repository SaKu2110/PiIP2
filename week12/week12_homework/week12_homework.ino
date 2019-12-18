const int doremi[] = {0, 262, 294, 330, 349, 392, 440, 494, 523, 587};
int i, j, k, l;
int flag = 0;
unsigned char rx;
unsigned char rdata[8];

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    rx = Serial.read();
    if (rx == '$') i = 0;
    rdata[i++] = rx;
    if (rx == '\n') flag = 1;
  }
  if (flag) {
    l = rdata[1] - '0';                     
    j = rdata[2] - '0';
    k = rdata[3] - '0';

    if ((l % 2 == 0)? true:(l == 9)? true:false) {
      if (k) {
        if (j == 0);
        else if (j == 1) tone(9, doremi[k], 2000 - 50);
        else if (j == 2) tone(9, doremi[k], 1000 - 50);
        else if (j == 3) tone(9, doremi[k], 750 - 50);
        else if (j == 4) tone(9, doremi[k], 500 - 50);
        else if (j == 6) tone(9, doremi[k], 375 - 50);
        else if (j == 8) tone(9, doremi[k], 250 - 50);
        else if (j == 9) tone(9, doremi[k], 125 - 50);
      }
    }

    flag = 0;
  }

}
