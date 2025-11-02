#include <Arduino.h>
/*fazer um temporizador
criar um serial print
simular a ação
substituir as variáveis por uma estrutura
criar dois temporizador que utilizem duas vezes a estrutura*/

//agora só quando carregar no botão é que ele começa a ligar
/*
início
V
definir variável do rate do arduino como 9600
V
definir variável do tempo_atual como 0
V
definir variável do tempo_anterior como 0
V
inicializar serial com a variável do rate do arduino no monitor serial
V
inicializar o loop
V
SE
tempo_atual - tempo_anterior > 1000
SE SIM
executar uma ação de impressão da variável tempo_atual
V
executar uma ação de impressão da variável tempo_anterior
SE NÃO
volta ao início do SE
*/
/*
int BAUD_RATE = 9600;

unsigned long int tempo_atual = 0;
unsigned long int tempo_anterior = 0;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  tempo_atual = millis();
  if (tempo_atual - tempo_anterior >= 1000) {
    Serial.print("Tempo atual - ");
    Serial.println(tempo_atual);
    Serial.print("Tempo anterior - ");
    Serial.println(tempo_anterior);
  }
}
*/

int BAUD_RATE = 9600;

typedef struct sensor_temperatura
{
  int valor;
  int periferico;
  unsigned long tempo_anterior;
  unsigned long intervalo;
};

sensor_temperatura sensor1;
sensor_temperatura sensor2;
sensor_temperatura sensor3;

void setup() {
  Serial.begin(BAUD_RATE);
  sensor1.tempo_anterior = 0;
  sensor2.tempo_anterior = 0;
  sensor3.tempo_anterior = 0;
  sensor1.intervalo = 1000;
  sensor2.intervalo = 2000;
  sensor3.intervalo = 3000;
}

void loop() {

  if (millis() - sensor1.tempo_anterior >= sensor1.intervalo)
  {
    Serial.print("Tempo anterior sensor 1 - ");
    Serial.println(sensor1.tempo_anterior);
    Serial.print("Tempo intervalo sensor 1 - ");
    Serial.println(sensor1.intervalo);

    sensor1.tempo_anterior = millis();
  }
  if (millis() - sensor2.tempo_anterior >= sensor2.intervalo)
  {
    Serial.print("Tempo anterior sensor 2 - ");
    Serial.println(sensor2.tempo_anterior);
    Serial.print("Tempo intervalo sensor 2 - ");
    Serial.println(sensor2.intervalo);

    sensor2.tempo_anterior = millis();
  }
  if (millis() - sensor3.tempo_anterior >= sensor3.intervalo)
  {
    Serial.print("Tempo anterior sensor 2 - ");
    Serial.println(sensor3.tempo_anterior);
    Serial.print("Tempo intervalo sensor 2 - ");
    Serial.println(sensor3.intervalo);

    sensor3.tempo_anterior = millis();
  }
}