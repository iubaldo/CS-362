// 1 -Ian Ubaldo - 657982252
// 2- Lab 3 - LCD
// 3- Description - Print scrolling text to an LCD
// 4- Assumptions - LCD pins are set up identically to that in the reference
// 5- References - https://docs.arduino.cc/learn/electronics/lcd-displays
// 6- Demo - in-person demonstration 9/26/22, 11:08 am, Michael


#include <LiquidCrystal.h>

// setup LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// setup print variables
String top = "the quick brown fox jumps over the lazy dog. ";
char row2[17];
int strIdx = 0;


void setup() {
  Serial.begin(9600);

  // initialize LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}


void loop() {
  // Update top row
  String toPrint;
  if (strIdx + 16 < top.length()) // printed characters within string, don't wrap
    toPrint = top.substring(strIdx, strIdx + 16);
  else {
    int remaining = 16 - (top.length() - strIdx); // printed characters exceed end of string, wrap around
    toPrint = top.substring(strIdx) + top.substring(0, remaining);
  }
  
  // Update second row
  sprintf(row2, "      %s    ", "Ian");

  // Print to LCD
  lcd.setCursor(0, 0);
  lcd.print(toPrint); // top row
  lcd.setCursor(0, 1);
  lcd.print(row2);    // bottom row

  // Debug print statements
  // Serial.println(toPrint);

  // Update strIdx to shift to the right
  if (++strIdx >= top.length())
    strIdx = 0;

  delay(400);
}
