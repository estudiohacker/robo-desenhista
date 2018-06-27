#include <math.h>
#include "interface.h"
#include "hardware.h"

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

void circulo(int diametro) {
  int num_lados = 20;
  for (int count = 0; count < num_lados; count++){
    moveForward(diametro * M_PI / num_lados);
    turnRight(360 / num_lados);
  }
}

void desenho_quadradosconcentricos() {
  pendown();

  int i = 0;
  while (i < 5) {
    quadrado(50);
    turnLeft(72);
    i++;
  }
  done();

  penup();
}

void desenho_circulosconcentricos() {
  pendown();

  int i = 0;
  while (i < 6) {
    circulo(50);
    jumpForward(50);
    turnRight(360/6);
    i++;
  }
  circulo(50);  
  done();

  penup();
}

void desenho_espiralquadrados() {
  pendown();

  moveForward(100);
  turnRight(90);
  int tamanho = 100;
  while (tamanho > 0) {
    moveForward(tamanho);
    turnRight(90);

    moveForward(tamanho);
    turnRight(90);
    tamanho = tamanho - 10;
  }
  done();

  penup();
}

void desenho_espiraltriangulos() {
  pendown();

  int tamanho = 100;
  moveForward(tamanho);
  turnRight(120);
  while (tamanho > 0) {
    moveForward(tamanho);
    turnRight(120);
    
    tamanho = tamanho - 10;
  }
  done();

  penup();
}

void desenho_espiralcirculos() {
  pendown();

  int diametro = 100;
  int num_lados = 20;
  while (diametro > 10) {
    moveForward(diametro * M_PI / num_lados);
    turnRight(360 / num_lados);
    diametro--;
  }

  done();

  penup();
}

void desenho_estrela() {
  pendown();

  int i = 0;
  while (i < 5) {
    moveForward(100);
    turnRight(144);
    i++;
  }

  done();

  penup();
}


