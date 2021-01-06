int rast[10];
int i = 0;
int j = 0;
int k = 0;

void setup() {
  Serial.begin(9600);
  while (i < 10) { rast[i]; i++; }
}

void loop() {
  Serial.println(distanse());
}

int distanse() {
  i = 0;
  while (i < 10) {
    rast[i] = analogRead(A0);
    delay(10);
    i++;
  }
  i = 0;
  while (i < 10) {
    while (j < 10) {
      if (rast[j] > rast[j+1]) {
        k = rast[j];
        rast[j+1] = rast[j];
        rast[j] = k;
      }
      j++;
    }
    j = 0;
    i++;
  }
  return(32*pow((rast[(10-1)/2-1])*0.0048828125, -1.10));
}

