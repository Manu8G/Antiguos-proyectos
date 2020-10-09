package es.practica3ds5.JurassicCards.modelo;

import java.util.ArrayList;

public class Partida {
	private int indiceJugadorActual;
	private ArrayList<Jugador> jugadores = new ArrayList<>();
	private int turno, numCartasCampo;
	private Carta generica= new Carta("?",0);

	public void init(ArrayList<String> nombres) {
		for (int i = 0; i < nombres.size(); i++)
			jugadores.add(new Jugador(nombres.get(i)));

		indiceJugadorActual = 0;
		turno = 1;
		numCartasCampo = 0;
	}

	//******************************************************************************//
	// Metodos GET
	public int getIndiceJugadorActual(){
		return indiceJugadorActual;
	}

	public Jugador getJugadorActual(){
		return jugadores.get(indiceJugadorActual);
	}

	public Jugador getJugador(int indice){
		return jugadores.get(indice);
	}

	public Jugador getOtroJugador(){
		if (indiceJugadorActual == 0){
			return jugadores.get(1);
		} else {
			return jugadores.get(0);
		}
	}

	public Carta getGenerica(){
		return generica;
	}

	//******************************************************************************//
	public void pasarTurno() {
		if (getJugadorActual().getSalud() != 0 && getOtroJugador().getSalud() != 0){
			indiceJugadorActual++;

			if (indiceJugadorActual >= jugadores.size()) {
				indiceJugadorActual = 0;
			}

			jugadores.get(indiceJugadorActual).addCartaAMano(0);
			turno = 0;
			numCartasCampo = 0;
		}
	}

	public void atacar(Jugador otro) {
		int ataqueJugadorActual = getJugadorActual().getAtaqueTotal();
		int ataqueOtroJugador = otro.getAtaqueTotal();
		int resultado = ataqueJugadorActual - ataqueOtroJugador;
		int s = 0;

		if (turno == 0 && getJugadorActual().getCampo().size() > 0 && (getJugadorActual().getSalud() != 0 && getOtroJugador().getSalud() != 0)) {
			if (resultado > 0) {        // El jugador 1 tiene mayor ataque
				while (otro.getCampo().size() > 0) {
					s += otro.getCartaCampo(0).getAtaque();
					otro.addCartaACementerio(0);
					if (s > getJugadorActual().getCartaCampo(0).getAtaque()) {
						s -= getJugadorActual().getCartaCampo(0).getAtaque();
						getJugadorActual().addCartaACementerio(0);
					} else {
						getJugadorActual().getCartaCampo(0).setAtaque(getJugadorActual().getCartaCampo(0).getAtaque() - s);
					}
				}
				otro.restarSalud(ataqueJugadorActual - s);
				s = 0;
			}

			if (resultado < 0) {        // El jugador 1 tiene menor ataque
				while (getJugadorActual().getCampo().size() > 0) {
					s += getJugadorActual().getCartaCampo(0).getAtaque();
					getJugadorActual().addCartaACementerio(0);
					if (s > getOtroJugador().getCartaCampo(0).getAtaque()) {
						s -= getOtroJugador().getCartaCampo(0).getAtaque();
						getOtroJugador().addCartaACementerio(0);
					} else {
						getOtroJugador().getCartaCampo(0).setAtaque(getOtroJugador().getCartaCampo(0).getAtaque() - s);
					}
				}

				getJugadorActual().restarSalud(ataqueOtroJugador - s);
				s = 0;
			}

			if (resultado == 0){
				for (int i = 0; i < getJugadorActual().getCampo().size()+1; i++)
					getJugadorActual().addCartaACementerio(0);
				for (int j = 0; j < getOtroJugador().getCampo().size()+1; j++)
					getOtroJugador().addCartaACementerio(0);
			}
		}

		turno++;
	}

	public void ponerCartaCampo(int indice){
		if (numCartasCampo == 0 && (getJugadorActual().getSalud() != 0 && getOtroJugador().getSalud() != 0)){
			jugadores.get(indiceJugadorActual).sacarAlCampo(indice);
			numCartasCampo++;
		}
	}
}