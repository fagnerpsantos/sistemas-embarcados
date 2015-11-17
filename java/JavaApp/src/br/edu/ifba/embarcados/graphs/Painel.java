package br.edu.ifba.embarcados.graphs;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Painel extends JComponent {
	
    public Painel() {
    	repaint();
    }
    
    protected void paintComponent(Graphics g) {
        Graphics2D g2d;
        g2d = (Graphics2D)g.create();
        
        // Erase background to white
        g2d.setColor(Color.WHITE);
        g2d.fillRect(0, 0, getWidth(), getHeight());
        
        // base rectangle
        g2d.setColor(Color.GRAY.brighter());
        g2d.fillRect(50, 50, 50, 50);
        
        // rotated 45 degrees around origin
 /*       g2d.rotate(Math.toRadians(45));
        g2d.setColor(Color.GRAY.darker());
        g2d.fillRect(50, 50, 50, 50);
        */
        
        // rotated 45 degrees about center of rect
        g2d = (Graphics2D)g.create();
        g2d.rotate(Math.toRadians(50), 75, 75);
        g2d.setColor(Color.BLACK);
        g2d.fillRect(50, 50, 50, 50);

        // done with g2d, dispose it
        g2d.dispose();
    }
    
    private static void createAndShowGUI() {    
        JFrame f = new JFrame("Rotation");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(300, 300);
        f.add(new Painel());
        f.setVisible(true);
    }
    
    public static void main(String args[]) {
        Runnable doCreateAndShowGUI = new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        };
        SwingUtilities.invokeLater(doCreateAndShowGUI);
    }

}
