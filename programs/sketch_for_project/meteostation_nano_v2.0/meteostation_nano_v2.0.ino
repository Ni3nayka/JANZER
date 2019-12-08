#include <Wire.h> 
#include <BMP085.h> 
BMP085 dps = BMP085();    
long Temperature = 0, Pressure = 0;

#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(8, 9); // RX, TX
byte gps_flag = 0;
byte gps_flag2 = 0;
byte fs = 0;  // $
byte fz = 0;  // ,
byte ft = 0;  // .
byte sp = 0;  // satellites - спутники

#include <SPI.h>
#include <SD.h>
File file;
char F;

float temp = 0;
float dav = 0;

long int time = 0;
int i = 0;
int u = 0;
float b = 0;
#define ras 10

float mas_t[ras];  // температура
float mas_d[ras];  // давление

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  i = 0;
  Wire.begin();
  dps.init(); 
  delay(100);
  while (i < ras) { bmp(i); i++; }
  while(!Serial){;}
}

void loop() {
  i = ras-1;
  while (i > 0) {  
    mas_t[i] = mas_t[i-1]; 
    mas_d[i] = mas_d[i-1];
    i--;
  }
  bmp(0);
  if (Serial.available() > 0) {
    F = Serial.read();
    if (F == '{')      { OPEN();   }
    else if (F == '}') { CLOSE();  }
    else if (F == '#') { zapros(); }
    else if (file)     { 
      file.print(F); 
      //Serial.print(F); 
    }
    F = 0;
  }
  //test_bmp();
}


void zapros() {
  gps();
  /*i = 0;
  temp = 0; dav = 0;
  while (i < ras) {
    temp = temp + mas_t[i];
    dav = dav + mas_d[i];
    i++;
  }
  Serial.print(temp/ras);  Serial.print(";"); 
  Serial.print(dav/ras);   Serial.print(";");*/
  bmp2();
  Serial.print(temp);  Serial.print(";"); 
  Serial.print(dav);   Serial.print(";");
  Serial.println();
}

void OPEN() {
  if(!SD.begin(10)){ Serial.println("E"); }
  else { 
    //Serial.println("S");
    file = SD.open("DATA.txt", FILE_WRITE);
    if(file) { Serial.println("S"); }
    else { Serial.println("E"); } 
  }
}

void CLOSE() {
   if (file) {
    file.close();
    //Serial.println("S");
  }
  //else { Serial.println("E"); }
}

void test_bmp() {
  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
  Serial.println(Temperature*0.1);  // Температуру по Цельсию
  Serial.println(Pressure/133.3);   // давление мм рт ст
}

void bmp2() {
  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
  temp = Temperature*0.1;  // Температуру по Цельсию
  dav  = Pressure/133.3;   // давление мм рт ст
}

void bmp(int n) {
  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
  mas_t[n] = Temperature*0.1;  // Температуру по Цельсию
  mas_d[n] = Pressure/133.3;   // давление мм рт ст
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
  //if (gps_flag == 1) { Serial.println("ERROR: gps"); }
  if (gps_flag == 1) { Serial.print("E;"); }
}

void gps_mozg(char c) {
  //if ((fs == 0)) { Serial.print("gps coordinates: "); }
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
    else if ((gps_flag == 9) || (gps_flag == 19)) { Serial.print(";"); gps_flag++; }
  }
  else if (fs == 3 + sp) {
    if ((sp == 0) && (fz == 1)) {  // определяем кол-во спутников  && (gps_flag == 20)
      //gps_flag++;
      if (gps_flag != 20) {  // т.е. он не определил gps координаты
        //Serial.print("xxx; xxx; ");
        Serial.print("x;x;");
      }
      //Serial.println();
      //Serial.print("gps satellites: ");
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
      //Serial.println("; ");
      Serial.print(";"); 
      if (gps_flag == 21) {
        //Serial.print("gps time: ");
      }
      if (gps_flag == 30) {
        //Serial.print("gps date: ");
      }
      gps_flag++; 
    }
    else if ((gps_flag == 24) || (gps_flag == 27)) { Serial.print(":"); gps_flag++; }
    else if ((gps_flag == 33) || (gps_flag == 36)) { Serial.print("."); gps_flag++; }
  }
}
