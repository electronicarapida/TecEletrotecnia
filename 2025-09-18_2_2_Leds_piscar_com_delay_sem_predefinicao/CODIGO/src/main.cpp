#include <Arduino.h>

int per = 9;
int per_2 = 8;

void setup()
{
    pinMode(per, OUTPUT);
    pinMode(per_2, OUTPUT);
}

void loop()
{
    digitalWrite(per, HIGH);
    delay(5000);
    digitalWrite(per, LOW);

    digitalWrite(per_2, HIGH);
    delay(5000);
    digitalWrite(per_2, LOW);
}