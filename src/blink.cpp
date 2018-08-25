#include <Arduino.h>


#define LED_BUILTIN 17
#define MODE_BLINK // make the led blink

#ifdef MODE_BLINK
void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, LOW);

  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, HIGH);

   // wait for a second
  delay(1000);
}
#endif

