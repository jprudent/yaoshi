#include <Arduino.h>
#include "Keyboard.h"

/*
Place the cursor somewhere you can type things with keyboard.
It should input "AZERTY"
*/
void setup() {
  Keyboard.begin();
}

bool done = false;
void loop() {
  delay(2000);
  if (!done) {
     Keyboard.print("AZERTY");
  }
  done = true;
}