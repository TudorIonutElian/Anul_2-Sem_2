package ro.proiectJava;

import java.time.LocalDate;

/**
 * @author Cristina Richter an 2 ID, gr. 1114
 *
 */
public class Telefon extends Agenda {

	private String TelefonT;

	Telefon(String info, LocalDate data, String telefon) {
		super(info, data);
		this.setTelefonT(telefon);
	}

	public String toString() {
		return super.getInfoIntrare() + " " + super.getDataIntrare().format(formatter) + " " + String.valueOf(getTelefonT());
	}

	/**
	 * @return the telefonT
	 */
	public String getTelefonT() {
		return TelefonT;
	}

	/**
	 * @param telefonT
	 *            the telefonT to set
	 */
	public void setTelefonT(String telefonT) {
		TelefonT = telefonT;
	}
}
