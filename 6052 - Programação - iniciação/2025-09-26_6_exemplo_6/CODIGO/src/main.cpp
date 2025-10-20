#include <Arduino.h>

//const int pinBotao = A0;
//int valor_1 = 10;
//int valor_2 = 5;

int temperatura_lida = 10;
int temperatura_maxima = 5;
int temperatura_minima = 2;

//simulação de botões digitais
int botao_arranque_1 = 0;
int botao_arranque_2 = 0;

int sobrecarga = 10;

void setup() {
  Serial.begin(115200);
}

void loop() {
  //if (digitalRead(A0) == LOW) { //TAMBÉM SE PODE USAR OS SEGUINTES OPERADORES RELACIONAIS: == / != / > / < / >= / <=
    //Serial.println("LED ligou");
  //if (valor_1 > valor_2) {
    //Serial.println("valor 1 é maior do que o valor 2");
  if (temperatura_lida > temperatura_maxima) {
    Serial.println("Ligar ventoinha");
  }
  else {
    //Serial.println("valor 2 é maior do que o valor 1");
    Serial.println("Desligar ventoinha");
  }

  if (temperatura_lida > temperatura_minima) {
    Serial.println("Ligar esquentador");
  }
  else {
    //Serial.println("valor 2 é menor do que o valor 1");
    Serial.println("Desligar esquentador");
  }

  //simulação de botões digitais
  if (botao_arranque_1 && botao_arranque_2) {
    Serial.println("Ligar máquina");
  }
  else {
    Serial.println("Desligar máquina");
  }

  if ((temperatura_lida > temperatura_maxima) || sobrecarga) {
    Serial.println("Desligar máquina");
  }
  else {
    Serial.println("Ligar máquina");
  }
  delay(100);
}