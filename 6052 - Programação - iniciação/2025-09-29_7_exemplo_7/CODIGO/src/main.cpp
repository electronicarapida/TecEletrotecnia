#include <Arduino.h>

const int BAUD_RATE = 9600;
int botao = 2;
int led = 3;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(botao, INPUT);  // Correção crucial - resistor pull-up interno
  pinMode(led, OUTPUT);
}

void loop()
{
  // Enquanto o botão estiver pressionado (LOW com pull-up)
  while(digitalRead(botao) == LOW)
  {
    // Ligar o LED
    digitalWrite(led, HIGH);
    Serial.println("Ligado");
    delay(2000);
  }
  
  // Fora do while - quando botão estiver solto
  digitalWrite(led, LOW);
  Serial.println("Desligado");
}