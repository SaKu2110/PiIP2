unsigned int i, line = 0;
const char col[5] = {1, 3, 10, 7, 8};
const char row[7] = {12, 11, 2, 9, 4, 5, 6};

void setup(){
  for(i = 0; i < 5; i++) pinMode(col[i], OUTPUT);
  for(i = 0; i < 7; i++) pinMode(row[i], OUTPUT);
}

void loop(){
  /*
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(9, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  */
  for(i = 0; i < 5; i++)  digitalWrite(col[i], LOW);
  digitalWrite(col[line % 5], HIGH);

  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(9, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  line++;
  delay(100);
}
