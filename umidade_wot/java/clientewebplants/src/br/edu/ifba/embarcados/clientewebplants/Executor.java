package br.edu.ifba.embarcados.clientewebplants;

import br.edu.ifba.embarcados.clientewebplants.conector.Conector;

public class Executor {

	public static void main(String[] args) throws InterruptedException {
		Conector conector = new Conector();

		while (true) {
			Integer id = conector.getId();
			System.out.println("id = " + id);
			
			System.out.println("Sensores...");
			
			Integer batimentos = conector.getLuminosidade();
			System.out.println("Batimentos = " + batimentos);
			Integer temperatura = conector.getTemperatura();
			System.out.println("Temperatura = " + temperatura);
			System.out.println("Umidade = " + conector.getUmidade());
			
			System.out.println("Final de leitura!");
			System.out.println("...");
			
			
			Thread.sleep(1000);
		}
	}

}
