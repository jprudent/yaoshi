#include <LiquidCrystal.h>

#include "Display.h"

void zeroes(char *s, size_t len) {
  for (size_t i = 0; i <= len; i++) {
    s[i] = '\0';
  }
}

Display::Display(LiquidCrystal * lcd, uint32_t lcd_nb_rows, uint32_t lcd_nb_cols) {
  this->lcd = lcd;
  this->lcd_nb_cols = lcd_nb_cols;
  this->lcd_nb_rows = lcd_nb_rows;

  this->lcd->cursor();
  this->lcd->blink();
  this->line1 = (char *) malloc((lcd_nb_cols + 1) * sizeof(char));
  zeroes(this->line1, lcd_nb_cols + 1);
  line1Len = 0;
}

Display::~Display() {
  free(this->lcd);
  free(this->line1);
}

void Display::append(char c) {
  this->replace(c);
  if (line1Len < lcd_nb_cols) {
    line1Len = line1Len + 1;
  }
}

void Display::append(char *s) {
  for(size_t i=0; i<strlen(s); i++) {
    this->append(s[i]);
  }
}

void Display::replace(char c) {
  this->lcd->clear();
  line1[line1Len] = c;
  this->lcd->print(line1);
  this->lcd->setCursor(line1Len, 0);
}

void Display::erase() {
  this->replace('\0');
  if (line1Len > 0) {
    line1Len = line1Len - 1;
  }
  this->replace('\0');
}

char* Display::getLine1() {
  return this->line1;
}

void Display::reset() {
  zeroes(this->line1, lcd_nb_cols + 1);
  line1Len = 0;
  this->lcd->clear();
}
