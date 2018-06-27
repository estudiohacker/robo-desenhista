#pragma once

#include <Arduino.h>

// Os servos e os Wii Nunchuk piratas só funcionam juntos com essa definição habilitada.
#define RF_CONTROL

const uint8_t servoPin = 2;
const uint8_t L_stepper_pins[] = {8, 9, 10, 11};
const uint8_t R_stepper_pins[] = {4, 5, 6, 7};

// PEN_DOWN tem que ser sempre maior que PEN_UP, caso contrário 
// verificar a lógica em pendown() e penup() quando RF_CONTROL está definido.
const int PEN_DOWN = 130; // ângulo do servo quando a caneta está abaixada.
const int PEN_UP = 90;    // ângulo do servo quando a caneta está levantada.

const float wheel_dia =  66;     // diâmetro da roda em milímetros.

// separação entre as duas rodas em milímetros.
// número maior, o ângulo fica mais fechado.
const float wheel_base = 115; 
const int steps_rev = 4096;      // número de passos do step motor 28BYJ-48.

// Velocidade máxima téorica de 16.25 rpm,
// ou seja, 4096 * 16.25 = 66560 pulsos por minuto, 
// logo 1109.33 pulsos por segundo.
const int max_speed = 500;       

