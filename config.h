#pragma once

#include <Arduino.h>

const uint8_t servoPin = 2;
const uint8_t L_stepper_pins[] = {8, 9, 10, 11};
const uint8_t R_stepper_pins[] = {4, 5, 6, 7};

const int PEN_DOWN = 170; // angle of servo when pen is down
const int PEN_UP = 150;   // angle of servo when pen is up

const float wheel_dia =  60.4;   // # mm (increase = spiral out)
const float wheel_base = 115.25; // # mm (increase = spiral in, ccw)
const int steps_rev = 4096;      // Step motor 28BYJ-48
const int max_speed = 975;       // 16.25 rpm * 60s


