package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.AsincExec;
import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;
import br.edu.ifba.embarcados.javaapp.conector.FabricaConectores;
import br.edu.ifba.embarcados.javaapp.conector.IComunicacaoSensores;
import br.edu.ifba.embarcados.javaapp.graphs.Dialog;
import br.edu.ifba.embarcados.javaapp.graphs.Retangulo;

public class Executor {

	public static void main(String[] args) throws InterruptedException {
		
		//Acessar acelerômetro
		
		AsincExec asinc = 
				new AsincExec("/dev/ttyUSB0");
		
		//Criar uma nova janela
		
		Dialog dialog = new Dialog();

		
		ListenerAcelerometro li = new ListenerAcelerometro();
		
		IListenerAcelerometro listener = dialog.getListener();
		
		//Adicionar o retângulo na janela
		asinc.addListener(listener);
		
		Thread t = new Thread(asinc);
		//Iniciar
		t.start();
		
		dialog.init();
		
		t.join();	

	}

}
