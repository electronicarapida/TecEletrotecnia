#include <Arduino.h>

int BAUD_RATE = 9600;

int ativo = 6;
int rele = 8;
int botao = 10;

void setup ()
{
  Serial.begin(BAUD_RATE);
  pinMode(ativo, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop ()
{
    if (digitalRead(botao) == LOW) {
      digitalWrite(rele, LOW);
      delay(1000);
      if (digitalRead(ativo) == LOW) {
        Serial.println("Contactor ligado");
      }
    } else {
      digitalWrite(rele, HIGH);
      delay(1000);
      if (digitalRead(ativo) == HIGH) {
        Serial.println("Contactor desligado");
      }
    }
  delay(100);
}
