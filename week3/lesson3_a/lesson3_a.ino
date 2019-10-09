int ad;

void setup(){
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

// 600 off
// 500 on
void loop(){
  ad = analogRead(A0);
  Serial.println(ad);
  if(analogRead(A0) > 600){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }
  
}

