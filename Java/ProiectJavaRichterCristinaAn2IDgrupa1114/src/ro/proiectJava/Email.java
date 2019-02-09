package ro.proiectJava;

import java.time.LocalDate;

public class Email extends Agenda{

	private String emailE;
	Email(String info, LocalDate data, String email){
		super (info, data);
		this.setEmailE(email);
	}
	
	public String toString() {
		return super.getInfoIntrare() + " " + super.getDataIntrare().format(formatter) + " "+ getEmailE();
	}

	/**
	 * @return the emailE
	 */
	public String getEmailE() {
		return emailE;
	}

	/**
	 * @param emailE the emailE to set
	 */
	public void setEmailE(String emailE) {
		this.emailE = emailE;
	}
}
