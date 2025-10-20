#include <Arduino.h>

int BAUD_RATE = 9600;

/*
em vez de:
botao b1;
botao b2;
botao b3;

organizar com a seguinte estrutura:
typedef struct botao
{
 int periferico;
 int valor;
}
*/

//criar estrutura botao e led
typedef struct botao {
  int pino_botao;
  int estado_botao;
};

typedef struct led {
  int pino_led;
};

/*
botaoLed b1 = {4, 2, HIGH};
botaoLed b2 = {6, 12, HIGH};


int opcao = 0;

void leds(int estado_do_led1, int estado_do_led2)
{
  led l1, l2;
  digitalWrite(l1.pino_led, estado_do_led1);
  digitalWrite(l2.pino_led, estado_do_led2);
}

void setup ()
{
  Serial.begin(BAUD_RATE);

  botao b1, b2;
  led l1, l2;
  b1.pino_botao = 4;
  b2.pino_botao = 6;
  l1.pino_led = 2;
  l2.pino_led = 12;

  pinMode(b1.pino_botao, INPUT);
  pinMode(b2.pino_botao, INPUT);
  pinMode(l1.pino_led, OUTPUT);
  pinMode(l2.pino_led, OUTPUT);
}

void loop ()
{
  botao b1, b2;
  led l1, l2;

  if ((digitalRead(!b1.estado_botao) == HIGH) || (digitalRead(!b2.estado_botao) == HIGH))
    switch (opcao) {
      case 0:
        leds(LOW, LOW);
        break;
      case 1:
        leds(HIGH, LOW);
        break;
      case 2:
        leds(LOW, HIGH);
        break;
      case 3:
        leds(HIGH, HIGH);
        break;
      default:
        Serial.println("Erro");
        break;
  }
  delay(100);
}
*/

botao b1, b2;
led l1, l2;
int opcao = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  
  b1.pino_botao = 4;
  b2.pino_botao = 6;
  l1.pino_led = 2;
  l2.pino_led = 12;

  pinMode(b1.pino_botao, INPUT);
  pinMode(b2.pino_botao, INPUT);
  pinMode(l1.pino_led, OUTPUT);
  pinMode(l2.pino_led, OUTPUT);
}

void leds(int estado_led1, int estado_led2) {
  digitalWrite(l1.pino_led, estado_led1);
  digitalWrite(l2.pino_led, estado_led2);
}

void loop() {
  b1.estado_botao = digitalRead(b1.pino_botao);
  b2.estado_botao = digitalRead(b2.pino_botao);

  if (b1.estado_botao == LOW || b2.estado_botao == LOW) {
    if (b1.estado_botao == LOW && b2.estado_botao == HIGH) {
      opcao = 1;
    }
    else if (b1.estado_botao == HIGH && b2.estado_botao == LOW) {
      opcao = 2;
    }
    else if (b1.estado_botao == LOW && b2.estado_botao == LOW) {
      opcao = 3;
    }
    switch (opcao) {
      case 0:
        leds(LOW, LOW);
        break;
      case 1:
        leds(HIGH, LOW);
        break;
      case 2:
        leds(LOW, HIGH);
        break;
      case 3:
        leds(HIGH, HIGH);
        break;
      default:
        Serial.println("Erro");
        break;
    }
    delay(300);
  }
  delay(100);
}