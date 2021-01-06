int val = 0;
int i = 0;
void setup() {
  Serial.begin(9600); 
}

void loop() {
  if( Serial.available() > 0 ) {
    val = Serial.read();
    //Serial.print("I received: ");
    //Serial.write(val);
    if (val == '-') { i = -1; }
    else { i = val; }
    Serial.println();
    Serial.println(i*2);
    Serial.println();
  }
}


