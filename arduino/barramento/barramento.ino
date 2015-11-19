/********************************************************************************
* ADXL345 Library Examples- pitch_roll.ino                                      *
*                                                                               *
* Copyright (C) 2012 Anil Motilal Mahtani Mirchandani(anil.mmm@gmail.com)       *
*                                                                               *
* License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> *
* This is free software: you are free to change and redistribute it.            *
* There is NO WARRANTY, to the extent permitted by law.                         *
*                                                                               *
*********************************************************************************/

#include <Wire.h>
#include "ADXL345.h"

const float alpha = 0.5;

double fXg = 0;
double fYg = 0;
double fZg = 0;

ADXL345 acc;

//Inicia a porta serial e o acelerometro
void setup()
{
  Serial.begin(9600);
	acc.begin();
	
	
}
//Cria uma estrutura que ira comportar os 3 eixos do acelerometro
struct Eixos{
  int acelX, acelY, acelZ;
};

Eixos eixos;

//Coloca os dados do acelerometro na estrutura
void enviarEixos() {
  int tam = sizeof(eixos);
  char buff[tam];

  memcpy(&buff, &eixos, tam);
  Serial.write('I');
  Serial.write((uint8_t*)&buff, tam);
  Serial.write('F');
  
}

//VArre o acelerometro enviando os eixos
void loop()
{
	acc.read(&eixos.acelX, &eixos.acelY, &eixos.acelZ);
        enviarEixos();


	delay(50);
}

