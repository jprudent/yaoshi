#include "Joystick.h"
#include <Arduino.h>

Joystick::Joystick(size_t pin_btn, size_t pin_x_axis, size_t pin_y_axis) {
  this->pin_btn = pin_btn;
  this->pin_x_axis = pin_x_axis;
  this->pin_y_axis = pin_y_axis;

  this->btnPressedTime = 0;
  this->btnPressedMillis = 0;


  pinMode(this->pin_btn, INPUT_PULLUP);
  //inMode(this->pin_x_axis, INPUT);
  //pinMode(this->pin_y_axis, INPUT);
  
}

Joystick::~Joystick() {
}

long Joystick::getBtnPressedDuration() {
  return 0L;
}

bool Joystick::getIsBtnReleased() {
  return this->isBtnReleased;
}

void Joystick::reset() {
  this->x_axis = 0;
  this->isBtnReleased = false;
  this->btnPressedMillis = 0;
  this->btnPressedTime = 0;
}

int16_t Joystick::getX() {
  return this->x_axis;
}

void Joystick::probe() {
  
  const unsigned long now = millis();

  if(digitalRead(pin_btn) == LOW) { // LOW = pressed because of PULL_UP mode
    if(this->btnPressedMillis == 0) {
      this->btnPressedTime = now;
    }
    this->btnPressedMillis = now - this->btnPressedTime;
  } else if(this->btnPressedMillis != 0) {
      this->isBtnReleased = true;
      this->btnPressedMillis = 0;
      this->btnPressedTime = 0;
  }

  const uint16_t zero = 1024 / 2;
  const int16_t raw_val = analogRead(this->pin_x_axis); 
  const int16_t val = raw_val - zero;
  this->x_axis = val;
  
}