#define PIN 13
boolean position = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  attachInterrupt(0, deistvie, RISING); // attachInterrupt(порт прерывания, выполняемая подпрограмма, условие прерывания);
  /*
  порт прерывания:
    arduino UNO:
      0 - 2 pin;
      1 - 3 pin;
    arduino MEGA:
      0 - 2  pin;
      1 - 3  pin;
      2 - 21 pin;
      3 - 20 pin;
      4 - 19 pin;
      5 - 18 pin;
  условие прерывания:
    LOW      – выполняется по низкому уровню сигнала, когда на контакте нулевое значение. Прерывание может циклично повторяться – например, при нажатой кнопке;
    CHANGE   – по фронту, прерывание происходит при изменении сигнала с высокого на низкий или наоборот. Выполняется один раз при любой смене сигнала;
    RISING   – выполнение прерывания один раз при изменении сигнала от LOW к HIGH;
    FALLING  – выполнение прерывания один раз при изменении сигнала от HIGH к LOW.
  */
}

void loop() {
  
}

void deistvie() {
  //position != position;
  if (position == 0) position = 1;
  else position = 0;
  digitalWrite(PIN, position); 
}
