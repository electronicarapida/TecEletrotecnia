#include <Arduino.h>

int teste = 0; // 1 // 10 // -1 -> qualquer valor que não seja 0 é verdadeiro, ou valor 1, o computador testa tudo o que não é falso

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (teste) {
    Serial.println("Verdadeiro");
  }
  else {
    Serial.println("Falso");
  }
  delay(1000);
}
