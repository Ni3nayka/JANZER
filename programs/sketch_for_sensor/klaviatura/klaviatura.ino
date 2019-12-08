int PinOut[4] {5, 4, 3, 2}; // пины выходы
int PinIn[4] {9, 8, 7, 6}; // пины входа
char klav = 0;
byte flag = 0;
const char value[4][4] {
  { '1', '4', '7', '*' },
  { '2', '5', '8', '0' },
  { '3', '6', '9', '#' },
  { 'A', 'B', 'C', 'D' }
};

void setup()
{
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, INPUT );
  pinMode (7, INPUT );
  pinMode (8, INPUT );
  pinMode (9, INPUT );
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);

  Serial.begin(112500);
}

void matrix ()
{
  flag = 0;
  while (flag == 0) {
    for (int rad1 = 1; rad1 <= 4; rad1++) {
      digitalWrite(PinOut[rad1 - 1], LOW);
      for (int rad2 = 1; rad2 <= 4; rad2++) {
        if ((digitalRead(PinIn[rad2 - 1]) == LOW) && (klav != value[rad1 - 1][rad2 - 1])) {
          klav = value[rad1 - 1][rad2 - 1];
          flag++;
        }
        else {
          if ((digitalRead(PinIn[rad2 - 1]) == HIGH) && (klav == value[rad1 - 1][rad2 - 1])) {
            klav = 0;
          }
        }
        delay(1);
      }
      digitalWrite(PinOut[rad1 - 1], HIGH);
    }
  }
  flag = 0;
}

void loop() {
  matrix();
  Serial.println(klav);
}
