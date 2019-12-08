#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(8, 9);
char F = 0;
long int i = 0;
int f = 0;

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  gps();
}

void loop() {
  
}

void gps() {   // + 25.8000, 26.8350
  f = 0;
  while (f < 2) {
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
      //Serial.print(F);
      i = millis();
      f = 1;
    }
    if ((millis() > i + 100) && (f == 1)) {
      //Serial.println();
      f++;
      i = millis();
    }
  }
  f = 0;
  while (f < 2) {
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
      Serial.print(F);
      i = millis();
      f = 1;
    }
    if ((millis() > i + 100) && (f == 1)) {
      //Serial.println();
      f++;
      i = millis();
    }
  }
  Serial.println();
}
