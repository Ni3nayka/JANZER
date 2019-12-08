#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
//char str[100];
char s = 0;
int c = 0;
int i = 0;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  /*lcd.print("Hello world!");
  lcd.setCursor(0, 1);
  lcd.print("foo bar baz");*/
}

void loop() {
  str1();
  
  /*if (Serial.available()) {
    i = Serial.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("");
    //Serial.println(Serial.read());
  }*/
}

void str1() {
  if (Serial.available() > 0) {
    s = Serial.read();
    //lcd.clear();
    //lcd.setCursor(0, 0);
    lcd.print(s);
    /*
    if (s == 'a') { lcd.print(s); }
    if (s == 'b') { lcd.print("b"); }
    if (s == 'c') { lcd.print("c"); }
    if (s == 'd') { lcd.print("d"); }
    if (s == 'e') { lcd.print("e"); }
    if (s == 'f') { lcd.print("f"); }
    if (s == 'g') { lcd.print("g"); }
    if (s == 'h') { lcd.print("h"); }
    if (s == 'i') { lcd.print("i"); }
    if (s == 'j') { lcd.print("j"); }
    if (s == 'k') { lcd.print("k"); }
    if (s == 'l') { lcd.print("l"); }
    if (s == 'm') { lcd.print("m"); }
    if (s == 'n') { lcd.print("n"); }
    if (s == 'o') { lcd.print("o"); }
    if (s == 'p') { lcd.print("p"); }
    if (s == 'q') { lcd.print("q"); }
    if (s == 'r') { lcd.print("r"); }
    if (s == 's') { lcd.print("s"); }
    if (s == 't') { lcd.print("t"); }
    if (s == 'u') { lcd.print("u"); }
    if (s == 'w') { lcd.print("w"); }
    if (s == 'v') { lcd.print("v"); }
    if (s == 'x') { lcd.print("x"); }
    if (s == 'y') { lcd.print("y"); }
    if (s == 'z') { lcd.print("z"); }
    if (s == 'A') { lcd.print("A"); }
    if (s == 'B') { lcd.print("B"); }
    if (s == 'C') { lcd.print("C"); }
    if (s == 'D') { lcd.print("D"); }
    if (s == 'E') { lcd.print("E"); }
    if (s == 'F') { lcd.print("F"); }
    if (s == 'G') { lcd.print("G"); }
    if (s == 'H') { lcd.print("H"); }
    if (s == 'I') { lcd.print("I"); }
    if (s == 'J') { lcd.print("J"); }
    if (s == 'K') { lcd.print("K"); }
    if (s == 'L') { lcd.print("L"); }
    if (s == 'M') { lcd.print("M"); }
    if (s == 'N') { lcd.print("N"); }
    if (s == 'O') { lcd.print("O"); }
    if (s == 'P') { lcd.print("P"); }
    if (s == 'Q') { lcd.print("Q"); }
    if (s == 'R') { lcd.print("R"); }
    if (s == 'S') { lcd.print("S"); }
    if (s == 'T') { lcd.print("T"); }
    if (s == 'U') { lcd.print("U"); }
    if (s == 'W') { lcd.print("W"); }
    if (s == 'V') { lcd.print("V"); }
    if (s == 'X') { lcd.print("X"); }
    if (s == 'Y') { lcd.print("Y"); }
    if (s == 'Z') { lcd.print("Z"); }
    if (s == '0') { lcd.print("0"); }
    if (s == '1') { lcd.print("1"); }
    if (s == '2') { lcd.print("2"); }
    if (s == '3') { lcd.print("3"); }
    if (s == '4') { lcd.print("4"); }
    if (s == '5') { lcd.print("5"); }
    if (s == '6') { lcd.print("6"); }
    if (s == '7') { lcd.print("7"); }
    if (s == '8') { lcd.print("8"); }
    if (s == '9') { lcd.print("9"); }   
    if (s == '@') { lcd.print("@"); }
    if (s == '#') { lcd.print("#"); }
    if (s == '$') { lcd.print("$"); }
    if (s == '%') { lcd.print("%"); }
    if (s == '^') { lcd.print("^"); }
    if (s == '&') { lcd.print("&"); }
    if (s == '*') { lcd.print("*"); }
    if (s == '(') { lcd.print("("); }
    if (s == ')') { lcd.print(")"); }
    if (s == '+') { lcd.print("+"); }
    if (s == '-') { lcd.print("-"); }
    if (s == '_') { lcd.print("_"); }
    if (s == '=') { lcd.print("="); }
    if (s == '/') { lcd.print("/"); }
    if (s == '|') { lcd.print("|"); }
    //if (s == '"') { lcd.print("""); }
    if (s == ':') { lcd.print(":"); }
    if (s == ';') { lcd.print(";"); }
    if (s == ']') { lcd.print("]"); }
    if (s == '[') { lcd.print("["); }
    if (s == '{') { lcd.print("{"); }
    if (s == '}') { lcd.print("}"); }
    if (s == '!') { lcd.print("!"); }
    if (s == '?') { lcd.print("?"); }
    if (s == ',') { lcd.print(","); }
    if (s == '.') { lcd.print("."); }
    if (s == '<') { lcd.print("<"); }
    if (s == '>') { lcd.print(">"); }
    if (s == '~') { lcd.print("~"); }
    Serial.println(s);
    //c++;  // 91
    */
  }
}
