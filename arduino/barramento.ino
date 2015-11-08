#include <Wire.h>
#include "ADXL345.h"

ADXL345 acel =  ADXL345();

struct Eixos {
  int acelX, acelY, acelZ;
  
};

Eixos eixos;

void setup() {
  Serial.begin(9600);
  acel.powerOn(); 
};

void enviarEixos() {
  int tam = sizeof(eixos);
  char buff(tam);
  
  memcpy(&buff, &eixos, tam);
  
  Serial.write('I');
  Serial.write((uint8_t*)&buff, tam);
  Serial.write('F'); 
};

void loop() {
  acel.readAccel(&eixos.acelX, &eixos.acelY, &eixos.acelZ);
  enviarEixos();
  
  delay(50);
};
