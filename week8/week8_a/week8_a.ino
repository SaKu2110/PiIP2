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
}

void loop(){
  digitalWrite(10, HIGH);
  seg(0x01);
}
