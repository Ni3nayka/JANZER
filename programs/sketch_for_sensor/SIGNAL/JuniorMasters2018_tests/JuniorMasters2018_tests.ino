//#include <LiquidCrystal.h>
//LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
//#include <TroykaDHT.h>
//DHT dht(A1, DHT11);
int k = 0;
int i = 0;
int s = 0;
int a = 0;
int t = 0;
int t_1 = 0;
float s1 = 0;
float s2 = 0;
int m = 1;

#include <OneWire.h> 
OneWire ds(17);
byte addr[8];

#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;

// занятые пины: 3, 4, 5, 6, 7, 8, 12, 10, 11, A5;

void setup() {
  //while (!Serial) ;
  //pinMode(13, OUTPUT);
  //pinMode(11, OUTPUT);
  //pinMode(10, OUTPUT);
  Serial.begin(9600);
  //dht.begin();
  //-------------------------------------------
  //pinMode(8, OUTPUT);
  //pinMode(2, OUTPUT);
  //pinMode(9, INPUT);
  //pinMode(9, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  //pinMode(6, OUTPUT);
  //pinMode(7, OUTPUT);
  //-------------------------------------------
  //lcd.begin(20, 4);
  
  //Dima();
}

void loop () {
  //Serial.println(analogRead(A0));   delay(100);
  //sys();
  //key();
  Time();
}
/*
void sys() {
  lcd.clear();
  lcd.setCursor(0, 0);
  Time();
  key();  
  dht.read();
  t = dht.getTemperatureC();
  if (((digitalRead(8)) == 1) || ((digitalRead(9)) == 1) || ((analogRead(A0)) < 100) || (t > 30) || (t_1 > 80)) {
    if (((digitalRead(8)) == 1)  || ((digitalRead(9)) == 1)) {
      lcd.print("        ");
      lcd.print("\xA8");
      lcd.print("\xA5");
      lcd.print("P");
    }
    else {
      if ((analogRead(A0)) < 100) {
        lcd.print("\xA1");
    lcd.print("e");
    lcd.print("p");
    lcd.print("\xBA");
    lcd.print("o");
    lcd.print("\xBD");
        
      }
      else {
        lcd.print("       ");
        lcd.print("\xBF");
        lcd.print("e");
        lcd.print("\xBC");
        lcd.print("\xBE");
        
      }
    }
    //------------------------------
    lcd.setCursor(0, 1);
    if (((digitalRead(8)) == 1)  || ((digitalRead(9)) == 1)) {
      if ((digitalRead(8)) == 1) {
        lcd.print("          1");
      }
      else {
        lcd.print("          2");
      }
    }
    else {
      lcd.print("1");
    //------------------------------
    lcd.setCursor(0, 1);  
    }

    //------------------------------
    if (m < 3) {
      while (i < 10) {
        tone(12, 1000);
        delay(250);
        noTone(12);
        delay(250);
        i++;
      }
      i = 0;
      tone(12, 500);
      //delay(500);
      m = 4;
    }
    
  }
  if ((m == 1) || (m == 2))  {
    noTone(12);
    lcd.print(t1);
    lcd.print(":");
    lcd.print(t2);
    lcd.print(" ");
    lcd.print(t3);
    lcd.print(".");
    lcd.print(t4);
    lcd.print(" ");
    //--------------------
    lcd.setCursor(0, 1);
    lcd.print("\xA8");
    lcd.print("\xA5");
    lcd.print("P");
    lcd.print(" 1:");
    lcd.print(digitalRead(8));
    lcd.print(" 2:");
    lcd.print(digitalRead(9));
    lcd.print(" ");
    lcd.print("\xA1");
    lcd.print("e");
    lcd.print("p");
    lcd.print("\xBA");
    lcd.print("o");
    lcd.print("\xBD");
    lcd.print(":");
    if ((analogRead(A0)) < 100 ) {
      lcd.print("1");
    } else {
      lcd.print("0");
    }
    //lcd.print(digitalRead(9));
    //-----------------------------
    lcd.setCursor(0, 2);
    t_1 = dht.getHumidity();
    lcd.print("DHT ");
    lcd.print("\xBF");
    lcd.print("e");
    lcd.print("\xBC");
    lcd.print("\xBE");
    lcd.print(":");
    lcd.print(t);
    if (t < 10) {
      lcd.print(" ");
    }
    lcd.print(" ");
    lcd.print("\xB3");
    lcd.print("\xBB");
    lcd.print("a");
    lcd.print("\xB6");
    lcd.print("\xBD");
    lcd.print(":");
    lcd.print(t_1);
    //-----------------------------
    lcd.setCursor(0, 3);
    lcd.print("O");
    lcd.print("c");
    lcd.print("\xB3");
    lcd.print("e");
    lcd.print("\xE6");
    lcd.print("\xB5");
    lcd.print("\xBD");
    lcd.print("\xBD");
    lcd.print("o");
    lcd.print("c");
    lcd.print("\xBF");
    lcd.print("\xC4");
    lcd.print(":");
    lcd.print(analogRead(A2) / 10.22);
    lcd.print("%");
    //-----------------------------
    delay(100);
    //lcd.clear();
    lcd.setCursor(0, 0);
  }
  delay(1);
}
*/
void key() {
  if ( !ds.search(addr) ) { }
  else {
    if ((addr[7] == 90) && (addr[6] == 0) && (addr[5] == 0)&& (addr[4] == 1)&& (addr[3] == 184)&& (addr[2] == 13)&& (addr[1] == 98) && (addr[0] == 1)) { m = 1; Serial.print("pol"); }
    if ((addr[7] == 107) && (addr[6] == 0) && (addr[5] == 0)&& (addr[4] == 4)&& (addr[3] == 163)&& (addr[2] == 40)&& (addr[1] == 213) && (addr[0] == 1)) { m = 2; Serial.print("mas"); }
    ds.reset_search();
    Serial.println();
  }
}

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
}
/*
void kn() {
  if (((analogRead(A5)) > 500) && ((analogRead(A5)) < 600)) {
    i = 0;
    while (((analogRead(A5)) > 500) && ((analogRead(A5)) < 600)) {
      i++;
      delay(10);
    }
  }
  if (i < 100) {
    if (a == 0) {
      a++;
      digitalWrite(9, HIGH);
    }
    else {
      a--;
      digitalWrite(9, LOW);
    }
    while (!(((analogRead(A5)) > 500) && ((analogRead(A5)) < 600))) { }
  }
  if (i > 100) {
    digitalWrite(9, HIGH);
    delay(50);
    digitalWrite(9, LOW);
    delay(50);
  }
}

void lcd123() {
  s1 = analogRead(A0) / 10.23;
  s2 = analogRead(A1) / 10.23;
  lcd.setCursor(0, 0);
  lcd.print("S1: ");
  lcd.print(s1);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("S2: ");
  lcd.print(s2);
  lcd.print("%");
  if (s1 > 75) {
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
  if (s2 > 75) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  s1 = s1 / 5;
  s2 = s2 / 5;
  lcd.setCursor(0, 2);
  while (s1 > 0.5) {
    lcd.print("\xFF");
    s1--;
  }
  lcd.setCursor(0, 3);
  while (s2 > 0.5) {
    lcd.print("\xFF");
    s2--;
  }
  delay(50);
  lcd.clear();

  //lcd.setCursor(0, 2);
}

void tem() {
  //dht.read();
  //t = dht.getTemperatureC();
  digitalWrite(2, LOW);
  if (t > 27) {
    if (i == 0) {
      lcd.print("temperature");
      i++;
    }
    tone(12, 500);
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }
  else {
    if ((digitalRead(9)) == 1) {
      if (i == 0) {
        lcd.print("dvizhenie");
        i++;
      }
      tone(12, 2000);
    }
    else {
      lcd.clear();
      noTone(12);
      if (i == 1) {
        i--;
      }
    }
  }
}

void sv_2() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

  digitalWrite(s, HIGH);
  if ((analogRead(A0)) < 256) {
    i = 1;
  }
  if (((analogRead(A0)) > 256) && ((analogRead(A0)) < 512)) {
    i = 2;
  }
  if (((analogRead(A0)) > 512) && ((analogRead(A0)) < 768)) {
    i = 3;
  }
  if (((analogRead(A0)) > 768) && ((analogRead(A0)) < 1023)) {
    i = 4;
  }
  if (i == 1) {
    if (a == 0) {
      s++;
      if (s == 9) {
        s--;
        a = 1;
      }
    }
    if (a == 1) {
      s--;
      if (s == 1) {
        s++;
        s++;
        a = 0;
      }
    }
  }
  if (i == 2) {
    if (a == 0) {
      s++;
      if (s == 8) {
        s--;
        a = 1;
      }
    }
    if (a == 1) {
      s--;
      if (s == 2) {
        s++;
        s++;
        a = 0;
      }
    }
  }
  if (i == 3) {
    if (a == 0) {
      s++;
      if (s == 7) {
        s--;
        a = 1;
      }
    }
    if (a == 1) {
      s--;
      if (s == 3) {
        s++;
        s++;
        a = 0;
      }
    }
  }
  if (i == 4) {
    if (s == 5) {
      s = 0;
    }
    else {
      s = 5;
    }
  }
  delay(100);
}

void sv() {
  if ((analogRead(A0)) < 150) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
  if (((analogRead(A0)) > 150) && ((analogRead(A0)) < 300)) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  if (((analogRead(A0)) > 300) && ((analogRead(A0)) < 450)) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (((analogRead(A0)) > 450) && ((analogRead(A0)) < 600)) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (((analogRead(A0)) > 600) && ((analogRead(A0)) < 750)) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (((analogRead(A0)) > 750) && ((analogRead(A0)) < 900)) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  if ((analogRead(A0)) > 900) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void Dima() {
  Dima_2();
  tone(12, 1000);
  delay(70);
  noTone(12);
  delay(70);
  tone(12, 1000);
  delay(70);
  noTone(12);
}
/*
void Dima_2() {
  tone(12, 1000);
  delay(70);
  noTone(12);
  lcd.setCursor(4, 1);
  lcd.print("Initializing");
  lcd.setCursor(8, 2);
  lcd.print("\xFF");
  delay(200);
  lcd.print("\xFF");
  delay(200);
  lcd.print("\xFF");
  delay(200);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Initializing");
  lcd.setCursor(8, 2);
  lcd.print("\xFF");
  delay(200);
  lcd.print("\xFF");
  delay(200);
  lcd.print("\xFF");
  delay(200);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Initializing");
  lcd.setCursor(8, 2);
  lcd.print("\xFF");
  delay(200);
  lcd.print("\xFF");
  delay(200);
  lcd.print("\xFF");
  delay(200);
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("Complete!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void knopka_test() {
  knopka();
  if (k == 1) {
    Serial.println("vverx");
    digitalWrite(13, HIGH);
    tone(12, 2000);
  }
  if (k == 2) {
    Serial.println("vniz");
    digitalWrite(13, LOW);

    tone(12, 500);
  }
  if (k == 3) {
    Serial.println("vlevo");
    //tone(12, 1000);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
  if (k == 4) {
    Serial.println("vpravo");
    //tone(12, 2000);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }
  if (k == 5) {
    Serial.println("zentr");
    //lcd.print("you win!");
    tone(12, 1000);
  }
  delay(500);
  noTone(12);
}

void zum() {
  tone(12, 500);
  delay (250);
  noTone(12);
  delay (250);
  tone(12, 2000);
  delay (250);
  noTone(12);
}

void knopka() {
  if ((analogRead(A5)) == 1023) {
    k = 0;
  }
  if (((analogRead(A5)) > 300) && ((analogRead(A5)) < 400)) {  // ВВЕРХ  378
    k = 1;
  }
  if (((analogRead(A5)) > 200) && ((analogRead(A5)) < 300)) {  // ВНИЗ   231
    k = 2;
  }
  if (((analogRead(A5)) > 600) && ((analogRead(A5)) < 700)) {  // ВЛЕВО  608
    k = 3;
  }
  if (((analogRead(A5)) > 400) && ((analogRead(A5)) < 500)) {  // ВПРАВО 479
    k = 4;
  }
  if (((analogRead(A5)) > 500) && ((analogRead(A5)) < 600)) {  // ЦЕНТР  552
    k = 5;
  }
  //||
  //Serial.println(analogRead(A5));
  //delay(100);
}*/
