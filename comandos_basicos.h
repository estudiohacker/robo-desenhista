/* 
 *  As funções disponibilizadas aqui são para compatibilidade com
 *  a hora do código.
 *  https://studio.code.org/s/frozen/stage/1/puzzle/1
 */

#pragma once

#include "helper_functions.h"

typedef int var; // handles JavaScript var type

void moveForward(float distance) {
  forward(distance);
}

void moveBackward(float distance) {
  backward(distance);
}

void turnLeft(float degrees) {
  left(degrees);
}

void turnRight(float degrees) {
  right(degrees);
}

void jumpForward(float distance) {
  penup();
  moveForward(distance);
  pendown();
}

void jumpBackward(float distance) {
  penup();
  moveBackward(distance);
  pendown();
}

