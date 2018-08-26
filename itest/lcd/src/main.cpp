#include <Arduino.h>
#include <LiquidCrystal.h>

/*
"hello, world" should be printed
the cursor should blink for 3 seconds, then no blinking, ...
*/

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

// MICRO LCD BINDING :
const int rs = 7, e = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// MINI LCD BINDING
//const int rs = 4, e = 9, d4 = 8, d5 = 7, d6 = 6, d7 = 5;

// UNO LCD BINDING
//const int rs = 8, e = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  delay(2000);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.noBlink();
  delay(3000);
  // Turn on the blinking cursor:
  lcd.blink();
  // print the number of seconds since reset:
  lcd.print("hello, world!");
  delay(3000);
}