package br.edu.ifba.se.umidade.leitor;

import br.edu.ifba.se.umidade.conector.SingleConector;


//Isso aqui é pra terceira unidade!
public class LeitorAssincrono implements Runnable {

	private boolean continuar;

	@Override
	public void run() {
		continuar = true;

		while (continuar) {

			SingleConector.ler();

			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

		}

	}

	public void parar() {
		continuar = false;
	}

}
