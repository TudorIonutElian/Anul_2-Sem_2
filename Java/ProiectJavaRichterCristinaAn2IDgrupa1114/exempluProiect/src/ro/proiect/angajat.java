package ro.proiect;

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

public class angajat {
	private LocalDate dataAngajare;
	private String nume;
	public static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
	
	public angajat() {
		this.dataAngajare = null;
		this.nume = null;
	}
	
	public angajat(String num){
		this.dataAngajare = LocalDate.now();
		this.nume = num;
	}
	
	public angajat(String num, LocalDate data) {
		this.dataAngajare = data;
		this.nume = num;
	}
	
	public LocalDate getDataAngajare() {
		return this.dataAngajare;
	}
	
	public String getNume() {
		return this.nume;
	}
	
	public void setNume(String nume) {
		if(nume.length()<3) throw new IllegalArgumentException("Lungimea numelui este mai mica de 3");
		else 
			this.nume = nume;
	}
	
	public void setDataAngajare(String data) {
		if(data.matches("^\\d?\\d{2}/\\d{2}/\\d{4}$")) {
			this.dataAngajare = LocalDate.parse(data,formatter);
		} else throw new IllegalArgumentException("Data invalida.");
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
	
	public static void importaFisier(BufferedReader br,LinkedList<angajat> lista) throws IOException {
		String linie;
		while((linie = br.readLine())!= null) {
			String[] stringuri = linie.split(",");
			LocalDate data = LocalDate.parse(stringuri[1],formatter);
			angajat a = new angajat(stringuri[0],data);
			lista.add(a);
		}
		br.close();
	}
	
	public String toString() {
		return this.nume + " " + this.dataAngajare.format(formatter);
	}
	
	
	
	
	public static void main(String[] args) {
		LinkedList<angajat> lista = new LinkedList<angajat>();
		try {
			BufferedReader br = angajat.creazaFileReader("text.txt");
			angajat.importaFisier(br, lista);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		Scanner reader = new Scanner(System.in);
		int alegere = 0;
		do {
			System.out.println("Meniu");
			System.out.println("1. Adauga un angajat");
			System.out.println("2. Afiseaza lista");
			System.out.println("3. Iesire din aplicatie");
			System.out.println("4. Adauga programator");
			System.out.println("5. Exporta in fisier");
			System.out.println("6. Cauta dupa data");
			System.out.println("Alegeti una din optiuni: ");
			alegere = reader.nextInt();
			switch(alegere) {
			case 1:
				try {
					angajat a = new angajat();
					System.out.println("Introduceti numele: ");
					String nume = reader.next();
					a.setNume(nume);
					System.out.println("Introduceti data: ");
					String data = reader.next();
					a.setDataAngajare(data);
					lista.add(a);
				} catch(IllegalArgumentException iae) {
					System.out.println(iae.getMessage());
				}
				
				break;
			case 2:
				System.out.println("Lista: ");
				for(angajat ang:lista) {
					System.out.println(ang);
				}
				break;
			case 3:
				System.out.println("Programul s-a inchis.");
				break;
			case 4:
				System.out.println("Introduceti numele: ");
				String nume = reader.next();
				System.out.println("Introduceti data: ");
				String data = reader.next();
				LocalDate d = LocalDate.parse(data,formatter);
				System.out.println("Introduceti limbaj: ");
				String limbaj = reader.next();
				Programator p = new Programator(nume,d,limbaj);
				lista.add(p);
				break;
			case 5:
				angajat a = new angajat();
				try {
					FileWriter fw = a.creazaFileWriter("text.txt");
					for (angajat ang:lista) {
						fw.write(ang.getNume()+",");
						fw.write(ang.getDataAngajare().format(formatter));
						fw.write(System.lineSeparator());
					}
					fw.close();
				} catch (IOException ioe) {
					System.out.println(ioe.getMessage());
				}
				break;
			case 6:
				System.out.println("Introduceti data angajarii: ");
				String dataS = reader.next();
				LocalDate v = LocalDate.parse(dataS,formatter);
				for (angajat angj:lista) {
					if(angj.getDataAngajare().equals(v)) {
						System.out.println(angj);
					}
				}
			default:
				System.out.println("Alegeti alta optiune");
				break;
			}			
		} while (alegere != 3);

	}

}
