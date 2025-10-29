#include <Arduino.h>

#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

// Pino de saída para comando do relé
#define RELE_PIN 7

// Definição dos pinos do sensor ultrassónico
#define TRIG_PIN 8
#define ECHO_PIN 9

// Distância limite (em centímetros) para ativação do relé
#define DISTANCIA_LIMITE 40

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println(F("Sensor ultrasónico"));

  // Configuração dos pinos
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELE_PIN, OUTPUT);

  digitalWrite(RELE_PIN, LOW);  // Garante relé desligado no arranque

  // Inicialização do LCD
  lcd.setCursor(0, 0);
  lcd.print(F("Atuador Proximidade "));
  lcd.setCursor(0, 1);
  lcd.print(F("Mazagao. 2025"));
  delay(1500);
  lcd.clear();

  Serial.println("Sistema de Proximidade iniciado...");
}

void loop() {
  // Gera o pulso de disparo (TRIG)
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Mede o tempo (em microssegundos) até ao eco retornar
  long duracao = pulseIn(ECHO_PIN, HIGH, 30000); // timeout 30ms (~5m)

  // Calcula a distância em centímetros (som = 0,034 cm/µs)
  long distancia = duracao * 0.034 / 2;

  // Mostra a distância na porta série
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Atualiza o LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print(distancia);
  lcd.print(" cm");

  // Controlo do relé conforme distância medida
  if (distancia > 0 && distancia <= DISTANCIA_LIMITE) {
    digitalWrite(RELE_PIN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Rele: ON ");
    Serial.println("Objeto proximo, Rele ligado");
  } else {
    digitalWrite(RELE_PIN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Rele: OFF");
    Serial.println("Sem objeto, Rele desligado");
  }

  delay(500); // Pequeno atraso antes da próxima leitura
}
