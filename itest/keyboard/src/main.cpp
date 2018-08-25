#include <Arduino.h>
#include "Keyboard.h"

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
