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

//opção atual
int opcao = 0;

void setup() {
  Serial.begin(BAUD_RATE);

  //configuração dos LEDs
  pinMode(led_esquerdo, OUTPUT);
  pinMode(led_meio, OUTPUT);
  pinMode(led_direito, OUTPUT);

  //configuração dos botões
  pinMode(botao_esquerdo, INPUT);
  pinMode(botao_meio, INPUT);
  pinMode(botao_direito, INPUT);
}


//tudo desligado
void desligarTudo() {
  digitalWrite(led_esquerdo, LOW);
  digitalWrite(led_meio, LOW);
  digitalWrite(led_direito, LOW);
  Serial.println("Todos os LEDs desligados");
}

//LED esquerdo aceso
void soEsquerdo() {
  digitalWrite(led_esquerdo, HIGH);
  digitalWrite(led_meio, LOW);
  digitalWrite(led_direito, LOW);
  Serial.println("LED esquerdo aceso");
}

//LED direito aceso
void soDireito() {
  digitalWrite(led_esquerdo, LOW);
  digitalWrite(led_meio, LOW);
  digitalWrite(led_direito, HIGH);
  Serial.println("LED direito aceso");
}

//todos acesos
void tudoLigado() {
  digitalWrite(led_esquerdo, HIGH);
  digitalWrite(led_meio, HIGH);
  digitalWrite(led_direito, HIGH);
  Serial.println("Todos os LEDs acesos");
}

void loop() {
  estado_esquerdo = digitalRead(botao_esquerdo);
  estado_meio = digitalRead(botao_meio);
  estado_direito = digitalRead(botao_direito);

  if (!estado_esquerdo && !estado_meio && !estado_direito) {
    opcao = 0;  //nenhum
  } 
  else if (estado_esquerdo && !estado_meio && !estado_direito) {
    opcao = 1;  //só esquerdo
  } 
  else if (!estado_esquerdo && !estado_meio && estado_direito) {
    opcao = 2;  //só direito
  } 
  else {
    opcao = 3;  //meio ou ambos
  }

  switch (opcao) {
    case 0:
      desligarTudo();
      break;
    case 1:
      soEsquerdo();
      break;
    case 2:
      soDireito();
      break;
    case 3:
      tudoLigado();
      break;
    default:
      Serial.println("Erro: opção inválida");
      desligarTudo();
      break;
  }
  delay(2000);
}