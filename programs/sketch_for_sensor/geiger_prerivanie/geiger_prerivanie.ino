int i = 0;
long int time = 0;

void setup() {
  attachInterrupt(0, s_geiger, RISING);
  Serial.begin(9600);
}

void loop() {
  if (time + 42000 < millis()) {
    time = millis();
    Serial.println(i);
    i = 0;
  }
}

void s_geiger() {
  i++;
}
