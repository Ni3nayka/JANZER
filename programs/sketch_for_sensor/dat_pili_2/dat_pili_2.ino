#define DUST_ILED 7
#define DUST_PIN 0
#define NO_DUST_VOLT 0//.9
 
void setup() {
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, HIGH);
  delayMicroseconds(280);
  int outVolt = analogRead(DUST_PIN);
  digitalWrite(7, LOW);
  int calcVoltage = (outVolt * 5.0 / 1024.0 - NO_DUST_VOLT)*100;
  Serial.println(calcVoltage);
  delay(1000);
}
