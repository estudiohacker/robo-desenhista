#pragma once

#include <Arduino.h>

const uint8_t servoPin = 2;
const uint8_t L_stepper_pins[] = {8, 9, 10, 11};
const uint8_t R_stepper_pins[] =  {4, 5, 6, 7};

const int PEN_DOWN = 170; // angle of servo when pen is down
const int PEN_UP = 150;   // angle of servo when pen is up

const float wheel_dia = 63;   // # mm (increase = spiral out)
const float wheel_base = 117; // # mm (increase = spiral in, ccw)
const int steps_rev = 512;    // # 512 for 64x gearbox, 128 for 16x gearbox
const int delay_time = 3;     // # time between steps in ms

const int fwd_mask[][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

const int rev_mask[][4] = {
  {1, 0, 0, 1},
  {0, 0, 1, 1},
  {0, 1, 1, 0},
  {1, 1, 0, 0}
};

