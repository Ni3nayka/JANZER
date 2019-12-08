#include <EEPROM.h> 
int address = 0; 
byte value; 
char ser;
byte ser2;
int i = 0;
int n = 0;

void setup() { 
  Serial.begin(9600);   
  /*EEPROM.update(0,14); 
  value=EEPROM.read(0);  
  Serial.println(value);*/
}

void loop() {
  if (Serial.available() > 0) {
    ser = Serial.read();
    //Serial.println(ser);
    if ((ser == '0') || (ser == '1') || (ser == '2') || (ser == '3') || (ser == '4') || (ser == '5') || (ser == '6') || (ser == '7') || (ser == '8') || (ser == '9')) {
      if (ser == '0') { ser2 = 0; }
      if (ser == '1') { ser2 = 1; }
      if (ser == '2') { ser2 = 2; }
      if (ser == '3') { ser2 = 3; }
      if (ser == '4') { ser2 = 4; }
      if (ser == '5') { ser2 = 5; }
      if (ser == '6') { ser2 = 6; }
      if (ser == '7') { ser2 = 7; }
      if (ser == '8') { ser2 = 8; }
      if (ser == '9') { ser2 = 9; }
      EEPROM.put(i, ser2);
      ser2 = EEPROM.read(i);
      Serial.println(ser2); // +" "+(EEPROM.read(i))+2
      //Serial.println(ser2 + 1);
    }
    /*else { 
      ser2 = 11;
      EEPROM.put(i, ser);
      Serial.println(EEPROM.read(i));
    }*/
    i++;
  }
  Serial.println(digitalRead(3));
  delay(100);
}
