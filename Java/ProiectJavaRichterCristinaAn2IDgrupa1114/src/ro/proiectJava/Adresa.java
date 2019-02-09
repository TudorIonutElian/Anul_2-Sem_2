package ro.proiectJava;

import java.time.LocalDate;

/**
 * @author Richter Cristina an 2 ID
 *
 */
public class Adresa extends Agenda {
	private String adresaA;

	Adresa(String info, LocalDate data, String adresa) {
		super(info, data);
		this.setAdresaA(adresa);
	}

	public String toString() {
		return super.getInfoIntrare() + " " + super.getDataIntrare().format(formatter) + " " + getAdresaA();
	}

	/**
	 * @return the adresaA
	 */
	public String getAdresaA() {
		return adresaA;
	}

	/**
	 * @param adresaA the adresaA to set
	 */
	public void setAdresaA(String adresaA) {
		this.adresaA = adresaA;
	}
}
