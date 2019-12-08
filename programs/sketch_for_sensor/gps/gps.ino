#include <SoftwareSerial.h>
//SoftwareSerial SoftSerial(8, 9); // RX, TX
//SoftwareSerial SoftSerial(5, 6);
SoftwareSerial SoftSerial(8, 9);
char F = 0;
long int i = 0;
int f = 0;

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  //delay(1000);
  //SoftSerial.print("S");
}

void loop() {
  if (SoftSerial.available() > 0) {
    F = SoftSerial.read();
    Serial.print(F);
    i = millis();
    f = 0;
  }
  if ((millis() > i + 500) && ((f == 0) || (f == 1))) {
    Serial.println();
    f++;
    i = millis();
  }
  if (Serial.available() > 0) {
    F = Serial.read();
    SoftSerial.print(F);
  }
}
