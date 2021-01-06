#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(8, 9);
char f[400];
int i = 0;
byte gps_flag = 0;
byte gps_flag2 = 0;
byte fs = 0;  // $
byte fz = 0;  // ,
byte ft = 0;  // .
byte sp = 0;  // satellites - спутники

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  while (i < 100) { f[i] = 0; i++; } i = 0;
  delay(100);
}

void loop() {
  gps();
  i = 0;
 // Serial.println();
  while (f[i] != 0) {
    Serial.print(f[i]);
    f[i] = 0;
    i++;
  }
  i = 0;
  Serial.println("----------------------------------");
}

void gps() {
  char F = 0;
  byte fl = 0;
  long int time_gps = millis();
  gps_flag = 1; //                      <=================================
  gps_flag2 = 1;
  fs = 0;  // $
  fz = 0;  // ,
  ft = 0;  // .
  sp = 0;  // спутники
  //vivodln("gps:");
  while ((fl < 2) && (time_gps + 2000 > millis())) {   // проверка на неполные первые входные данные
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
      //Serial.print(F);
      time_gps = millis();
      fl = 1;
    }
    if ((millis() > time_gps + 100) && (fl == 1)) {
      //Serial.println();
      fl++;
      time_gps = millis();
    }
  }
  fl = 0;
  time_gps = millis();
  while ((fl < 2) && (time_gps + 2000 > millis())) {
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
      gps_mozg(F);  //                    <=================================
      f[i] = F; i++;  // отладка 
      //Serial.print(F);
      //if(file){ file.print(F); }
      time_gps = millis();
      fl = 1;
    }
    if ((millis() > time_gps + 100) && (fl == 1)) {
      //Serial.println();
      fl++;
      time_gps = millis();
    }
  }
  if (gps_flag == 1) { Serial.println("ERROR: gps"); }
}

void gps_mozg(char c) {
  if ((fs == 0)) { Serial.print("gps coordinates: "); }
  if (c == '$') { fs++; ft = 0; fz = 0; }
  else if (c == '.') { ft++; }
  else if (c == ',') { fz++; }
  else if (fs == 1) {  // определяем gps координаты  
    if ((fs == 1) && ((fz == 2) || (fz == 4))) {  // ((fz == 1) && (ft == 0)) || 
      //if (gps_flag != 9) { Serial.print(c); }
      Serial.print(c);
      if ((gps_flag == 2) || (gps_flag == 12)) { Serial.print('.'); } 
      gps_flag++;
    }
    else if ((gps_flag == 9) || (gps_flag == 19)) { Serial.print("; "); gps_flag++; }
  }
  else if (fs == 3 + sp) {
    if ((sp == 0) && (fz == 1)) {  // определяем кол-во спутников  && (gps_flag == 20)
      //gps_flag++;
      if (gps_flag != 20) {  // т.е. он не определил gps координаты
        Serial.print("xxx; xxx; ");
      }
      Serial.println();
      Serial.print("gps satellites: ");
      gps_flag = 21;
      Serial.print(c);
      //Serial.println(";");
      if      (c == '1') { sp = 1; }
      else if (c == '2') { sp = 2; }
      else if (c == '3') { sp = 3; }
      else if (c == '4') { sp = 4; }
      else if (c == '5') { sp = 5; }
      else if (c == '6') { sp = 6; }
    }
    else if ((sp > 0) && (((fz == 1) && (ft == 0)) || (fz == 9))) {  // определяем время и дату
      Serial.print(c);
      gps_flag++; 
    }
    if ((gps_flag == 21) || (gps_flag == 30) || (gps_flag == 39)) { //  || (gps_flag == 19) 
      Serial.println("; "); 
      if (gps_flag == 21) { 
        //Serial.println();
        Serial.print("gps time: ");
      }
      if (gps_flag == 30) { 
        //Serial.println();
        Serial.print("gps date: ");
      }
      gps_flag++; 
    }
    else if ((gps_flag == 24) || (gps_flag == 27)) { Serial.print(":"); gps_flag++; }
    else if ((gps_flag == 33) || (gps_flag == 36)) { Serial.print("."); gps_flag++; }
  }
}
