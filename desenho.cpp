#include <math.h>
#include "desenho.h"
#include "comandos_basicos.h"
#include "helper_functions.h"

void teste() {
  pendown();

  moveForward(100);
  turnRight(90);
  turnLeft(90);
  moveBackward(100);
  done();

  penup();
}

void quadrado(int tamanho) {
  moveForward(tamanho);
  turnLeft(90);
  moveForward(tamanho);
  turnLeft(90);
  moveForward(tamanho);
  turnLeft(90);
  moveForward(tamanho);
  turnLeft(90);
}

void desenho() {
  pendown();

  int i = 0;
  while (i < 10) {
    quadrado(50);
    turnLeft(36);
    i++;
  }
//
//  int i = 0;
//  while (i < 10) {
//    moveForward(random(0, 50));
//    turnLeft(random(0, 180));
//    moveBackward(random(0, 50));
//    turnRight(random(0, 180));
//    i++;
//  };
  done();

  penup();
}

