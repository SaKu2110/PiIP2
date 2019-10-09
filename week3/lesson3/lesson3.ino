#include <EEPROM.h>

char name[256];
int i, j = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  while(true){
    name[i] = EEPROM.read(i);
    i ++;
    if(EEPROM.read(i) == '\0') break;
  }
  Serial.print(name);
  delay(1000);
}

