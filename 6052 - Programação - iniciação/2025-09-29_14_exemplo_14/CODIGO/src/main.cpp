#include <Arduino.h>

/*Instruções
variáveis das opções e leds
usar função para desligar os leds
para cada função criar uma função e ligar os casos da função*/

const int BAUD_RATE = 9600;

int opcao = 1;

int led1 = 2;
int led2 = 12;

void desled1desled2()
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}
void ligled1desled2()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
}
void desled1ligled2()
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}
void ligled1ligled2()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
}

void setup ()
{
  Serial.begin(BAUD_RATE);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop ()
{
  switch (opcao) {
    case 0:
      desled1desled2();
      break;
    case 1:
      ligled1desled2();
      break;
    case 2:
      desled1ligled2();
      break;
    case 3:
      ligled1ligled2();
      break;
    default:
      Serial.println("Erro");
      break;
  }
  delay(100);
}