package ro.proiectJava;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.LinkedList;
import java.util.Scanner;

public class Agenda {
	private LocalDate dataIntrare;
	private String infoIntrare;

	public static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

	public Agenda() {
		this.dataIntrare = null;
		this.infoIntrare = null;
	}

	public Agenda(String info) {
		this.dataIntrare = LocalDate.now();
		this.infoIntrare = info;
	}

	public Agenda(String info, LocalDate data) {
		this.dataIntrare = data;
		this.infoIntrare = info;
	}

	public LocalDate getDataIntrare() {
		return this.dataIntrare;
	}

	public String getInfoIntrare() {
		return this.infoIntrare;
	}

	public void setInfoIntrare(String info) {
		if (info.length() < 3)
			throw new IllegalArgumentException("Lungimea informatiei introduse trebuie sa fie mai mare de 3");
		else
			this.infoIntrare = info;
	}

	public void setDataIntrare(String data) {
		if (data.matches("^\\d?\\d{2}/\\d{2}/\\d{4}$")) {
			this.dataIntrare = LocalDate.parse(data, formatter);
		} else
			throw new IllegalArgumentException("Data furnizata invalida");
	}

	protected FileWriter creazaFileWriter(String numeFisier) throws IOException {
		File f = new File(numeFisier);
		FileWriter fw = new FileWriter(f);
		return fw;
	}

	public static BufferedReader creazaFileReader(String numeFisier) throws FileNotFoundException {
		FileReader fr = new FileReader(numeFisier);
		BufferedReader br = new BufferedReader(fr);
		return br;
	}

	public static void importaFisier(BufferedReader br, LinkedList<Agenda> lista) throws IOException {
		String linie;
		while ((linie = br.readLine()) != null) {
			String[] stringuri = linie.split(",");
			LocalDate data = LocalDate.parse(stringuri[1], formatter);
			Agenda a = new Agenda(stringuri[0], data);
			lista.add(a);
		}
		br.close();
	}

	public String toString() {
		return this.infoIntrare + " " + this.dataIntrare.format(formatter);
	}

	public static void main(String[] args) {
		LinkedList<Agenda> lista = new LinkedList<Agenda>();
		try {
			BufferedReader br = Agenda.creazaFileReader("agenda.txt");
			Agenda.importaFisier(br, lista);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		Scanner reader = new Scanner(System.in);
		try {
			int alegere = 0;
			do {
				System.out.println("Meniu");
				System.out.println("1. Adauga o intrare in agenda");
				System.out.println("2. Afiseaza lista");
				System.out.println("3. Adauga programare");
				System.out.println("4. Exporta in fisier");
				System.out.println("5. Cauta dupa data");
				System.out.println("6. Adauga adresa");
				System.out.println("7. Adauga telefon");
				System.out.println("8. Adauga email");
				System.out.println("9. Iesire din aplicatie");
				System.out.println("Alegeti una din optiuni: ");
				alegere = reader.nextInt();

				switch (alegere) {
				case 1://introducere date
					try {
						Agenda a = new Agenda();
						System.out.println("Introduceti informatiile programarii: ");
						String info = reader.next();
						a.setInfoIntrare(info);
						System.out.println("Introduceti data: ");
						String data = reader.next();
						a.setDataIntrare(data);
						lista.add(a);
					} catch (IllegalArgumentException exception) {
						System.out.println(exception.getMessage());
					}

					break;
				case 2://afisare
					System.out.println("Lista: ");
					for (Agenda agend : lista) {
						System.out.println(agend);
					}
					break;
				case 3://persoana
					System.out.println("Introduceti informatiile programarii: ");
					String info = reader.next();
					System.out.println("Introduceti data: ");
					String data = reader.next();
					LocalDate z = LocalDate.parse(data, formatter);
					System.out.println("Introduceti numele persoanei: ");
					String nume = reader.next();
					Persoana p = new Persoana(info, z, nume);
					lista.add(p);
					System.out.println("Persoana a fost introdusa.");
					break;
				case 4://scrie in txt
					Agenda a = new Agenda();
					try {
						FileWriter fw = a.creazaFileWriter("agenda.txt");
						for (Agenda ag : lista) {
							fw.write(ag.getInfoIntrare() + ",");
							fw.write(ag.getDataIntrare().format(formatter));
							fw.write(System.lineSeparator());
						}
						fw.close();
					} catch (IOException IOe) {
						System.out.println(IOe.getMessage());
					}
					break;
				case 5://data programarii
					System.out.println("Introduceti data programarii in agenda: ");
					String dataI = reader.next();
					LocalDate d = LocalDate.parse(dataI, formatter);
					for (Agenda agen : lista) {
						if (agen.getDataIntrare().equals(d)) {
							System.out.println(agen);
						}
					}
				case 6: //Adresa
					System.out.println("Introduceti informatiile programarii: ");
					String infoAdr = reader.next();
					System.out.println("Introduceti data: ");
					String dataAdr = reader.next();
					LocalDate adr = LocalDate.parse(dataAdr, formatter);
					System.out.println("Introduceti adresa: ");
					String adresa = reader.next();
					Adresa adress = new Adresa(infoAdr, adr, adresa);
					lista.add(adress);
					System.out.println("Adresa introdusa.");
					break;
					
				case 7: //Telefon
					System.out.println("Introduceti informatiile programarii: ");
					String infoTel = reader.next();
					System.out.println("Introduceti data: ");
					String dataTel = reader.next();
					LocalDate tel = LocalDate.parse(dataTel, formatter);
					System.out.println("Introduceti adresa: ");
					String telefon = reader.next();
					Telefon phone = new Telefon(infoTel, tel, telefon);
					lista.add(phone);
					System.out.println("telefonul introdus.");
					break;
				case 8: //Email
					System.out.println("Introduceti informatiile programarii: ");
					String infoEm = reader.next();
					System.out.println("Introduceti data: ");
					String dataEm = reader.next();
					LocalDate em = LocalDate.parse(dataEm, formatter);
					System.out.println("Introduceti emailul: ");
					String email = reader.next();
					Email mail = new Email(infoEm, em, email);
					lista.add(mail);
					System.out.println("Emailul a fost introdus.");
					break;
				case 9:
					System.out.println("Aplicatia s-a inchis cu succes.");
					break;
				default:
					System.out.println("Optiune incorecta.");
					break;
				}
			} while (alegere != 9);
		} finally {
			reader.close();
		}
	}

}
