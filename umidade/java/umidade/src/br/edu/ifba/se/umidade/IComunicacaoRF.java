package br.edu.ifba.se.umidade;

import com.sun.jna.Library;

public interface IComunicacaoRF extends Library {

	public int iniciar(String porta);

	public int ler();

	public int getId();

	public int getUmidade();

	public int getTemperatura();

	public int getLuminosidade();

	public int finalizar();

}
