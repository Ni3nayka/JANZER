#include <avr/sleep.h>
#include <avr/power.h>
 
//int time = millis() / 1000;
int pin = 3;// для прерывания
int led = 13; // диод
int pinState = 0;
unsigned long time;
 
void setup(){
set_sleep_mode(SLEEP_MODE_IDLE); //Определяем режим сна
pinMode(pin, INPUT);
pinMode(led, OUTPUT);
 
     Serial.begin(9600);
     Serial.println(" Void setup");
     delay(300);
}
void loop(){
  pinState = digitalRead(pin);
 
    if(pinState == HIGH); {
      digitalWrite(led, HIGH);
      Serial.println("ПРОСНУЛСЯ");
      Serial.print("Прошло ");
      time = millis() / 1000;
      Serial.print(time);
      Serial.println(" сек");
      delay(5000);
      digitalWrite(led, LOW);
      Serial.println("ЗАСЫПАЮ");
    }
    delay(1000);
  EnterSleep(); //Пора спать
    
}
 
void wakeUp()
{
  Serial.println("Проснулся в wakeUp"); //Проснулись
  detachInterrupt(0); //Отключаем прерывания 
  delay(500);
}
 
void EnterSleep()
{
  attachInterrupt(0, wakeUp, RISING);
  delay(10);
 
  sleep_enable(); //Разрешаем спящий режим
  sleep_mode(); //Спим (Прерывания продолжают работать.) Программа останавливается.
  sleep_disable(); //Запрещаем спящий режим
}
