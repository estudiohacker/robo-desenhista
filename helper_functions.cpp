#include <Servo.h>
#include "config.h"

extern Servo penServo;

int step(float distance) {
  int steps = distance * steps_rev / (wheel_dia * PI); //24.61
  /*
    Serial.print(distance);
    Serial.print(" ");
    Serial.print(steps_rev);
    Serial.print(" ");
    Serial.print(wheel_dia);
    Serial.print(" ");
    Serial.println(steps);
    delay(1000);*/
  return steps;
}


void forward(float distance) {
  int steps = step(distance);
  //Serial.println(steps);
  for (int step = 0; step < steps; step++) {
    for (int mask = 0; mask < 4; mask++) {
      for (int pin = 0; pin < 4; pin++) {
        digitalWrite(L_stepper_pins[pin], rev_mask[mask][pin]);
        digitalWrite(R_stepper_pins[pin], fwd_mask[mask][pin]);
      }
      delay(delay_time);
    }
  }
}


void backward(float distance) {
  int steps = step(distance);
  for (int step = 0; step < steps; step++) {
    for (int mask = 0; mask < 4; mask++) {
      for (int pin = 0; pin < 4; pin++) {
        digitalWrite(L_stepper_pins[pin], fwd_mask[mask][pin]);
        digitalWrite(R_stepper_pins[pin], rev_mask[mask][pin]);
      }
      delay(delay_time);
    }
  }
}


void right(float degrees) {
  float rotation = degrees / 360.0;
  float distance = wheel_base * PI * rotation;
  int steps = step(distance);
  for (int step = 0; step < steps; step++) {
    for (int mask = 0; mask < 4; mask++) {
      for (int pin = 0; pin < 4; pin++) {
        digitalWrite(R_stepper_pins[pin], fwd_mask[mask][pin]);
        digitalWrite(L_stepper_pins[pin], fwd_mask[mask][pin]);
      }
      delay(delay_time);
    }
  }
}


void left(float degrees) {
  float rotation = degrees / 360.0;
  float distance = wheel_base * PI * rotation;
  int steps = step(distance);
  for (int step = 0; step < steps; step++) {
    for (int mask = 0; mask < 4; mask++) {
      for (int pin = 0; pin < 4; pin++) {
        digitalWrite(R_stepper_pins[pin], rev_mask[mask][pin]);
        digitalWrite(L_stepper_pins[pin], rev_mask[mask][pin]);
      }
      delay(delay_time);
    }
  }
}


void done() { // unlock stepper to save battery
  for (int mask = 0; mask < 4; mask++) {
    for (int pin = 0; pin < 4; pin++) {
      digitalWrite(R_stepper_pins[pin], LOW);
      digitalWrite(L_stepper_pins[pin], LOW);
    }
    delay(delay_time);
  }
}


void penup() {
  delay(100);
  Serial.println("PEN_UP()");
  penServo.write(PEN_UP);
  delay(100);
}


void pendown() {
  delay(100);
  Serial.println("PEN_DOWN()");
  penServo.write(PEN_DOWN);
  delay(100);
}


void circle(float radius, float extent, int sides) {
  // based on Python's Turtle circle implementation
  float frac = abs(extent) / 360;
  float w = 1.0 * extent / sides;
  float w2 = 0.5 * w;
  float l = 2.0 * radius * sin(w2 * PI / 180);
  if (radius < 0) {
    l = -l;
    w = -w;
    w2 = -w2;
  }
  left(w2);
  Serial.print("circle: ");
  Serial.print("frac=");
  Serial.print(frac);
  Serial.print(" sides=");
  Serial.print(sides);
  Serial.print(" l=");
  Serial.print(l);
  Serial.print(" w=");
  Serial.print(w);
  Serial.print(" w2=");
  Serial.println(w2);

  for (int i = 0; i < sides; i++) {
    forward(l);
    left(w);
  }
  right(w2);
}


void circle(float radius, float extent) {
  int sides = 1 + int(4 + abs(radius) / 12.0);
  circle(radius, extent, sides);
}


void circle(float radius) {
  circle(radius, 360);
}

