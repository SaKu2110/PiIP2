
int ad, tm = 0, num = '0', flag = 0;
double volt, distance;
char seg_table[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0xf7f, 0x67};

void seg(char x) {
  if(x & 0x80)  digitalWrite(9, LOW);
  else          digitalWrite(9, HIGH);
  if(x & 0x40)  digitalWrite(8, LOW);
  else          digitalWrite(8, HIGH);
  if(x & 0x20)  digitalWrite(7, LOW);
  else          digitalWrite(7, HIGH);
  if(x & 0x10)  digitalWrite(6, LOW);
  else          digitalWrite(6, HIGH);
  if(x & 0x08)  digitalWrite(5, LOW);
  else          digitalWrite(5, HIGH);
  if(x & 0x04)  digitalWrite(4, LOW);
  else          digitalWrite(4, HIGH);
  if(x & 0x02)  digitalWrite(3, LOW);
  else          digitalWrite(3, HIGH);
  if(x & 0x01)  digitalWrite(2, LOW);
  else          digitalWrite(2, HIGH);
}

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

// 20cm 1.3 [V]
// 50cm 0.6 [V]
// 80cm 0.4 [V]
// 20cm ~ 50cm 区間 volt = -( 0.7 / 30 )dis + 5.3 / 3
// 50cm ~ 80cm 区間 volt = -( 0.2 / 30 )dis + 2.8 / 3
void loop(){
  if(tm % 60 == 0){
    ad = analogRead(A0);
    volt = (double)ad * 5.0 / 1023.0;
    if (volt <= 0.6){
      distance = (volt - 2.8 / 3.0) / -( 0.2 / 30.0 );
    }else{
      distance = (volt - 5.3 / 3.0) / -( 0.7 / 30.0 );
    }
    Serial.println((int)distance);
  }

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  seg(0x00);

  digitalWrite(10, HIGH);
  seg(seg_table[(int)distance / 10]);
  delay(10);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  seg(0x00);

  digitalWrite(11, HIGH);
  seg(seg_table[(int)distance % 10]);
  delay(10);
  tm++;
}
