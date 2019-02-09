package ro.proiectJava;

import java.time.LocalDate;

/**
 * @author Cristina Richter
 *
 */
public class Persoana extends Agenda{
	private String numeP;
	Persoana(String info, LocalDate data, String nume){
		super (info, data);
		this.setNumeP(nume);
	}
	
	public String toString() {
		return super.getInfoIntrare() + " " + super.getDataIntrare().format(formatter) + " "+ getNumeP();
	}

	/**
	 * @return the numeP
	 */
	public String getNumeP() {
		return numeP;
	}

	/**
	 * @param numeP the numeP to set
	 */
	public void setNumeP(String numeP) {
		this.numeP = numeP;
	}

}
