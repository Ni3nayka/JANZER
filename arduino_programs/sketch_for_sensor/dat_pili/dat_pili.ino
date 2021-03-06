int measurePin = 0;
int ledPower = 7;
 
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
 
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
 
void setup(){
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}
 
void loop(){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);
 
  voMeasured = analogRead(measurePin); // read the dust value
 
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
 
  // 0 - 3.3V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (3.3 / 1024);
 
  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  
  dustDensity = 0.17 * calcVoltage - 0.1;
  //dustDensity = 0.17 * voMeasured * (3.3 / 1024) - 0.1;
  //dustDensity = 0.17 * analogRead(measurePin) * (3.3 / 1024) - 0.1;
  //dustDensity = 0.00055 * analogRead(A5) - 0.1;
 
  Serial.print("Raw Signal Value (0-1023): "); // Значение необработанного сигнала
  Serial.print(voMeasured);
 
  Serial.print(" - Voltage: ");       // вольтаж
  Serial.print(calcVoltage);
 
  Serial.print(" - Dust Density: "); // Плотность пыли  (0,25 мг / м³)
  Serial.println(dustDensity);
 
  delay(1000);
}
