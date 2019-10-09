int rx;

void setup(){
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

// 600 off
// 500 on
void loop(){
  rx = Serial.read();
  if(rx== '1') digitalWrite(8, HIGH);
  else if(rx == '0') digitalWrite(8, LOW);
  
}

