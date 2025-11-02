//objetivo: 4 botões que vão ligar 4 relays por um array
//algortimo não precisa de ser replicado para 100 botões
/*
#include <Arduino.h>

int BAUD_RATE = 9600;

typedef struct Temporizador {
  unsigned long tempo_anterior;
  unsigned long intervalo;
};

typedef struct Rele {
  int estado;
  int periferico;
  Temporizador temporizador;
};

Rele reles[4];

typedef struct Botao {
  int estado;
  int periferico;
};

Botao botoes[4];

int pinosRele[4] = {4, 6, 8, 10};

int rele_atual = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  for (int i = 0; i < 4; i++) {
    reles[i].temporizador.tempo_anterior = 0;
    reles[i].temporizador.intervalo = 5000;
    reles[i].periferico = pinosRele[i];
    reles[i].estado = LOW;
    
    pinMode(reles[i].periferico, OUTPUT);
    digitalWrite(reles[i].periferico, reles[i].estado);   
  }

  reles[rele_atual].estado = HIGH;
  digitalWrite(reles[rele_atual].periferico, HIGH);
  reles[rele_atual].temporizador.tempo_anterior = millis();
}

void loop() {
/*
  if (millis() - reles[0].temporizador.tempo_anterior >= reles[0].temporizador.intervalo)
  {
    //if (digitalRead(rele1.periferico))
    //{
    digitalWrite(reles[1].periferico, HIGH);
    reles[0].temporizador.tempo_anterior = millis();
    Serial.print("Rele ligado.");
  }
  else
  {
    digitalWrite(reles[1].periferico, LOW);
    reles[1].temporizador.tempo_anterior = millis();
    Serial.print("Rele desligado.");
  }
}
*/

#include <Arduino.h>

int BAUD_RATE = 9600;

typedef struct Temporizador {
  unsigned long tempo_anterior;
  unsigned long intervalo;
};

typedef struct Rele {
  int estado;
  int periferico;
  Temporizador temporizador;
};

Rele reles[2];

typedef struct Botao {
  int estado;
  int periferico;
};

Botao botoes[2];

void setup() {
  Serial.begin(BAUD_RATE);
  reles[2].periferico = 2;
  reles[2].estado = 0;
  pinMode(botoes[0].periferico, OUTPUT);

  Serial.begin(BAUD_RATE);
  reles[2].periferico = 2;
  reles[2].estado = 0;
  pinMode(botoes[0].periferico, INPUT);
}

void loop() {
  botoes[1].estado = !digitalRead(botoes[1].periferico);
  Serial.println("b1 - ");
  Serial.println(botoes[1].estado);

  if(botoes[0].estado) {
    if(digitalRead(reles[0].periferico)) {
      //ligar rele
    }
  }
}
