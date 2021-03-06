/*
 * Executor.cpp
 *
 *  Created on: 26/11/2015
 *      Author: fagnerpsantos e anaandrade
 */
#include <iostream>
#include <Comunicacao.h>

using namespace std;

struct InfoRF {
	short id;
	short luminosidade;
	short temperatura;
	short umidade;
};

int main(int argc, char **argv) {

	Comunicacao com("/dev/ttyUSB0");

 	//iniciou a comunicacao
	if (com.iniciar() == EXIT_SUCCESS) {  //se foi iniciado com sucesso
		char ci, cf;
		InfoRF info = { 0 };

		while (true) {
			//realizar a leitura do caractere i que representa o inicio
			int resultado = com.ler((char*) &ci, sizeof(ci)); //manda ler e capta o resultado
			if (resultado == EXIT_SUCCESS && (ci == 'I')) { //se o resultado for sucesso e ele tiver encontrado o i
				resultado = com.ler((char*) &info, sizeof(info)); //vai ler o conteudo de dados depois do i na estrutura
				if (resultado == EXIT_SUCCESS) {  //se leu os dados ok
					resultado = com.ler((char*) &cf, sizeof(cf)); //o resultado sera a leitura do f
					if (resultado == EXIT_SUCCESS && (cf == 'F')) { //se leu tudo certinho, vai imprimir
						cout << "id = " << info.id << endl;
						cout << "luminosidade = " << info.luminosidade << endl;
						cout << "temperatura = " << info.temperatura << endl;
						cout << "umidade = " << info.umidade << endl;

					}
				}
			}

			Sleep(50);
		}
	}


	return 0;
}
