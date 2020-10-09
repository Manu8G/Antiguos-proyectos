package es.practica3ds5.JurassicCards.modelo;

public class Carta {
	private String nombre;
	private int ataque;

	public Carta(String nom, int ata){
		nombre = nom;
		ataque = ata;
	}

	public void setAtaque(int ata){
		ataque=ata;
	}

	public int getAtaque(){
		return ataque;
	}

	@Override
	public String toString(){
		String s = nombre + "\n "+ ataque;
		return s;
	}
}