#include <Arduino.h>
#include "hardware.h"
#include <LiquidCrystal.h>
#include "Display.h"
#include "AlphabetNavigator.h"

// global vars

// Hardware initialization
LiquidCrystal * init_lcd() {
  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_ENABLE, OUTPUT);
  pinMode(LCD_D4, OUTPUT);
  pinMode(LCD_D5, OUTPUT);
  pinMode(LCD_D6, OUTPUT);
  pinMode(LCD_D7, OUTPUT);
  LiquidCrystal * lcd = new LiquidCrystal(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
  lcd->begin(16, 2);
  lcd->println("<<** YaoShi **>>");
  return lcd;
}

void setup() {
   LiquidCrystal * lcd = init_lcd();
   Display * display = new Display(lcd, LCD_NB_ROWS, LCD_NB_COLS);

   Keys * alpha = new Keys("abcdefghijklmnopqrstuvwxyz", 26);
   Keys ** keys = new Keys*[1] {alpha};
   AlphabetNavigator alphabetNavigator = AlphabetNavigator(keys, 1);
}

void loop() {}