int data[32];
int rear;

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
  delayMicroseconds(37);
}

void lcd2(char x) {
  lcd(x);
  lcd(x << 4);
}

void lcdInit(){
  delay(40);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  lcd(0x30);
  lcd(0x30);
  lcd(0x30);
  lcd(0x20);

  lcd2(0x28);
  lcd2(0x0c);
  lcd2(0x01);
  delayMicroseconds(1520);
  lcd2(0x06);

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void writeData(int data[32]){
  int i, j, lf = 0;
  lcdInit();
  for(i = 0; i <= rear; i++){
    if (data[i] == 500){
      if(lf == 0){
        for(j = 0; j < 40 - i; j++)
          lcd2(0x20);
        lf = 1;
      }else if(lf == 1){
        lcdInit();
        rear = 0;
        data[rear] = 95;
        lcd2('_'); 
        i = rear + 1;
      }
    }else{
      lcd2(char(data[i])); 
    }
  }
}

void setup() {
  Serial.begin(9600);


  // Setup pin mode
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
    
  lcdInit();
  rear = 0;
  data[rear] = 95;
  writeData(data);
}

void loop() {
  char rx = Serial.read();
  if (rx != -1) {
    if (int(rx) == 127){
      if(rear != 0) {
        rear--;
        data[rear] = 95;
      }
    }else if(rx == 0x0d){
      data[rear] = 500;
      data[rear + 1] = 95;
      rear++;
    }else{
      data[rear] = int(rx);
      data[rear + 1] = 95;
      rear++;
    }
    writeData(data);
  }
}
