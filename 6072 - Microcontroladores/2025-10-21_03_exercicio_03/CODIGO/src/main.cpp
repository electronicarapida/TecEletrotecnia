#include <Arduino.h>

int BAUD_RATE = 9600;

int rele = 6;
int ativo = 8;

void setup ()
{
  Serial.begin(BAUD_RATE);
  pinMode(rele, OUTPUT);
  pinMode(ativo, INPUT_PULLUP); // switch é ativo com comutação ao gnd
}

void loop ()
{
  if (digitalRead(ativo) == LOW) {
    Serial.println("Contactor ligado");
    delay(1000);
    digitalWrite(rele, LOW);
  } else {
    Serial.println("Contactor desligado");
    digitalWrite(rele, HIGH);
    delay(1000);
  }
}