package ro.proiect;

import java.time.LocalDate;

public class Programator extends angajat {
	private final String limbajP;
	
	Programator(String nume, LocalDate data, String limbaj){
		super(nume,data);
		this.limbajP = limbaj;
	}
	
	public String toString() {
		return super.getNume() + " " + super.getDataAngajare().format(formatter);
	}
}
