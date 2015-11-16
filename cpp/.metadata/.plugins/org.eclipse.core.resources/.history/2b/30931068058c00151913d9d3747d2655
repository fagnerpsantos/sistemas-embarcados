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

using namespace std;

struct Eixos {
  short acelX, acelY, acelZ;

};


int main(int argc, char **argv){
	//Criar uma instancia da classe de comunicacao
	Comunicacao com = Comunicacao("/dev/ttyUSB0");
    if (com.inciar() == EXIT_SUCCESS){
       char ci, cf;
       Eixos eixos;

       // enquanto estiver executando...
       while (true){
    	   // realizar a leitura do caracter I (inicio)
       int resultado = com.ler((char*)&ci, sizeof(ci));
       if ((resultado == EXIT_SUCCESS) && (ci == 'I')){
    	   // se a leitura de I ocorrer bem, ler os eixos
    	   resultado = com.ler((char*)&eixos, sizeof(eixos));
    	   if (resultado == EXIT_SUCCESS){
    		   // se a leitura dos eixos ocorrer bem ler o carcter F Final
    		   resultado = com.ler((char*)&cf, sizeof(cf));
    		   if((resultado == EXIT_SUCCESS)
    				   && (cf == 'F')){
    			   // se tudo for atendido, exibir os eixos do acelerometro
    			   cout << "X = " << eixos.acelX << endl;
    			   cout << "Y = " << eixos.acelY << endl;
    			   cout << "Z = " << eixos.acelZ << endl;
    		   }
    	   }
         }
         Sleep(100);
     }
 }


	return EXIT_SUCCESS;
}



