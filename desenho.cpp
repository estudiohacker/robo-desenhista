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

void circulo(int diametro) {
  int num_lados = 20;
  for (int count = 0; count < num_lados; count++){
    moveForward(diametro * M_PI /num_lados);
    turnRight(360 / num_lados);
  }
}

void desenho_10quadrados36graus() {
  pendown();

  int i = 0;
  while (i < 10) {
    quadrado(50);
    turnLeft(36);
    i++;
  }
  done();

  penup();
}

void desenho_7circulosconcentricos() {
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

void desenho_bandeirabrasil() {
  pendown();

  // Retângulo
  moveForward(100);
  turnRight(90);
  moveForward(70);
  turnRight(90);
  moveForward(100);
  turnRight(90);
  moveForward(70);
  turnRight(90);
  
  // Preparação para o losângo
  jumpForward(50);
  turnRight(90);
  jumpForward(15);
  turnLeft(60);

  // Losângo
  moveForward(45);
  turnRight(120);
  moveForward(45);
  turnRight(60);
  moveForward(45);
  turnRight(120);
  moveForward(45);
  turnRight(120);

  // Preparação círculo
  jumpForward(10);
  turnLeft(90);
  circulo(30);

  done();

  penup();
}

