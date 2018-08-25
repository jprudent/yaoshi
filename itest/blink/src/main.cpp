#include <Arduino.h>

/*
The LED should blink 5 times then should be always on
*/


#define LED_BUILTIN 17

void setup() {
    delay(2000);
    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
    if (i < max_blinks)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        i++;
    }
    else if (i == max_blinks) {
      digitalWrite(LED_BUILTIN, LOW);
    }
}