#include <Arduino.h>

void setup ()
{
  pinMode(2, INPUT),
  pinMode(3, INPUT),
  pinMode(4, INPUT),
  pinMode(11,OUTPUT),
  pinMode(12,OUTPUT),
  pinMode(13,OUTPUT);
}

void loop ()
{
  
  if (digitalRead(2)==HIGH)
  {
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(13, HIGH);
  }
  
  if (digitalRead(3)==HIGH)
  {
    digitalWrite(12, LOW);
  }
  else
  {
    digitalWrite(12, HIGH);
  }
  
  if (digitalRead(4)==HIGH)
  {
    digitalWrite(11, LOW);
  }
  else
  {
    digitalWrite(11, HIGH);
  }
}