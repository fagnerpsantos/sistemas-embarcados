package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.AsincExec;

public class Executor {

	public static void main(String[] args) throws InterruptedException {
		ListenerAcelerometro listener =
				new ListenerAcelerometro();
		
		//Acessar acelerômetro
		
		AsincExec asinc = 
				new AsincExec("/dev/ttyUSB0");
		asinc.addListener(listener);
		
		Thread t = new Thread(asinc);
		t.start();
		
		for(int i=0; i<10; i++){
			Thread.sleep(1000);
		}
		asinc.setContinuar(false);
		t.join();	

	}

}
