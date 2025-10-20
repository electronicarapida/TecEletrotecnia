#include <Arduino.h>
/*Instruções

definir estados de botões/variáveis dos botões
usar ifs para validar os estados com operadores
variáveis dos estados
ler variáveis dos estados das variáveis dos botões
aplicar switches a estas leituras
*/
const int BAUD_RATE = 9600;

int estado_botao_esquerda = 1;
int estado_botao_direita = 1;

int botao_da_esquerda = 4;
int botao_da_direita = 6;

int opcao = 2;

int led1 = 2;
int led2 = 12;

void leds(int estado_do_led1, int estado_do_led2)
{
    digitalWrite(led1, estado_do_led1);
    digitalWrite(led2, estado_do_led2);
}

void setup ()
{
    Serial.begin(BAUD_RATE);
    pinMode(botao_da_direita, INPUT);
    pinMode(botao_da_esquerda, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop ()
{
    //if (estado_botao_esquerda == 1 && estado_botao_direita == 1) {
        if ((digitalRead(botao_da_esquerda) == LOW) && (digitalRead(botao_da_direita) == LOW)) {
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
        }
    //}
    delay(100);
}