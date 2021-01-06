#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS3231);
uint8_t D, M, Y, h, m, s, W;

void setup(){
    delay(300);
    Serial.begin(9600);
    time.begin();
}

void loop(){
    if(millis()%1000==0){
      time.gettime();                                                   // Считываем текущее время из модуля.
      D = time.day;                                                     // Получаем текущий день месяца 1-31.
      M = time.month;                                                   // Получаем текущий месяц       1-12.
      Y = time.year;                                                    // Получаем текущий год         0-99.
      h = time.Hours;                                                   // Получаем текущие часы        0-23.
      m = time.minutes;                                                 // Получаем текущие минуты      0-59.
      s = time.seconds;                                                 // Получаем текущие секунды     0-59.
      W = time.weekday;                                                 // Получаем текущий день недели 0-6. Sun Mon Tue Wed Thu Fri Sat
      Serial.println((String) D+"-"+M+"-"+Y+", "+h+":"+m+":"+s+", "+W); // Выводим время в монитор, одной строкой
      Serial.println(s);
      delay(1);                                                         // Приостанавливаем скетч на 1 мс, чтоб не выводить время несколько раз за 1мс.
    }
}
