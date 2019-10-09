char name[256];
int rx, i = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  rx = Serial.read();

  if (rx != -1) {
    if (rx == '?'){
      Serial.print(name);
    }
    else{
      if (rx == '@') {
        i = 0;
      }
      else if (rx == '\n'){
        name[i++] = rx;
        name[i++] = 0;
      }
      else {
        name[i++] = rx;
      }
    }
  }
}

