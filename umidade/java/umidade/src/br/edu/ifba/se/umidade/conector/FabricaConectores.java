package br.edu.ifba.se.umidade.conector;

import com.sun.jna.Native;
import com.sun.jna.Platform;

import br.edu.ifba.se.umidade.IComunicacaoRF;

public class FabricaConectores {
	
	public static IComunicacaoRF getConector(String libPath){
		IComunicacaoRF comRF = null;
		
		if(Platform.isWindows()){
			comRF = (IComunicacaoRF) Native.loadLibrary(libPath + "/comunicacaorf.dll", IComunicacaoRF.class);
		} else if (Platform.isLinux()){
			comRF = (IComunicacaoRF) Native.loadLibrary(libPath + "/comunicacaorf.so", IComunicacaoRF.class);

		}
		
		return comRF;
	}

}
