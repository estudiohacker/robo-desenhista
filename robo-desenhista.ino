/*
 * Versão inicial baseada em http://www.instructables.com/id/Arduino-Drawing-Robot/
 * Adaptado por Monica Rizzolli e João Adriano Freitas.
*/

#include <Servo.h>
#include "config.h"
#include "desenho.h"

Servo penServo;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  for (int pin = 0; pin < 4; pin++) {
    pinMode(L_stepper_pins[pin], OUTPUT);
    digitalWrite(L_stepper_pins[pin], LOW);
    pinMode(R_stepper_pins[pin], OUTPUT);
    digitalWrite(R_stepper_pins[pin], LOW);
  }
  
  penServo.attach(servoPin);
}

void loop() {
  Serial.println("loop");

  teste();

//  desenho();

  delay(5000);
}

