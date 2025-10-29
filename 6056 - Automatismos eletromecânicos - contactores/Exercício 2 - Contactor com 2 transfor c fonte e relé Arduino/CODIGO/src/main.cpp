#include <Arduino.h>

int BAUD_RATE = 9600;

int ativo = 6;
int rele = 8;
int botao = 10;

void setup ()
{
  Serial.begin(BAUD_RATE);
  pinMode(ativo, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop ()
{
  if (digitalRead(botao) == LOW ) {
    Serial.println("Contactor ligado");
    digitalWrite(rele, LOW);
    delay(1000);
  } else {
    Serial.println("Contactor desligado");
    digitalWrite(rele, HIGH);
    delay(1000);
  }
  delay(100);
}
