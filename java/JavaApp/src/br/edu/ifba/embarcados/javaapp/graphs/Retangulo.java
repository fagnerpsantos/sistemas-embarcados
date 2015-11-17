/*
 * Essa classe é responsável por criar o retângulo, foi utilizada a biblioteca
 * graphcs2D do próprio Java
 */

package br.edu.ifba.embarcados.javaapp.graphs;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class Retangulo extends JPanel implements IListenerAcelerometro {
	
	
    public Retangulo() {
    	repaint();
    }
    
    public static int angulo = 0;
    
    /*
     * Essa função fica pegando os dados do acelerômetro e manipulando o 
     * retângulo
     */
	@Override
	public void notificarMovimento(int x) {
		angulo = x;
		
		removeAll();
		updateUI();
		repaint();
		
	}

	/*
	 * Essa função é pra dar vida ao retângulo. A cor, tamanho..
	 */
    
    protected void paintComponent(Graphics g) {
    	
        Graphics2D g2d;
        g2d = (Graphics2D)g.create();
        
        // Erase background to white
        g2d.setColor(Color.WHITE);
        g2d.fillRect(0, 0, getWidth(), getHeight());
        
        // base rectangle
        g2d.setColor(Color.GRAY.brighter());
        g2d.fillRect(50, 50, 150, 150);
        
        // rotated 45 degrees around origin
 /*       g2d.rotate(Math.toRadians(45));
        g2d.setColor(Color.GRAY.darker());
        g2d.fillRect(50, 50, 50, 50);
        */
        
        // Aqui é o mais importante, pois é onde nós rotacionamos o retângulo
        //na função rotate, passamos o angulo que é obtido através do método 
        //notificarMovimento e ele gira conforme o arduino
        g2d = (Graphics2D)g.create();
        g2d.rotate(Math.toRadians(-angulo), 75, 75);
        g2d.setColor(Color.BLACK);
        g2d.fillRect(50, 50, 150, 150);
        

        // done with g2d, dispose it
        g2d.dispose();
    }

    

}
