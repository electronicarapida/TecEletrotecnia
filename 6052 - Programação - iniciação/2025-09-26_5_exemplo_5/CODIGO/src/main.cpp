#include <Arduino.h>

const int BAUD_RATE = 9600; //O baud rate (ou taxa de transmissão em bauds) é a velocidade de comunicação serial entre dois dispositivos — por exemplo, o microcontrolador e o computador. BAUD_RATE tem que ser configurado em sintonização pelo computador e pelo ficheiro (que irá ser usado pelo microcontrolador).
int teste = 0; //testar com -5 e 0 e ver diferenças de valores

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  if (teste) {
    Serial.println("if");
  }
  else {
    Serial.println("else");
  }
  delay(100);
}
