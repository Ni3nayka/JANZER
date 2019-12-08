char str[4];
int i = 0;

void setup() {
  Serial.begin(9600);
  //Serial1.begin(9600);
  pinMode (13, OUTPUT);
}

void loop() {
  pl_1();
}

void pl_1() {
  if (Serial.available() > 0) {
    i = Serial.read();
    if (i == 'H') {
      digitalWrite(13, 1);
    }
    if (i == 'L') {
      digitalWrite(13, 0);
    }
  }
}

void pl_2() {
  Serial.print('H');
  delay(500);
  Serial.print('L');
  delay(500);
}


