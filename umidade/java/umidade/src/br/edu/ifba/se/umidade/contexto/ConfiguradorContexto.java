package br.edu.ifba.se.umidade.contexto;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;

import br.edu.ifba.se.umidade.conector.SingleConector;
import br.edu.ifba.se.umidade.leitor.LeitorAssincrono;

import com.sun.faces.config.ConfigureListener;

public class ConfiguradorContexto extends ConfigureListener {
	

	private LeitorAssincrono leitor;
	private Thread tLeitor;

	@Override
	public void contextInitialized(ServletContextEvent sce) {
		super.contextInitialized(sce);
		ServletContext sc = sce.getServletContext();
		String libPath = sc.getRealPath("/WEB-INF/lib");

		SingleConector.iniciarComunicacaoRF(libPath);

		leitor = new LeitorAssincrono();
		tLeitor = new Thread(leitor);
		tLeitor.start();
	}

	@Override
	public void contextDestroyed(ServletContextEvent sce) {
		leitor.parar();
		try {
			tLeitor.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SingleConector.finalizar();
		super.contextDestroyed(sce);
	}
	 
}
