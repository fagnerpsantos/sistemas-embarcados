package br.edu.ifba.embarcados.clientewebplants.conector;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

@SuppressWarnings("deprecation")
public class Conector {

	private static final String ENDERECO_WS = "http://localhost:8081/webplants/v1/servico/";

	public String acessar(String urlFuncao) {
		String resultado = "";

		@SuppressWarnings("resource")
		HttpClient cliente = new DefaultHttpClient();
		HttpGet get = new HttpGet(ENDERECO_WS + urlFuncao);
		HttpResponse resposta;
		try {
			resposta = cliente.execute(get);
			BufferedReader br = new BufferedReader(new InputStreamReader(resposta.getEntity().getContent()));

			resultado = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}

		return resultado;
	}

	public Integer getId() {
		Integer id = 0;

		String sid = acessar("id");
		if (sid != "") {
			id = Integer.parseInt(sid);
		}

		return id;
	}

	public Integer getLuminosidade() {
		Integer luminosidade = 0;

		String slums = acessar("sensores/luminosidade");
		if (slums != "") {
			luminosidade = Integer.parseInt(slums);
		}

		return luminosidade;
	}

	public Integer getTemperatura() {
		Integer temperatura = 0;

		String stemp = acessar("sensores/temperatura");
		if (stemp != "") {
			temperatura = Integer.parseInt(stemp);
		}

		return temperatura;
	}
	
	public Integer getUmidade() {
		Integer umidade = 0;

		String sumid = acessar("sensores/umidade");
		if (sumid != "") {
			umidade = Integer.parseInt(sumid);
		}

		return umidade;
	}

}
