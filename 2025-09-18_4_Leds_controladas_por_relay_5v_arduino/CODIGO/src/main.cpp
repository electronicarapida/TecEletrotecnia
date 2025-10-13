#include <Arduino.h>

int relay = 4;

void setup ()
{
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW); // começa desligado
}

void loop ()
{
  digitalWrite(relay, HIGH); // ativa bobina → LED NO acende
  delay(1000);
  digitalWrite(relay, LOW); // desliga bobina → LED NC acende
  delay(1000);
}