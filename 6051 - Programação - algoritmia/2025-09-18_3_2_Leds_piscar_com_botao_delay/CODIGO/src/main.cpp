#include <Arduino.h>

void setup ()
{
  pinMode(2, INPUT),
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop ()
{
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  if (digitalRead(2)==LOW)
  {
    delay(10000);
  }
}