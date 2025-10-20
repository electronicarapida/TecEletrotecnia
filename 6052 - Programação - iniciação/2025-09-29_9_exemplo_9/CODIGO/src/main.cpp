#include <Arduino.h>

int opcao = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
 switch(opcao) {
  case 0:
   Serial.println("Temperatura alta");
   break;
  case 1:
   Serial.println("Temperatura normal");
   break;
  case 2:
   Serial.println("Temperatura media");
   break;
  case 3:
   Serial.println("Temperatura acima dos 25ºC");
   break;
  default:
   Serial.println("Opção não existe");
   break;
 }
}