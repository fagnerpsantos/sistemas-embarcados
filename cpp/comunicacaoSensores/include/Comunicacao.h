/*
 * comunicacao.h
 * Prove uma classe cujos metodos possibilitam
 * a comunicação com um dispositivo controlador
 * que realiza a leitura de sensores de 10 eixos.
 *
 *  Created on: 08/10/2015
 *      Author: fagnerpsantos
 */

#ifndef INCLUDE_COMUNICACAO_H_
#define INCLUDE_COMUNICACAO_H_

#include <stdlib.h>

#ifdef _WIN32 || _WIN64
#include <Windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#define Sleep(x) usleep(x * 1000);
#endif

class Comunicacao {
private:
	char* porta;

#ifdef __linux__
	int hPorta;
#endif

#ifdef _WIN32 || _WIN64
	HANDLE hPorta;
#endif

public:
	Comunicacao(char* porta);

	//Iniciar comunicação com a porta serial;
	int inciar();

	//Lê um buffer a partir da porta serial;
	int ler(char* buffer, long unsigned int bytesParaLer);

	//Finaliza a porta serial;
	int finalizar();

};



#endif /* INCLUDE_COMUNICACAO_H_ */
