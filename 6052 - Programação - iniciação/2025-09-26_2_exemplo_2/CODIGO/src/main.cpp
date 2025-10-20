#include <Arduino.h>

const int pinBotao = 2;
const int pinLED = 13;

void setup() {
  Serial.begin(115200);
  pinMode(pinBotao, INPUT),
  pinMode(pinLED, OUTPUT);
}

void loop() {
  if (digitalRead(pinBotao) == LOW) {
    digitalWrite(pinLED, HIGH);
    Serial.println("LED ligou");
  }
  else {
    digitalWrite(pinLED, LOW);
    Serial.println("LED desligou");
  }
}