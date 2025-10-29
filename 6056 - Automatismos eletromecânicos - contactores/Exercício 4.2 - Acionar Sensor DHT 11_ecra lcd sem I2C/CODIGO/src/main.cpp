#include <Arduino.h>
#include <LiquidCrystal.h>
#include "DHT.h"

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

#define DHTPIN   7
#define DHTTYPE  DHT11
DHT dht(DHTPIN, DHTTYPE);

#define RELAY_PIN 3

float T0 = 24.0;
float T1 = 28.0;

bool aquecimento = false;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  Serial.println(F("Termóstato Digital - DHT22"));
  Serial.println(F("Autor: Artur G."));
  
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(F("Termostato DHT22"));
  lcd.setCursor(0, 1);
  lcd.print(F("Autor: Artur G."));
  delay(1500);
  lcd.clear();
}

void loop() {
  float temperatura = dht.readTemperature();
  float humidade    = dht.readHumidity();

  if (isnan(temperatura) || isnan(humidade)) {
    Serial.println(F("Erro de leitura no DHT22"));
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor  ");
    lcd.setCursor(0, 1);
    lcd.print("Verifique cabos ");
    delay(2000);
    return;
  }

  if (temperatura > T1 && aquecimento) {
    aquecimento = false;
    digitalWrite(RELAY_PIN, LOW);
  } else if (temperatura < T0 && !aquecimento) {
    aquecimento = true;
    digitalWrite(RELAY_PIN, HIGH);
  }

  Serial.print(F("Temp: "));
  Serial.print(temperatura, 1);
  Serial.print(F(" ºC  Hum: "));
  Serial.print(humidade, 1);
  Serial.print(F("%  Saída: "));
  Serial.println(aquecimento ? F("ON") : F("OFF"));

  lcd.setCursor(0, 0);
  lcd.print(F("T:"));
  lcd.print(temperatura, 1);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.setCursor(9, 0);
  lcd.print(F("H:"));
  lcd.print(humidade, 0);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  lcd.print("Saida D3: ");
  lcd.print(aquecimento ? F("ON ") : F("OFF"));

  delay(1000);
}
