#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
String top = "the quick brown fox jumps over the lazy dog. ";
char row2[17];
int strIdx = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}


void loop() {
  String toPrint;
  if (strIdx + 16 < top.length())
    toPrint = top.substring(strIdx, strIdx + 16);
  else {
    int remaining = 16 - (top.length() - strIdx);
    toPrint = top.substring(strIdx) + top.substring(0, remaining);
  }
  
  sprintf(row1, "%s", toPrint);
  sprintf(row2, "       %s      ", "Ian");
  
  lcd.setCursor(0, 0);
  lcd.print(toPrint);
  lcd.print(row2);

  Serial.println(toPrint);
  
  strIdx++;
  if (strIdx >= top.length())
    strIdx = 0;
  
  delay(400);
}
