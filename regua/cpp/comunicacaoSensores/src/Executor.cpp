/*
 * Executor.cpp
 *
 *Testa a comunicação com o arduino, retornando e exibindo valores dos eixos
 *do acelerometro.
 *do
 *  Created on: 15/10/2015
 *      Author: fagnerpsantos e Ana Paula de Andrade (A bonita)
 */

#include "Comunicacao.h"

#include "iostream"
#include "math.h"

using namespace std;


struct InfoRF {
	short id;
	short batimentos;
	short temperatura;
	bool movimento;

};


int main(int argc, char **argv){
	//Criar uma instancia da classe de comunicacao
	Comunicacao com = Comunicacao("/dev/ttyUSB0");
    if (com.inciar() == EXIT_SUCCESS){
       char ci, cf;
       InfoRF info;

       // enquanto estiver executando...
       while (true){
    	   cout << "teste";
    	   // realizar a leitura do caracter I (inicio)
       int resultado = com.ler((char*)&ci, sizeof(ci));
       if ((resultado == EXIT_SUCCESS) && (ci == 'I')){

    	   // se a leitura de I ocorrer bem, ler os eixos
    	   resultado = com.ler((char*)&info, sizeof(info));
    	   if (resultado == EXIT_SUCCESS){
    		   // se a leitura dos eixos ocorrer bem ler o carcter F Final
    		   resultado = com.ler((char*)&cf, sizeof(cf));
    		   if((resultado == EXIT_SUCCESS)
    				   && (cf == 'F')){
    			   // se tudo for atendido, exibir os eixos do acelerometro

    			   cout << "temp = " << info.temperatura << endl;
    			   							cout << "batm = " << info.batimentos << endl;
    			   							cout << "movim = " << info.movimento << endl;
    			   							cout << "id = " << info.id << endl;
    		   }
    	   }
         }
         Sleep(50);
     }
 }


	return EXIT_SUCCESS;
}

