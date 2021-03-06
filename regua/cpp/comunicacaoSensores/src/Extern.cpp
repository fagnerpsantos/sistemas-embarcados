/*
 * Extern.cpp

 *
 *  Created on: 15/10/2015
 *      Author: fagnerpsantos
 */

#include <Comunicacao.h>
#include "Extern.h"
#include <cstdlib>
#include "math.h"

const float alpha = 0.5;

struct Eixos {
	short acelX, acelY, acelZ;
};

Eixos eixos;

Comunicacao com = NULL;

int iniciar(char* porta) {
	com = Comunicacao(porta);
	return com.inciar();
}

int ler() {
	char ci, cf;
	// enquanto estiver executando...
	// realizar a leitura do caracter I (inicio)
	int resultado = com.ler((char*) &ci, sizeof(ci));
	if ((resultado == EXIT_SUCCESS) && (ci == 'I')) {
		// se a leitura de I ocorrer bem, ler os eixos
		resultado = com.ler((char*) &eixos, sizeof(eixos));
		if (resultado == EXIT_SUCCESS) {
			// se a leitura dos eixos ocorrer bem ler o carcter F Final
			resultado = com.ler((char*) &cf, sizeof(cf));
			if ((resultado == EXIT_SUCCESS) && (cf == 'F')) {
				// se tudo for atendido, exibir os eixos do acelerometro
					resultado = EXIT_SUCCESS;
			}

		}

	}
	return resultado;
}
int getAcelX(){
	return eixos.acelX;
}
int getAcelY(){
	return eixos.acelY;
}
int getAcelZ(){
	return eixos.acelZ;
}
int finalizar(){
	return com.finalizar();
}

// Essa é a função principal. Nela, enviamos os dados que recebemos do acelerômetro em forma de graus.
// Utilizamos o arctang para esse cálculo

int grausAcel(){
	double fXg = eixos.acelX * alpha + (fXg * (1.0 - alpha));
	double fYg = eixos.acelY * alpha + (fYg * (1.0 - alpha));
	double fZg = eixos.acelZ * alpha + (fZg * (1.0 - alpha));

	//Roll & Pitch Equations
	int roll  = (atan2(-fYg, fZg)*180.0)/M_PI;

	return roll;
}

int grausAcelZ(){
	double fXg = eixos.acelX * alpha + (fXg * (1.0 - alpha));
	double fYg = eixos.acelY * alpha + (fYg * (1.0 - alpha));
	double fZg = eixos.acelZ * alpha + (fZg * (1.0 - alpha));

	int pitch = (atan2(fXg, sqrt(fYg*fYg + fZg*fZg))*180.0)/M_PI;

	return pitch;
}
