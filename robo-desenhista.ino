/*
 * Versão inicial baseada em http://www.instructables.com/id/Arduino-Drawing-Robot/
 * Adaptado por Monica Rizzolli e João Adriano Freitas.
*/

#include "desenho.h"
#include "helper_functions.h"

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  setupEngines();
}

void loop() {
  Serial.println("loop");

  teste();

//  desenho();

  delay(5000);
}

