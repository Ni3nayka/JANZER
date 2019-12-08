// подключение библиотек SPI и SD:
#include <SPI.h>
#include <SD.h>
File F; 
void setup(){
  Serial.begin(9600); 
  while(!Serial){;} 
  if(!SD.begin(10)){ Serial.println("SD-card not found"); return; }
  if(SD.exists("BAB.txt")){ //проверяем наличие файла "iarduino.txt" на SD-карте // если файл с именем "iarduino.txt" существует
    Serial.println("file exists");
  }
  else {
    Serial.println("file doesn't exist");
  } 
  F = SD.open("BAB.txt", FILE_WRITE);    // если файла с именем "____.txt" - нет, то он будет создан.
  if(F){  // если файл доступен (открыт для записи), то ...
    Serial.println("file is opened");
    F.println("Hello,");
    F.println("Polinaria");
    F.println();
    F.println(":D");
    F.close();
  }
  else {
    Serial.println("file is not opened");
  }
}
void loop(){
}
