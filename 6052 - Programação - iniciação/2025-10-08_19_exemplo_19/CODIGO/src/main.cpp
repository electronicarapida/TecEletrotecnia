#include <Arduino.h>

/*ANOTAÇÕES
quatro botões, cima baixo esquerda direita
ao carregar em dois deles mencionar as diagonais
carregar em terceiro botão dá default
*/

int BAUD_RATE = 9600;

//pinos dos botões
int botao_esquerda = 2;
int botao_cima = 3;
int botao_baixo = 4;
int botao_direita = 5;

//pinos dos LEDs
int led_esquerda = 8;
int led_cima = 9;
int led_baixo = 10;
int led_direita = 11;

//estados dos botões
int estado_esquerda = 0;
int estado_cima = 0;
int estado_baixo = 0;
int estado_direita = 0;

//ultima opção (para não repetir mensagens no serial)
int ultima_opcao = -1;

//função de controlo dos LEDs
void controlaLeds(int esquerda, int cima, int baixo, int direita) {
  digitalWrite(led_esquerda, esquerda);
  digitalWrite(led_cima, cima);
  digitalWrite(led_baixo, baixo);
  digitalWrite(led_direita, direita);
}

void setup() {
  Serial.begin(BAUD_RATE);

  //configurar LEDs
  pinMode(led_esquerda, OUTPUT);
  pinMode(led_cima, OUTPUT);
  pinMode(led_baixo, OUTPUT);
  pinMode(led_direita, OUTPUT);

  //configurar botões
  pinMode(botao_esquerda, INPUT);
  pinMode(botao_cima, INPUT);
  pinMode(botao_baixo, INPUT);
  pinMode(botao_direita, INPUT);

  Serial.println("=== Sistema Iniciado ===");
}

void loop() {
  //ler estados dos botões
  estado_esquerda = !digitalRead(botao_esquerda);
  estado_cima = !digitalRead(botao_cima);
  estado_baixo = !digitalRead(botao_baixo);
  estado_direita = !digitalRead(botao_direita);

  int total_pressionados = estado_esquerda + estado_cima + estado_baixo + estado_direita;
  int opcao = 0;
  
  //determinar a opção com base nas combinações
  if (total_pressionados == 0) {
    opcao = 0; //nenhum
  } 
  else if (total_pressionados >= 3) {
    opcao = 9; //3 ou mais botões
  }
  else if (estado_esquerda && estado_cima) {
    opcao = 5; //diagonal superior esquerda
  } 
  else if (estado_cima && estado_direita) {
    opcao = 6; //diagonal superior direita
  } 
  else if (estado_esquerda && estado_baixo) {
    opcao = 7; //diagonal inferior esquerda
  } 
  else if (estado_baixo && estado_direita) {
    opcao = 8; //diagonal inferior direita
  } 
  else if (estado_esquerda) {
    opcao = 1; //esquerda
  } 
  else if (estado_cima) {
    opcao = 2; //cima
  } 
  else if (estado_baixo) {
    opcao = 3; //baixo
  } 
  else if (estado_direita) {
    opcao = 4; //direita
  }
  
  if (opcao != ultima_opcao) {
    ultima_opcao = opcao;
    
    switch (opcao) {
      case 0:
      controlaLeds(LOW, LOW, LOW, LOW);
      Serial.println("Nenhum botão pressionado");
      break;
      case 1:
        controlaLeds(HIGH, LOW, LOW, LOW);
        Serial.println("Botão ESQUERDA pressionado");
        break;
      case 2:
        controlaLeds(LOW, HIGH, LOW, LOW);
        Serial.println("Botão CIMA pressionado");
        break;
      case 3:
        controlaLeds(LOW, LOW, HIGH, LOW);
        Serial.println("Botão BAIXO pressionado");
        break;
      case 4:
        controlaLeds(LOW, LOW, LOW, HIGH);
        Serial.println("Botão DIREITA pressionado");
        break;
      case 5:
        controlaLeds(HIGH, HIGH, LOW, LOW);
        Serial.println("Diagonal SUPERIOR ESQUERDA");
        break;
      case 6:
        controlaLeds(LOW, HIGH, LOW, HIGH);
        Serial.println("Diagonal SUPERIOR DIREITA");
        break;
      case 7:
        controlaLeds(HIGH, LOW, HIGH, LOW);
        Serial.println("Diagonal INFERIOR ESQUERDA");
        break;
      case 8:
        controlaLeds(LOW, LOW, HIGH, HIGH);
        Serial.println("Diagonal INFERIOR DIREITA");
        break;
      case 9:
      default:
        controlaLeds(LOW, LOW, LOW, LOW);
        Serial.println("Erro: opção inválida");
        break;
    }
  }
  delay(1000);
}