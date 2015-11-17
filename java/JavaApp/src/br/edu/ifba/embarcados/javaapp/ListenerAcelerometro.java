package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class ListenerAcelerometro 
	implements IListenerAcelerometro {

	public void notificarMovimento(int x) {
		System.out.println("X = " + x);

		
	}
 

}
