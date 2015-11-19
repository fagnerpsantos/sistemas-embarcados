﻿package br.edu.ifba.embarcados.javaapp.graphs;


import java.awt.Component;
import java.awt.GridLayout;

import javax.swing.JDialog;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;
import br.edu.ifba.embarcados.javaapp.conector.FabricaConectores;
import br.edu.ifba.embarcados.javaapp.conector.IComunicacaoSensores;

public class Dialog extends JDialog {
	private static final long serialVersionUID = 1L;
	Retangulo tela = new Retangulo();
	
	//Cria uma janela do tamanho 400 x 300 
	public Dialog(){
		setSize(400, 400);
		setResizable(false);
		
	}
	
	//Inicia a janela 
	public void init(){
		
		add(tela);

		

                setTitle("Régua de Nivelamento");
	

		setVisible(true);
		setModal(true);
		
		
	}
	
	public static void main(String[] args) {
		new Dialog();
	}
	
	//Aqui só retorna o retângulo que está inserido
	public IListenerAcelerometro getListener() {
		return tela;
	}

}
