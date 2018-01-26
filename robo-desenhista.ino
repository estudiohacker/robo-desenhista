/*
 * Versão inicial baseada em http://www.instructables.com/id/Arduino-Drawing-Robot/
 * Adaptado por Monica Rizzolli e João Adriano Freitas.
*/

#include <Servo.h>
#include "config.h"
#include "helper_functions.h"
#include "comandos_basicos.h"
#include "arte.h"

Servo penServo;

void setup() {
  Serial.begin(115200);

  for (int pin = 0; pin < 4; pin++) {
    pinMode(L_stepper_pins[pin], OUTPUT);
    digitalWrite(L_stepper_pins[pin], LOW);
    pinMode(R_stepper_pins[pin], OUTPUT);
    digitalWrite(R_stepper_pins[pin], LOW);
  }
  
  penServo.attach(servoPin);

  Serial.println("setup");
  penup();
  pendown();
  penup();
  pendown();
  penup();
}

void loop() {
  Serial.println("loop");

  teste();

  arte();

  done();
  delay(5000);
}

