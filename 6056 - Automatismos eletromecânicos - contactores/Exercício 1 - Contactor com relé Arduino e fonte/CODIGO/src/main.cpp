#include <Arduino.h>

int botao1 = 2;
int botao2 = 4;
int rele = 6;

void setup ()
{
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(rele, OUTPUT);
}

void loop ()
{
  if (digitalRead(botao1) == LOW) {
    digitalWrite(rele, LOW);
  }
  if (digitalRead(botao2) == LOW) {
    digitalWrite(rele, HIGH);
  }
}