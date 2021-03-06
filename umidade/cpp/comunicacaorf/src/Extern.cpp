/*
 * Extern.cpp
 *
 *  Created on: 03/12/2015
 *      Author: fagnerpsantos e Ana Paula (A bonitona)
 */

#include "Extern.h"
#include "Comunicacao.h"

struct InfoRF{
	short id;
	short luminosidade;
	short temperatura;
	short umidade;
}infoRF;

Comunicacao com = NULL;

int iniciar(char* porta){
	com = Comunicacao(porta);
	return com.iniciar();
}

int ler(){
	int resultado = EXIT_FAILURE;

	char ci = 0, cf = 0;
	if ((com.ler(&ci, sizeof(char)) ==0) && (ci == 'I')){
	   if ((com.ler((char*) &infoRF, sizeof(InfoRF)) == 0)){
		   if ((com.ler(&cf, sizeof(char)) ==0) && (cf == 'F')){
             resultado = EXIT_SUCCESS;
	   }
	}
}
	return resultado;
}

int getId(){
	return infoRF.id;
}

int getLuminosidade(){
	return infoRF.luminosidade;
}
int getTemperatura(){
	return infoRF.temperatura;
}
int getUmidade(){
	return infoRF.umidade;
}
int finalizar(){
	return com.finalizar();
}


