//objetivo: 4 botões que vão ligar 4 relays por um array
//algortimo não precisa de ser replicado para 100 botões


#include <Arduino.h>

int BAUD_RATE = 9600;

#define NUM_RELES 4

typedef struct Temporizador {
  unsigned long tempo_anterior;
  unsigned long intervalo;
};

typedef struct Rele {
  int estado;
  int periferico;
  Temporizador temporizador;
};

typedef struct Botao {
  int estado;
  int periferico;
};

Rele reles[NUM_RELES];
Botao botoes[NUM_RELES];

int perifericos_rele[NUM_RELES] = {2, 3, 4, 5};
int perifericos_botao[NUM_RELES] = {6, 7, 8, 9};

void setup() {
  Serial.begin(BAUD_RATE);

  for (int i = 0; i < NUM_RELES; i++) {
    reles[i].periferico = perifericos_rele[i];
    reles[i].estado = LOW;
    pinMode(reles[i].periferico, OUTPUT);
    digitalWrite(reles[i].pino, LOW);

    botoes[i].pino = pinos_botao[i];
    botoes[i].estado = LOW;
    pinMode(botoes[i].pino, INPUT);
  }
}

void loop() {
  for (int i = 0; i < NUM_RELES; i++) {
    int leitura = !digitalRead(botoes[i].pino);
    if (leitura && botoes[i].estado == LOW) {
      reles[i].estado = !reles[i].estado;
      digitalWrite(reles[i].pino, reles[i].estado);
      Serial.print("Rele ");
      Serial.print(i);
      Serial.print(" -> ");
      Serial.println(reles[i].estado ? "LIGADO" : "DESLIGADO");
      delay(200);
    }
    botoes[i].estado = leitura;
  }
}
