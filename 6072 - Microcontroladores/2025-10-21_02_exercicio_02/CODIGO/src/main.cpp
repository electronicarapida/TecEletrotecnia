#include <Arduino.h>

int rele = 6;

void setup ()
{
  pinMode(rele, OUTPUT);
}

void loop ()
{
  digitalWrite(rele, HIGH);
  delay(5000);
  digitalWrite(rele, LOW);
  delay(5000);
}
