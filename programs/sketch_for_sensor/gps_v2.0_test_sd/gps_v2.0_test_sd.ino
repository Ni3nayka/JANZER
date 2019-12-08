#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(8, 9);
//char f[400];
int i = 0;
byte gps_flag = 0;
byte gps_flag2 = 0;
byte fs = 0;  // $
byte fz = 0;  // ,
byte ft = 0;  // .
byte sp = 0;  // satellites - спутники

#include <SPI.h>
#include <SD.h>
File file; 

char c;

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  pinMode(7, OUTPUT);
  //while (i < 100) { f[i] = 0; i++; } i = 0;
  delay(100);
  while(!Serial){;} 
  if(!SD.begin(10)){ Serial.println("ERROR: SD-card"); }
  else { Serial.println("successfull: SD-card"); }
  file = SD.open("GPS.txt", FILE_WRITE);    // если файла с именем "____.txt" - нет, то он будет создан.
  if(file){  // если файл доступен (открыт для записи), то ...
    Serial.println("successfull: file is opened");
    //kartochka = 1;
  }
  else {
    Serial.println("ERROR: file is not opened");
  }
  file.println();
  if(file){ file.close(); Serial.println("successfull: file is close"); }
  digitalWrite(7, 0);
  //while (true) {}
}

void loop() {
  gps();
  i = 0;
 // Serial.println();
  /*while (f[i] != 0) {
    Serial.print(f[i]);
    f[i] = 0;
    i++;
  }*/
  i = 0;
  //Serial.println("----------------------------------");
}

void gps() {
  if(!SD.begin(10)){ Serial.println("ERROR: SD-card"); }
  else { Serial.println("successfull: SD-card"); }
  file = SD.open("GPS.txt", FILE_WRITE);    // если файла с именем "____.txt" - нет, то он будет создан.
  if(file){  // если файл доступен (открыт для записи), то ...
    Serial.println("successfull: file is opened");
    //kartochka = 1;
  }
  else {
    Serial.println("ERROR: file is not opened");
  }
  file.println();
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
      c = F;
      gps_mozg();  //                    <=================================
      //f[i] = F; i++;  // отладка 
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
  if (gps_flag == 1) { vivod("ERROR: gps"); digitalWrite(13, 0); }
  vivodln();
  if(file){ file.close(); Serial.println("successfull: file is close"); }
}

void gps_mozg() {
  if ((fs == 0)) { Serial.print("gps coordinates: "); file.print("gps coordinates: "); }
  if (c == '$') { fs++; ft = 0; fz = 0; }
  else if (c == '.') { ft++; }
  else if (c == ',') { fz++; }
  else if (fs == 1) {  // определяем gps координаты  
    if ((fs == 1) && ((fz == 2) || (fz == 4))) {  // ((fz == 1) && (ft == 0)) || 
      //if (gps_flag != 9) { Serial.print(c); }
      Serial.print(c); file.print(c);
      if ((gps_flag == 2) || (gps_flag == 12)) { Serial.print('.'); file.print('.'); } 
      gps_flag++;
    }
    else if ((gps_flag == 9) || (gps_flag == 19)) { Serial.print("; "); file.print("; "); gps_flag++; }
  }
  else if (fs == 3 + sp) {
    if ((sp == 0) && (fz == 1)) {  // определяем кол-во спутников  && (gps_flag == 20)
      //gps_flag++;
      if (gps_flag != 20) {  // т.е. он не определил gps координаты
        Serial.print("xxx; xxx; "); file.print("xxx; xxx; "); digitalWrite(13, 0);
      }
      else { digitalWrite(13, 1); }
      Serial.println(); file.println();
      Serial.print("gps satellites: "); file.print("gps satellites: ");
      gps_flag = 21;
      Serial.print(c); file.print(c);
      //Serial.println(";");
      if      (c == '1') { sp = 1; }
      else if (c == '2') { sp = 2; }
      else if (c == '3') { sp = 3; }
      else if (c == '4') { sp = 4; }
      else if (c == '5') { sp = 5; }
      else if (c == '6') { sp = 6; }
    }
    else if ((sp > 0) && (((fz == 1) && (ft == 0)) || (fz == 9))) {  // определяем время и дату
      Serial.print(c); file.print(c);
      gps_flag++; 
    }
    if ((gps_flag == 21) || (gps_flag == 30) || (gps_flag == 39)) { //  || (gps_flag == 19) 
      Serial.println("; "); file.println("; ");
      if (gps_flag == 21) { 
        //Serial.println();
        Serial.print("gps time: "); file.print("gps time: ");
      }
      if (gps_flag == 30) { 
        //Serial.println();
        Serial.print("gps date: "); file.print("gps date: ");
      }
      gps_flag++; 
    }
    else if ((gps_flag == 24) || (gps_flag == 27)) { Serial.print(":"); file.print(":"); gps_flag++; }
    else if ((gps_flag == 33) || (gps_flag == 36)) { Serial.print("."); file.print("."); gps_flag++; }
  }
}

void vivodi(long int S) {
  //Serial.print("file<");
  Serial.print(S);
  //Serial.print("> ");
  if(file){ file.print(S); }
}

void vivodlni(long int S) {
 // Serial.print("file<");
  Serial.println(S);
  //Serial.println("> ");
  if(file){ file.println(S); }
}

void vivod(String S) {
  //Serial.print("file<");
  Serial.print(S);
  //Serial.print("> ");
  if(file){ file.print(S); }
}

void vivodln(String S) {
  //Serial.print("file<");
  Serial.println(S);
  //Serial.println("> ");
  if(file){ file.println(S); }
}

void vivodln() {
  //Serial.print("file[endl] ");
  Serial.println();
  if(file){ file.println(); }
}
