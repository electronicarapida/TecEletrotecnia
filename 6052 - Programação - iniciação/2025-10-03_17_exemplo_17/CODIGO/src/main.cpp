#include <Arduino.h>

int BAUD_RATE = 9600;

//pinos dos botões
int botao_esquerdo = 4;
int botao_meio = 5;
int botao_direito = 6;

//pinos dos LEDs
int led_esquerdo = 2;
int led_meio = 9;
int led_direito = 12;

//variáveis de estado
int estado_esquerdo = 0;
int estado_meio = 0;
int estado_direito = 0;

//ppção de controlo
int opcao = 0;

void controlaLeds(int esquerdo, int meio, int direito) {
  digitalWrite(led_esquerdo, esquerdo);
  digitalWrite(led_meio, meio);
  digitalWrite(led_direito, direito);

  Serial.print("Estado -> Esquerdo: ");
  Serial.print(esquerdo);
  Serial.print(" | Meio: ");
  Serial.print(meio);
  Serial.print(" | Direito: ");
  Serial.println(direito);
}

void setup() {
  Serial.begin(BAUD_RATE);

  //configuração dos pinos
  pinMode(led_esquerdo, OUTPUT);
  pinMode(led_meio, OUTPUT);
  pinMode(led_direito, OUTPUT);

  pinMode(botao_esquerdo, INPUT);
  pinMode(botao_meio, INPUT);
  pinMode(botao_direito, INPUT);
}

void loop() {
  estado_esquerdo = digitalRead(botao_esquerdo);
  estado_meio = digitalRead(botao_meio);
  estado_direito = digitalRead(botao_direito);

  if (!estado_esquerdo && !estado_meio && !estado_direito) {
    opcao = 0; //nenhum botão
  } 
  else if (estado_esquerdo && !estado_meio && !estado_direito) {
    opcao = 1; //só esquerdo
  } 
  else if (!estado_esquerdo && !estado_meio && estado_direito) {
    opcao = 2; //só direito
  } 
  else if (!estado_esquerdo && estado_meio && !estado_direito) {
    opcao = 3; //só meio
  } 
  else {
    opcao = 4; //vários pressionados
  }

  switch (opcao) {
    case 0:
      controlaLeds(LOW, LOW, LOW);
      break;
    case 1:
      controlaLeds(HIGH, LOW, LOW);
      break;
    case 2:
      controlaLeds(LOW, LOW, HIGH);
      break;
    case 3:
      controlaLeds(LOW, HIGH, LOW);
      break;
    case 4:
      controlaLeds(HIGH, HIGH, HIGH);
      break;
    default:
      controlaLeds(LOW, LOW, LOW);
      Serial.println("Erro: opção inválida");
      break;
  }

  delay(100);
}
