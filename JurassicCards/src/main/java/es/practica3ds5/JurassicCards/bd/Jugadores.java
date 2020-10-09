package es.practica3ds5.JurassicCards.bd;

import es.practica3ds5.JurassicCards.modelo.Jugador;
import org.springframework.stereotype.Repository;
import java.util.ArrayList;

@Repository
public class Jugadores {
	private ArrayList<Jugador> jugadores;

	public Jugadores(){
		jugadores = new ArrayList<>();
	}
}