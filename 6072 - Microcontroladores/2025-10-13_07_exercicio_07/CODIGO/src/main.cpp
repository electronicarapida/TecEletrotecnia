#include <Arduino.h>

typedef struct Temporizador
{
  long tempo_anterior;
  long intervalo;
};

Temporizador temporizador1, temporizador2;

typedef struct Rele
{
    int estado_do_rele;
    int periferico_do_rele;
};

Rele rele1;

void setup()
{
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    temporizador1.tempo_anterior = 0;
    temporizador1.intervalo = 5000;
    temporizador2.intervalo = 10000;
}

void loop()
{
    if(millis() - temporizador1.tempo_anterior >= temporizador1.intervalo)
    {
        Serial.println("Relé 1 ligado");
        temporizador1.tempo_anterior = millis();
        digitalWrite(2, HIGH);
    }
    if(millis() - temporizador1.tempo_anterior >= temporizador2.intervalo)
    {
        Serial.println("Relé 2 ligado");
        temporizador2.tempo_anterior = millis();
        digitalWrite(3, HIGH);
    }
}