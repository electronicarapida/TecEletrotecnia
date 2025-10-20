#include <Arduino.h>

const int BAUD_RATE = 9600;

const int BOTAO_ESQUERDA = 4;
const int BOTAO_DIREITA = 6;
const int LED_ESQUERDA = 2;
const int LED_DIREITA = 12;

int posicao = 0;

void mostrarDisplay() {
  Serial.print("[");
  
  for (int i = 0; i <= 20; i++) {
    if (i == posicao) {
      Serial.print("O");
    } else {
      Serial.print("_");
    }
  }
  
  Serial.print("] Pos: ");
  Serial.println(posicao);
}

void piscarLEDesquerda() {
  digitalWrite(LED_ESQUERDA, HIGH);
  delay(100);
  digitalWrite(LED_ESQUERDA, LOW);
}

void piscarLEDdireita() {
  digitalWrite(LED_DIREITA, HIGH);
  delay(100);
  digitalWrite(LED_DIREITA, LOW);
}

void setup() {
  Serial.begin(BAUD_RATE);

  pinMode(BOTAO_ESQUERDA, INPUT);
  pinMode(BOTAO_DIREITA, INPUT);
  pinMode(LED_ESQUERDA, OUTPUT);
  pinMode(LED_DIREITA, OUTPUT);
  
  mostrarDisplay();
}

void loop() {
  // Botão ESQUERDA - move para a esquerda
  if (digitalRead(BOTAO_ESQUERDA) == LOW && posicao > 0) {
    posicao = posicao - 1;
    piscarLEDesquerda();
    mostrarDisplay();
    delay(500);
  }

  // Botão DIREITA - move para a direita
  if (digitalRead(BOTAO_DIREITA) == LOW && posicao < 20) {
    posicao = posicao + 1;
    piscarLEDdireita();
    mostrarDisplay();
    delay(500);
  }
}