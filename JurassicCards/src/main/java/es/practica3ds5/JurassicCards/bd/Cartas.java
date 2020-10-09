package es.practica3ds5.JurassicCards.bd;

import es.practica3ds5.JurassicCards.modelo.Carta;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;

@Repository
public class Cartas {

	private ArrayList<Carta> cartas;

	public Cartas(){
		cartas = new ArrayList<>();
	}

	public ArrayList<Carta> crearMazo(){
		cartas.add(new Carta("Gorgosauurs", 15));
		cartas.add(new Carta("Saltasaurus", 12));
		cartas.add(new Carta("Ornithomimus", 10));
		cartas.add(new Carta("Chirostenotes", 11));
		cartas.add(new Carta("Acrocanthosaurus", 16));
		cartas.add(new Carta("Ceratosaurus", 16));
		cartas.add(new Carta("Sarcosaurus", 14));
		cartas.add(new Carta("Barosaurus", 15));
		cartas.add(new Carta("Brachiosaurus", 20));
		cartas.add(new Carta("Giraffatitan", 17));
		cartas.add(new Carta("Dilophosaurus", 16));
		cartas.add(new Carta("Ichthyosaurus", 13));
		cartas.add(new Carta("Plateosaurus", 11));
		cartas.add(new Carta("Cynognathus", 10));
		cartas.add(new Carta("ProcompSognathus", 9));
		cartas.add(new Carta("Carnotaurus", 19));
		cartas.add(new Carta("Pteranodon", 16));
		cartas.add(new Carta("Eoraptor", 8));
		cartas.add(new Carta("Herrerasaurus", 14));
		cartas.add(new Carta("Ornitholestes", 11));
		cartas.add(new Carta("Maiasaura", 15));
		cartas.add(new Carta("Styracosaurus", 14));
		cartas.add(new Carta("Riojasaurus", 16));
		cartas.add(new Carta("Camptosaurus", 14));
		cartas.add(new Carta("Stegosaurus", 16));
		cartas.add(new Carta("Troodon", 9));
		cartas.add(new Carta("Gallimimus", 8));
		cartas.add(new Carta("Abrictosaurus", 8));
		cartas.add(new Carta("Spinosaurus", 20));
		cartas.add(new Carta("Tyrannosaurus Rex", 20));

		return cartas;
	}
}