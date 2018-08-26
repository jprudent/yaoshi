#include <Arduino.h>

/*
Print the values read on serial
Values range from 0 to 1024
Stationary value is around 512
*/

#define JOY_BUTTON 15
#define JOY_VERTICAL A1
#define JOY_HORIZONTAL A3

void setup() {
  // set up the LCD's number of columns and rows:
  delay(2000);
  
  pinMode(JOY_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
}

uint32_t h_max = 0;
uint32_t h_min = 0;

uint32_t v_max = 0;
uint32_t v_min = 0;

void loop() {
  Serial.print("Button:  ");
  Serial.print(digitalRead(JOY_BUTTON));
  Serial.print("\n");

  uint32_t h_val = analogRead(JOY_HORIZONTAL);
  h_max = max(h_val, h_max);
  h_min = min(h_val, h_min);
  Serial.print("Horizontal: ");
  Serial.print(h_min);
  Serial.print("/");
  Serial.print(h_val);
  Serial.print("/");
  Serial.print(h_max);
  Serial.print("\n");

  uint32_t v_val = analogRead(JOY_VERTICAL);
  v_max = max(v_val, v_max);
  v_min = min(v_val, v_min);
  Serial.print("Vertical: ");
  Serial.print(v_min);
  Serial.print("/");
  Serial.print(v_val);
  Serial.print("/");
  Serial.print(v_max);
  Serial.print("\n------------\n");
  delay(3000);
}