#include <Arduino.h>
/*
exercício 1
criar um rele
eletrônica do rele a ligar de 5 em 5 segundos utilizando a estrutura
exercício 2
colocar dois reles
um vai ligar de 5 em 5 e outro de 10 em 10

Composição - chamar uma variável de uma estrutura dentro de outra estrutura
*/

int BAUD_RATE = 9600;

typedef struct Temporizador
{
  unsigned long tempo_anterior;
  unsigned long intervalo;
};

typedef struct Sensor_Temperatura
{
  int valor;
  int periferico;

  Temporizador temporizador;
};

Sensor_Temperatura sensor1;

typedef struct Rele
{
  int estado;
  int periferico;

  Temporizador temporizador;
};

Rele rele1;
Rele rele2;
Rele rele3;

void setup() {
  Serial.begin(BAUD_RATE);
  rele1.temporizador.tempo_anterior = 0;
  rele1.temporizador.intervalo = 5000;
  rele1.periferico = 2;
  pinMode(rele1.periferico, OUTPUT);
}

void loop() {
  if (millis() - rele1.temporizador.tempo_anterior == rele1.temporizador.intervalo)
  {
    //if (digitalRead(rele1.periferico))
    //{
    digitalWrite(rele1.periferico, HIGH);
    rele1.temporizador.tempo_anterior = millis();
    Serial.print("Rele ligado.");
  }
  else
  {
    digitalWrite(rele1.periferico, LOW);
    rele1.temporizador.tempo_anterior = millis();
    Serial.print("Rele desligado.");
  }
}

//terminar este