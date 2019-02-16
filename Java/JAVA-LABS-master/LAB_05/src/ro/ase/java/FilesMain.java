package ro.ase.java;

//scrierea si citirea din fisier atat binar cat si text
//
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FilesMain {
	
	public static void main(String[] args) {
		
		File f = new File("test.txt");//fisier declarat aici
		String[] values = new String[] {"GIGEL", "POPEL", "IONEL", "DOREL" }; //vector de stringuri
		DataOutputStream dos = null; //obiecte pentru citire/scriere
		DataInputStream dis = null;
		try {//mecanism tip try catch
			FileWriter fw = new FileWriter(f);
			for(String s : values) {//for each parcurs valorile 
				fw.write(s+",");//obiect _> scris stringul si separat prin virgula
			}
			fw.close();//obiectele filewriter trebuie inchise
			System.out.println("S-a scris in fisier"); //afisez mesaj ca s-a scris in fisier
			
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line = br.readLine();
			String[] words = line.split(","); //line.split(","); aici e separatorul
			for(String s : words) {//pentru ca ultimul string e gol
				if(!s.equals(""))
				System.out.println(s);
			}
			br.close();//inchid obiectele de input si output
			fr.close();
			
			//Scriere in fisier binar
			
			FileOutputStream fos = new FileOutputStream("test1.txt");
			BufferedOutputStream bos = new BufferedOutputStream(fos);
			dos = new DataOutputStream(bos);
			
			dos.writeInt(400);
			dos.writeInt(600);
			
			dos.close();
			bos.close();
			fos.close();
			
			dis = new DataInputStream(new BufferedInputStream(new FileInputStream("test1.txt")));
			System.out.println(dis.readInt());
			System.out.println(dis.readInt());
			
			dis.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
	}
}
