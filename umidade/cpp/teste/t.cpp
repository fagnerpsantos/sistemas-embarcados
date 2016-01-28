/*
 * daemon.cpp
 *
 *Leitor de sensores que executa em background no LINUX.
 *Pode ser iniciado e parada a partir da linha de comando.
 *Pode
 *  Created on: 07/01/2016
 *      Author: fagnerpsantos e anapandrade
 */

#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>

using namespace std;

#define ARQUIVO_LOG "/temp/sensoriamento.log" // Colocar o endereço
#define ARQUIVO_PIPE "" //Colocar endereço

int daemonize() {
	int resultado = EXIT_SUCCESS;

 pid_t daemon_id = 0;
 pid_t sid = 0;

 daemon_id = fork();
 if (daemon_id < 0){
	 resuktado = EXIT_FAILURE;
	 cout << "Falha de criação do daemon!" << endl;
 } else{
	 cout << "Daemon criado! Saindo do processo principal" << endl;

	 exit(0);

	 close(STDIN_FILENO);
	 close(STDOUT_FILENO);
	 close(STDERR_FILENO);

	 sid = setsid();
	 if (sid < 0){
		 exit(1);
	 }
 }

 return resultado;

}

ofstream iniciarLog(){
	ofstream log(" ", ios_base::out | ios_base::app);

	log << "Arquivo de log iniciado!" << endl;

	return log;

}

bool pipeIniciado(){
	int resultado = mkfifo(ARQUIV0_PIPE, 0666);

	return (resultado != -1);

}

int main(int argc, char* argv[]) {

	if(daemonize() == EXIT_SUCCESS){
		ofstream iniciarLog();

		log << "Daemon inicializado com sucesso" << endl;
		log << "PIpe sendo criado... " << endl;

		if (!pipeIniciado()){
           log << "Falha de inicializacao do PIPE" << endl;

           exit(1);
		}
	}

}


