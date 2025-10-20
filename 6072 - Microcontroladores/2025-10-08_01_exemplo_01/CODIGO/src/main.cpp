#include <Arduino.h>
unsigned long int tempo_atual = 0; //unsigned usa os números dos bits até 65536 bits ao invés de 32767 e começa a contar do 0 e retorna sempre para o 0
//long torna o int em 2^64 bits
int BAUD_RATE = 9600;
//delay(100); --> é um temporizador "blocking"

unsigned long int tempo_anterior = 0;

int periferico = 10;

unsigned long int tempo_atual_2 = 0;
unsigned long int tempo_anterior_2 = 0;
unsigned long int periferico_2 = 12;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(periferico, INPUT);
  pinMode(periferico, OUTPUT);
  pinMode(periferico_2, INPUT);
  pinMode(periferico_2, OUTPUT);
}

void loop() {
//millis(); --Z é um temporizador "não blocking" que reotnra o valor decimal do pulso a que se encontra o microcontrolador
  tempo_atual = millis();

  if (tempo_atual - tempo_anterior > 1000) {
    Serial.print("Tempo atual - ");
    Serial.println(tempo_atual);

    Serial.print("Tempo anterior - ");
    Serial.println(tempo_anterior);

    if(digitalRead(periferico) == LOW)
    {
      digitalWrite(periferico, HIGH);
    }
    else
    {
      digitalWrite(periferico, LOW);
    }

    tempo_anterior = millis();
  }

  //temporizador 2
  tempo_atual_2 = millis();

  if (tempo_atual_2 - tempo_anterior_2 > 1000)
  {
    Serial.print("Tempo atual - ");
    Serial.println(tempo_atual_2);

    Serial.print("Tempo anterior - ");
    //retirar o texto
    Serial.println(tempo_anterior_2);

    if(digitalRead(periferico_2) == LOW)
    {
      digitalWrite(periferico_2, HIGH);
    }
    else
    {
      digitalWrite(periferico_2, LOW);
    }

    tempo_anterior_2 = millis();
  }
}
//exercicio 1 - recriar o comportamento do detetor de presenças utilizando um led tal e qual está a ser utilizado hoje, deteta, liga, passado alguns segundos desliga, volta a detetar, volta a ligar
//exercicio 2 - proposição de melhoria e simular também utilizando o botão e o led