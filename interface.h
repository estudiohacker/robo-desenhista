/*
 *  As funções disponibilizadas aqui são para compatibilidade com
 *  a hora do código.
 *  https://studio.code.org/s/frozen/stage/1/puzzle/1
 */

#pragma once

typedef int var; // handles JavaScript var type

// Ande para frente.
void moveForward(float distance);

// Ande para trás.
void moveBackward(float distance);

// Vire a esquerda.
void turnLeft(float degrees);

// Vire a direita.
void turnRight(float degrees);

// Ande para a frente com a caneta levantada.
void jumpForward(float distance);

// Ande para trás com a caneta levantada.
void jumpBackward(float distance);

