package es.practica3ds5.JurassicCards.modelo;

import es.practica3ds5.JurassicCards.bd.Cartas;
import java.util.ArrayList;
import java.util.Collections;

public class Jugador {
	private ArrayList<Carta> mazo;
	private ArrayList<Carta> mano = new ArrayList<>();
	private ArrayList<Carta> campo = new ArrayList<>();
	private ArrayList<Carta> cementerio = new ArrayList<>();

	private Cartas baraja = new Cartas();
	private String nombre;
	private int salud;

	public Jugador(String nom){
		nombre = nom;
		mazo = baraja.crearMazo();
		Collections.shuffle(mazo);
		salud = 100;

		for (int i = 0; i < 5; i++)
			sacarCarta();
	}

	//******************************************************************************//
	// Metodos GET
	public int getSalud(){
		return salud;
	}

	public String getNombre(){
		return  nombre;
	}

	public Carta getCartaCampo(int indice) {
		return campo.get(indice);
	}

	public ArrayList<Carta> getMano(){
		return mano;
	}

	public ArrayList<Carta> getCampo() {
		return campo;
	}

	public int getAtaqueTotal(){
		int total = 0;

		for(int i = 0; i < campo.size(); i++){
			total += campo.get(i).getAtaque();
		}

		return total;
	}

	//******************************************************************************//
	public void sacarCarta(){
		if (!mazo.isEmpty()) {
			mano.add(mazo.get(0));
			mazo.remove(mazo.get(0));
		}
	}

	public void sacarAlCampo(int num){
		if(campo.size()<=5){
			campo.add(mano.get(num));
			mano.remove(mano.get(num));
		}
	}

	public void addCartaAMano(int num){
		if(mano.size()<=5 && mazo.size()>0){
			mano.add(mazo.get(num));
			mazo.remove(mazo.get(num));
		}
	}

	public void addCartaACementerio(int num){
		cementerio.add(campo.get(num));
		campo.remove(campo.get(num));
	}

	//******************************************************************************//
	public void restarSalud(int s){
		salud = salud - s;
		if (salud < 0){
			salud = 0;
		}
	}

	public String toString(){
		String e = nombre + " " + salud;
		return e;
	}
}