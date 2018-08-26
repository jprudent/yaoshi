#include <Arduino.h>

/* 
test individual pin
modify the TEST_PIN and connect a led to the pin
the led should be blinking 5 times and the lighted up
*/


#define TEST_PIN A3

void setup() {
    delay(2000);
    pinMode(TEST_PIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
    if (i < max_blinks)
    {
        digitalWrite(TEST_PIN, LOW);
        delay(500);
        digitalWrite(TEST_PIN, HIGH);
        delay(500);
        i++;
    }
    else if (i == max_blinks) {
      digitalWrite(TEST_PIN, HIGH);
    }
}