/*
 * Versão inicial baseada em http://www.instructables.com/id/Arduino-Drawing-Robot/
 * Adaptado por Monica Rizzolli e João Adriano Freitas.
*/

#include <Wire.h>
#include "config.h"
#include "desenho.h"
#include "helper_functions.h"
#include "comandos_basicos.h"

// https://github.com/madhephaestus/WiiChuck
#include "src/WiiChuck/Nunchuck.h"


Nunchuck nunchuck;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  setupEngines();
  penup();

  nunchuck.begin();
  delay(100);
}

void loop() {
  static bool isPenDown = false;
  if (nunchuck.readData()) {
    
    // Informações para depuração.
    // Se eu comento a linha abaixo, a comunicação wire fica instável...
    nunchuck.printInputs();
    
    // Se o AccelZ (ou qualquer outro) estiver em 1023 quer dizer que estamos
    // com problemas na comunicação...
    if ((nunchuck.getAccelZ() == 1023) || (nunchuck.getButtonC())) {
      Serial.println("Reiniciando a comunicação...");
      Wire.end();

      // Rotina simplificada do início da comunicação com o Wii Nunchuk.
      Wire.begin();
      Wire.beginTransmission(0x52);
      Wire.write((uint8_t)0xF0);
      Wire.write((uint8_t)0x55);
      Wire.endTransmission();
      delay(1);
  
      Wire.beginTransmission(0x52);
      Wire.write((uint8_t)0xFB);
      Wire.write((uint8_t)0x00);
      Wire.endTransmission();
      delay(1);
    }
    digitalWrite(LED_BUILTIN, HIGH);

    bool isMoving = true;
    // Os valores 210 e 40 foram escolhidos pois estão perto das extremidades do joystick.
    if (nunchuck.getJoyY() > 210) {
      moveForward(1);
    } else if (nunchuck.getJoyY() < 40) {
      moveBackward(1);
    } else if (nunchuck.getJoyX() > 210) {
      turnRight(1);              
    } else if (nunchuck.getJoyX() < 40) {
      turnLeft(1);              
    } else {
      done();
      isMoving = false;
    }

    // Quando está movendo e abaixa a caneta, da problema na comunicação com o Nunchuk.
    // A parte boa é que dessa forma, podemos abaixar a caneta, por para movimentar e
    // soltar o botão que a caneta continua baixada.
    if (!isMoving) {
      if (nunchuck.getButtonZ() && (!isPenDown)) {
        isPenDown = true;
        pendown();
      }
      if (!nunchuck.getButtonZ() && (isPenDown)) {
        isPenDown = false;
        penup();
      }
    }
  } else {
    digitalWrite(LED_BUILTIN, LOW);

    delay(5000);

    randomSeed(analogRead(0));
    int sorteio = random(1, 4);
    Serial.print("Desenho sorteado: ");

    switch (sorteio) {
      case 1:
        Serial.println("10 quadrados separados por 36 graus");
        desenho_10quadrados36graus();        
        break;
      case 2:
        Serial.println("7 círculos concêntricos");
        desenho_7circulosconcentricos();        
        break;
      case 3:
        Serial.println("bandeira do brasil");
        desenho_bandeirabrasil();
        break;
      default:
        Serial.println("teste");
        teste();
    }

    while (1)    
      delay(1000);
  }  
}

