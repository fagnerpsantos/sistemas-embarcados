package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.AsincExec;
import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;
import br.edu.ifba.embarcados.javaapp.graphs.Dialog;
import br.edu.ifba.embarcados.javaapp.graphs.Retangulo;

public class Executor {

	public static void main(String[] args) throws InterruptedException {
		
		//Acessar acelerômetro
		
		AsincExec asinc = 
				new AsincExec("/dev/ttyUSB0");
		
		Dialog dialog = new Dialog();
		
		IListenerAcelerometro listener = dialog.getListener();
		
		asinc.addListener(listener);
		
		Thread t = new Thread(asinc);
		t.start();
		
		dialog.init();
		
		t.join();	

	}

}
