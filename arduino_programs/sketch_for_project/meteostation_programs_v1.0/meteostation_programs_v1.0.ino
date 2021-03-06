#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS3231);
int D, M, Y, h, m, s, W;
/*    time.gettime("d-m-Y, H:i:s, D")
     *****
      time.gettime();                                                   // Считываем текущее время из модуля.
      D = time.day;                                                     // Получаем текущий день месяца 1-31.
      M = time.month;                                                   // Получаем текущий месяц       1-12.
      Y = time.year;                                                    // Получаем текущий год         0-99.
      h = time.Hours;                                                   // Получаем текущие часы        0-23.
      m = time.minutes;                                                 // Получаем текущие минуты      0-59.
      s = time.seconds;                                                 // Получаем текущие секунды     0-59.
      W = time.weekday;                                                 // Получаем текущий день недели 0-6. Sun Mon Tue Wed Thu Fri Sat*/
#include <SPI.h>
#include <SD.h>
File file; 
int geiger = 0;
long int time_geiger = 0;
int i = 0;
boolean kartochka = 0;
#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(8, 9); // RX, TX

void setup() {
  Serial.begin(9600); 
  SoftSerial.begin(9600);
  delay(100);
  Serial.println();
  Serial.println("==============================");
  time.begin();
  while(!Serial){;} 
  if(!SD.begin(10)){ Serial.println("ERROR: SD-card"); }
  else { Serial.println("successfull: SD-card"); }
  file = SD.open("DATA.txt", FILE_WRITE);    // если файла с именем "____.txt" - нет, то он будет создан.
  if(file){  // если файл доступен (открыт для записи), то ...
    Serial.println("successfull: file is opened");
    kartochka = 1;
  }
  else {
    Serial.println("ERROR: file is not opened");
  }
  file.println();
  vivodln("==============================");
  vivodln("START ARDUINO");
  vivod("real time: ");
  vivodln(time.gettime("d-m-Y, H:i:s, D"));
  vivodln("==============================");
  if(file){ file.close(); Serial.println("successfull: file is close"); } 
  Serial.println("==============================");
  attachInterrupt(0, s_geiger, RISING);
}

void loop() {
  if (time_geiger + 2000 < millis()) {
    int Geiger = geiger;
    if(!SD.begin(10)){ Serial.println("ERROR: SD-card"); kartochka = 0; }
    else { 
      Serial.println("successfull: SD-card"); 
      file = SD.open("DATA.txt", FILE_WRITE);
      if(file){  // если файл доступен (открыт для записи), то ...
        Serial.println("successfull: file is opened");
        if (kartochka == 0) {
          vivodln("==============================");
          vivodln("CONNECT SD CARD WITH ARDUINO");
          vivodln("==============================");
        }
        kartochka = 1;
      }
      else {
        Serial.println("ERROR: file is not opened");
        kartochka = 0;
      }
    }
    vivod("real time: ");
    vivodln(time.gettime("d-m-Y, H:i:s, D"));
    vivod("system time: ");
    vivodlni(millis());
    gps();
    vivod("zivert: ");
    vivodlni(Geiger);
    file.println("------------------------------");
    if(file){ file.close(); Serial.println("successfull: file is close"); }
    Serial.println("------------------------------");
    geiger = 0;
    time_geiger = millis();
  }
}

void gps() {
  byte f = 0;
  long int time_gps = millis();
  char F;
  /*while (f == 0) {
    
  }*/
  vivodln("gps:");
  while (f < 2) {
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
      //Serial.print(F);
      vivod(F);
      time_gps = millis();
      f = 0;
    }
    if ((millis() > time_gps + 400) && ((f == 0) || (f == 1))) {
      //Serial.println();
      vivodln();
      f++;
      time_gps = millis();
    }
  }
}

void s_geiger() {
  geiger++;
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
