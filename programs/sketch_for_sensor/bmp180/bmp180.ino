#include <Wire.h>   // для подключения I2C (пины A4 A5)
#include <BMP085.h> // для работы с датчиком
 
BMP085 dps = BMP085();    
 
long Temperature = 0, Pressure = 0;
 
void setup()
{ 
  Serial.begin(9600); // вывод в Serial Monitor
  Wire.begin(); 
  delay(1000);
  dps.init();  
}          
 
void loop() 
{
  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
 
  Serial.print("Атмосферное давление (мм.рт ст): "); 
  Serial.print(Pressure/133.3);
  Serial.print("\tТемпература: ");
  Serial.print(Temperature*0.1);   // Температуру по Цельсию
  Serial.println(" °C");
  delay(2000); 
}
