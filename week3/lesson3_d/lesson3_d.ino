#include <EEPROM.h>

char name[256];
int rx, i = 0;

void setup(){
  Serial.begin(9600);
}

void loop() {
  rx = Serial.read();

  if (rx != -1){
    if(rx == '?'){
      // 受信データ有の場合の処理
    }
    else{
      if(rx == '@'){
        i = 0;
      }
      else if(rx == '\n'){
        EEPROM.write(i++, rx);
        EEPROM.write(i++, 0);
      }
      else {
        EEPROM.write(i++, rx);
      }
    }
  }
}

