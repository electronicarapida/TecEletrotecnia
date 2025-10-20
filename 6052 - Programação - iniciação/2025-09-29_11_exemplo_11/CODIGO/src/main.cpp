#include <Arduino.h>

const int BAUD_RATE = 9600;

//2º experimentar com 1º if o valor do comando que vai ser executado, experiência com 2 botões, 1 comando verdadeiro valor 0
//segundo comando verdadeiro com && e validação de botão 2 para validar o segundo if
int opcao = 3;
int BOTAO_ESQUERDA = 4;
int BOTAO_DIREITA = 6;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(BOTAO_ESQUERDA, INPUT);
  pinMode(BOTAO_DIREITA, INPUT);
}

void loop() {
  if (opcao == 3 && digitalRead(BOTAO_ESQUERDA) == LOW && digitalRead(BOTAO_DIREITA) == LOW) {
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