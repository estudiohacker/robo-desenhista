#include "config.h"

#include "src/AccelStepper/AccelStepper.h"
#include "src/AccelStepper/MultiStepper.h"
#ifdef RF_CONTROL
#include "src/SoftRcPulseOut/SoftRcPulseOut.h"
SoftRcPulseOut penServo;
#else
#include <Servo.h>
Servo penServo;
#endif


AccelStepper rightMotor(AccelStepper::HALF4WIRE, R_stepper_pins[0], R_stepper_pins[2], R_stepper_pins[1], R_stepper_pins[3]);
AccelStepper leftMotor(AccelStepper::HALF4WIRE, L_stepper_pins[0], L_stepper_pins[2], L_stepper_pins[1], L_stepper_pins[3]);
MultiStepper motors;

void setupEngines() {
  penServo.attach(servoPin);
  
  leftMotor.setMaxSpeed(max_speed);
  rightMotor.setMaxSpeed(max_speed);
  motors.addStepper(leftMotor);
  motors.addStepper(rightMotor);
}

int step(float distance) {
  return int(distance * steps_rev / (wheel_dia * PI));
}

float distance(float degrees) {
  return wheel_base * PI * (degrees / 360.0);
}

void move(long step_left, long step_right) {
  long steps[2];
  steps[0] = step_left;
  steps[1] = step_right;
  motors.moveTo(steps);
  motors.runSpeedToPosition();
  leftMotor.setCurrentPosition(0);
  rightMotor.setCurrentPosition(0);  
}

void forward(float distance) {
  Serial.print("↑ ");  Serial.print(distance); Serial.println("mm");
  int s = step(distance);
  move(-s, s);
}

void backward(float distance) {
  Serial.print("↓ ");  Serial.print(distance); Serial.println("mm");
  int s = step(distance);
  move(s, -s);
}

void right(float degrees) {
  Serial.print("↷ "); Serial.print(degrees); Serial.println("°");
  int s = step(distance(degrees));
  move(s, s);
}

void left(float degrees) {
  Serial.print("↶ "); Serial.print(degrees); Serial.println("°");
  int s = step(distance(degrees));
  move(-s, -s);
}

void done() { // unlock stepper to save battery
  rightMotor.disableOutputs();
  leftMotor.disableOutputs();
}

void penup() {
  Serial.println("⇞");

#ifdef RF_CONTROL
  for (int pos = PEN_DOWN; pos > PEN_UP - 15; pos -= 1) {
    penServo.write(pos);
    delay(2);
    SoftRcPulseOut::refresh();
  }   
#else    
  penServo.write(PEN_UP);
#endif
  delay(100);
}

void pendown() {
  Serial.println("⇟");

#ifdef RF_CONTROL
  for (int pos = PEN_UP; pos < PEN_DOWN + 15; pos += 1) {
    penServo.write(pos);
    delay(2);
    SoftRcPulseOut::refresh();
  }
#else    
  penServo.write(PEN_DOWN);
#endif
  delay(100);
}


