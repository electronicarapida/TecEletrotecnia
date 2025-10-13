#include <Arduino.h>

int per = 9;
int per_2 = 8;

int tempo = 1000;

void setup()
{
    pinMode(per, OUTPUT);
    pinMode(per_2, OUTPUT);
}

void loop()
{
    digitalWrite(per, HIGH);
    delay(tempo);
    digitalWrite(per, LOW);

    digitalWrite(per_2, HIGH);
    delay(tempo);
    digitalWrite(per_2, LOW);
}