#ifndef DISPLAY_H
#define DISPLAY_H

// see https://www.arduino.cc/en/Tutorial/HelloWorld?from=Tutorial.LiquidCrystal

#include <stdio.h>
#include <ctype.h>
#include <Arduino.h>
#include <LiquidCrystal.h>


class Display {
  public:
    Display(LiquidCrystal * lcd, uint32_t lcd_nb_rows, uint32_t lcd_nb_cols);
    ~Display();
    void append(char);
    void append(char *);
    void replace(char);
    void erase();
    char *getLine1();
    void reset();
  private:
    LiquidCrystal *lcd;
    uint32_t lcd_nb_rows;
    uint32_t lcd_nb_cols;
    char * line1;
    size_t line1Len;
};

#endif
