package br.edu.ifba.embarcados.javaapp.graphs;


import java.awt.GridLayout;

import javax.swing.JDialog;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class Dialog extends JDialog {
	private static final long serialVersionUID = 1L;
	Retangulo tela = new Retangulo();
	
	//Cria uma janela do tamanho 400 x 300 
	public Dialog(){
		setSize(400, 300);
		setResizable(false);
		
	}
	
	//Inicia a janela 
	public void init(){
		setLocationRelativeTo(null);
		setLayout(new GridLayout(1, 1, 0, 0));
		
		add(tela);
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
