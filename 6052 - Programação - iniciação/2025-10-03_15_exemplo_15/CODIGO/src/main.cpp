#include <Arduino.h>

int BAUD_RATE = 9600;

//criar variaveis
int estado_do_botao_esquerdo = 0;
int estado_do_botao_direito = 0;

//vars botões
int botao_esquerdo = 4;
int botao_direito = 6;

int opcao = 0;

//perifericos dos leds
int led1 = 2;
int led2 = 12;

void setup () {
  //configuracao porta serie
  Serial.begin(BAUD_RATE);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao_esquerdo, INPUT);
  pinMode(botao_direito, INPUT);
}

void loop () {
  //leitura dos botões
  estado_do_botao_esquerdo = digitalRead(botao_esquerdo);
  estado_do_botao_direito = digitalRead(botao_direito);

  //quando botoes nao tiverem pressionados desligar leds
  if (!estado_do_botao_esquerdo && !estado_do_botao_direito)
  {
    opcao = 0;
  }
  //quando botao da direita nao estiver pressionado e o botao da esquerda estiver pressionado ligar led da esquerda e desligar led da direita
  else if (estado_do_botao_esquerdo && !estado_do_botao_direito)
  {
    opcao = 1;
  }
  //quando botao da esquerda nao estiver pressionado e o botao da direita estiver pressionado ligar led da direita e desligar led da esquerda
  else if (!estado_do_botao_esquerdo && estado_do_botao_direito)
  {
    opcao = 2;
  }
  //quando os botoes estiverem pressionados ligar os dois leds
  else if (estado_do_botao_esquerdo && estado_do_botao_direito)
  {
    opcao = 3;
  }
  else  {
    opcao = 0;
  }

  switch(opcao) {
    case 0:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      break;
    case 1:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      break;
    case 2:
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      break;
    case 3:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      break;
    default:
      Serial.println("Erro");
      break;
  }
  delay(100);
}

//quatro ifs
//passar para uma função
// depois criar uma função que execute as opções que estão lá, quatro funções
//passar tudo para uma função que passe os parametros diretamente, em que eu no switch executo leds(1,0), etc...
// chamar as funçoes
//foram trocadas funções por valores fixos por dinâmicos com uma só função que ative diretamente sem estar a ser chamada cada função
//diferente
//complicar para existir um led do meio, criar int meio do meio, dizer que ha int do led 3 que é o d9 que é o do meio, dizer que
//há um botão do meio, meter mais casos conforme necessário, 