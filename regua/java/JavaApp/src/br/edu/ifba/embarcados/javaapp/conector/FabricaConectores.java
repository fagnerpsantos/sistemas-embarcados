package br.edu.ifba.embarcados.javaapp.conector;

import com.sun.jna.Native;
import com.sun.jna.Platform;

public class FabricaConectores {

	//Identificar o SO
	
	public static IComunicacaoSensores getConector(){
		
		IComunicacaoSensores conector = null;
		
		if(Platform.isWindows()){
			conector = (IComunicacaoSensores)Native.loadLibrary(
					"comunicacaoSensores.dll", IComunicacaoSensores.class);
		} else if(Platform.isLinux()){
			conector = (IComunicacaoSensores)Native.loadLibrary(
					"comunicacaoSensores.so", IComunicacaoSensores.class);
			
		}
		
		return conector;
		
		
		
	}
}
