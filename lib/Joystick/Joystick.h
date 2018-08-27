#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick {
  public:

    // precision in bits
    Joystick(size_t pin_btn, size_t pin_x_axis, size_t pin_y_axis);
    ~Joystick();
    long getBtnPressedDuration();
    bool getIsBtnReleased();   
    void reset();
    int16_t getX();
    void probe();

  private:
    size_t pin_btn;
    size_t pin_x_axis;
    size_t pin_y_axis;
    unsigned long btnPressedTime;
    unsigned long btnPressedMillis;
    bool isBtnReleased;
    int16_t x_axis;
};

#endif