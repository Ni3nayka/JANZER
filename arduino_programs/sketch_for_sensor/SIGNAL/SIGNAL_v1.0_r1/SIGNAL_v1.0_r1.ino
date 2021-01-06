#include <EEPROM.h> 
#include <iarduino_OLED_txt.h>                
iarduino_OLED_txt myOLED(0x78);                        
extern uint8_t SmallFontRus[];      

int i = 0;
long int time = 0;

void setup(){                                         
    myOLED.begin();                            
    myOLED.setFont(SmallFontRus);
    Serial.begin(9600);
    /*myOLED.print( "0" , OLED_C, 0);
    myOLED.print( "1" , OLED_C, 1);
    myOLED.print( "4" ,      5, 4);
    myOLED.print( "6" , OLED_C, 6);*/
    //EEPROM.put(0, 1); // позиция, значение
    //EEPROM.read(i);
    Serial.println(EEPROM.read(0));
    Serial.println("Yes");
}

void loop() {
  
}

void base() {  // сбросить все
  
}

void new_password() { // новый пароль
  
}

/*
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;

void Time() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    t1 = tm.Hour;
    t2 = tm.Minute;
    t3 = tm.Day;
    t4 = tm.Month;
    t5 = tmYearToCalendar(tm.Year);
      Serial.print(t1);
      Serial.print('.');
      Serial.print(t2);
      Serial.print('.');
      Serial.print(t3);
      Serial.print('.');
      Serial.print(t4);
      Serial.print('.');
      Serial.print(t5);
      Serial.println();
  }
}*/
