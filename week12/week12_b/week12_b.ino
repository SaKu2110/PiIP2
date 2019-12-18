const int doremi[] = {0, 262, 294, 330, 349, 392,440, 494, 523, 587};
const int music[] = {169,298,387,486,587,685,786,886,187,288,387,485,586,683,745,880,194,293,392,490,592,690,792,890,193,294,395,490,595,690,795,890,196,297,383,485,586,687,786,880,169,298,387,486,587,685,786,886,187,288,387,485,586,683,745,880,194,293,392,490,592,690,792,890,193,294,395,490,597,690,799,890,198,297,383,485,548,680,799,890,197,295,386,415,000};
const unsigned char hex2asc[] = "0123456789";
int i, j, k;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (digitalRead(7));

  i = 0;

  while (1) {
    Serial.write('$');
    Serial.write(hex2asc[music[i] / 100 % 10]);
    Serial.write(hex2asc[music[i] / 10 % 10]);
    Serial.write(hex2asc[music[i] / 1 % 10]);
    Serial.write('\n');
    
    j = music[i] / 10 % 10;
    k = music[i] % 10;

    if (k) tone(9, doremi[k]);
    else noTone(9);

    if (j == 0) break;
    else if (j == 1) delay(2000 - 50);
    else if (j == 2) delay(1000 - 50);
    else if (j == 3) delay(750 - 50);
    else if (j == 4) delay(500 - 50);
    else if (j == 6) delay(375 - 50);
    else if (j == 8) delay(250 - 50);
    else if (j == 9) delay(125 - 50);

    noTone(9);
    delay(50);

    i++;
  }

}
