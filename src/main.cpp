#include <Arduino.h>
#include "hardware.h"
#include <LiquidCrystal.h>
#include "Display.h"
#include "AlphabetNavigator.h"
#include "Joystick.h"

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


LiquidCrystal * lcd = init_lcd();
Display display = Display(lcd, LCD_NB_ROWS, LCD_NB_COLS);

Keys * alpha = new Keys("abcdefghijklmnopqrstuvwxyz", 26);
Keys ** keys = new Keys*[1] {alpha};
AlphabetNavigator alphabetNavigator = AlphabetNavigator(keys, 1);
Joystick j = Joystick(JOYSTICK_BUTTON, JOYSTICK_X_AXIS, JOYSTICK_Y_AXIS);

void button_logic() {
    if(j.getBtnPressedDuration() > 2000) {
        // compute and send hash through keyboard
        Serial.println("Validate!!");
        j.reset();
    } else if (j.getIsBtnReleased()) {
        Serial.println("Append");
        display.append(alphabetNavigator.currentLetter());
        j.reset();
    } else {
        // sampling
        // 512 = 2^9 
        // 2^9 >> 7 = 2^2 = 4 values
        int32_t x = j.getX() >> 7;
        Serial.println(x);
        const int32_t max_delay = 1000;
        const float max_value = 4.0;
        const float coeff = 1 / (abs(x) / max_value);
        int32_t ms =  coeff * max_delay;
        if (x < 0) {
            Serial.println("left");
            for(int i=0; i<(abs(x)+1); i++) {
                alphabetNavigator.left();
            }
            delay(max_delay);
        } else if (x > 0) {
            Serial.println("right");
            for(int i=0; i<(abs(x)+1); i++) {
                alphabetNavigator.right();
            }
            delay(max_delay);
        }

        if(x != 0){
            display.replace(alphabetNavigator.currentLetter());
        }
    }
    Serial.println(alphabetNavigator.currentLetter());

}

void setup() {
    display.append("salut");
}

void loop() {
    j.probe();
    button_logic();
    delay(1000);
    Serial.println("//////");
}