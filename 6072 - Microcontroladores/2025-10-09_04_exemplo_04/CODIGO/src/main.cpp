#include <Arduino.h>
//agora só quando carregar no botão é que ele começa a ligar
/*
início
V
leitura do millis
V
tempo_anterior = 0;
V
  SE
  digitalRead(periferico_2) == LOW
  SE SIM
    SE
    tempo_atual - tempo_anterior > 2000
    SE SIM

    SE NÃO
  SE NÃO
volta ao início do SE
V
executar uma ação
V
atualiza o tempo anterior
*/

int BAUD_RATE = 9600;

int periferico = 6;
int periferico_2 = 8;

unsigned long int tempo_atual = 0;
unsigned long int tempo_anterior = 0;

int comecar_contagem = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(periferico, INPUT);
  pinMode(periferico, OUTPUT);
  pinMode(periferico_2, OUTPUT);
}

void loop() { 
  if (digitalRead(periferico) == LOW) {
    digitalWrite(periferico_2, HIGH);
    comecar_contagem = 1;
    tempo_atual = millis();
    if (comecar_contagem) {
      if (tempo_atual - tempo_anterior > 2000) {
        Serial.print("Tempo atual - ");
        Serial.println(tempo_atual);
        Serial.print("Tempo anterior - ");
        Serial.println(tempo_anterior);

        digitalWrite(periferico, HIGH);
        
        tempo_anterior = millis();
      }
    }
   //agora declaro de novo a variável comecar_contagem, uso um if para validar como verdadeiro, crio um novo temporizador e desligo
   //o led passados 10 segundoss
  }
  delay(100);
}