#include <Arduino.h>

void setup() {
  //inicialização do monitor serial
  Serial.begin(115200);
}

void loop() {
  //serial print é uma consola que expõe a execução do código
  Serial.println("Ola");
  delay(2000);
  /*O tempo do delay tem que respeitar a física dos componentes que estamos a utilizar. Por exemplo há sensores que lêem de 2
  em 2 segundos, conforme for constatado no datasheet, tem que ser respeitado este intervalo para não ler erros de leitura e
  para não se estragar o hardware.*/
}