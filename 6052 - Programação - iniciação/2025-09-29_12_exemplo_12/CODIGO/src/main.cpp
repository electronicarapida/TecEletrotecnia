#include <Arduino.h>

const int BAUD_RATE = 9600;

//2º experimentar com 1º if o valor do comando que vai ser executado, experiência com 2 botões, 1 comando verdadeiro valor 0
//segundo comando verdadeiro com && e validação de botão 2 para validar o segundo if
//3º ou com nenhum botão <-------------
int opcao = 3;
int valor = 5;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  if (opcao == 3 && valor == 5) {
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
}