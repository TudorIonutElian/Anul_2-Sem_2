# Anul-2-Sem-2

# STRUCTURI DE DATE
-----------------------------

[LINK ZAMFIROIU - GREEN CODE](https://www.youtube.com/channel/UCdEmwULIisEidw3QJuHdotQ/videos)



tutorial 7 - structura 
----------------------

In acest tutorial vom crea o structura, pentru a avea articole in cadrul programului. Vom crea structura "Muzeu".

```c
#include <iostream>

struct Muzeu{
  char* nume;
  float pret_bilet;
  int nr_vizitatori;

};
```

Ne declaram un muzeu in main

```c
void main() {
  Muzeu muzeu;
}
```

Ca sa citim acest muzeu trebuie sa citim fiecare caracteristica in parte (nume, pret_bilet, nr_vizitatori).

Ca sa citim numele acestui muzeu trebuie sa:
1) alocam spatiu (dar nu stim cat spatiu sa alocam)  
1.1) ne luam un buffer alocat static.  
1.2) vom citi in acest buffer.  
1.3) vom aloca spatiu pe baza acestui buffer.  

```c
void main() {
  Muzeu muzeu;
  char buffer[20]; // 1.1
  printf ("Nume muzeu: ");   // indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer, 20); // 1.2
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // 1.3
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
}
```

Citim si celelalte 2 caracteristici: pret_bilet 

```c
void main() {
  Muzeu muzeu;
  char buffer[20]; 
  printf ("Nume muzeu: ");                                             //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer, 20);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  // citesc pret_bilet
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet);
}
```

De ce &muzeu (citit: adresa de muzeu)? Metoda scanf primeste de fapt un pointer la zona de memorie unde trebuie sa modifice. Daca nu i-am da adresa, si i-am face transmisia prin valoare, ar face o copie in stiva de memorie a lui scanf iar dupa modificare, dupa ce se termina metoda scanf, se va sterge acea stiva, si modificare nu va fi vizibila si in main. Si de aceea noi ii dam adresa pentru a face modificarea direct in memoria stack unde este alocat acest pret_bilet.

La buffer nu a trebuit sa ii dam adresa pentru ca buffer este un sir de caractere, si toate sirurile de caractere, toti vectorii in c sunt gestionati de fapt prin pointeri, printr-o adresa. deci buffer este deja o adresa.



si nr_vizitatori
```c
void main() {
  Muzeu muzeu;
  char buffer[20]; 
  printf ("Nume muzeu: ");                                             //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet);
  // citesc numar_vizitatori
  printf ("Numar vizitatori: ");
  scanf_s ("%d", &muzeu.nr_vizitatori);
}
```


Ca sa verificam ca acest muzeu a fost citit corect il afisam.

```c
void main() {
  Muzeu muzeu;
  char buffer[20]; 
  printf ("Nume muzeu: ");                                             //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer, 20);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet); // nu mai dam lungimea pt ca citim un float
  printf ("Numar vizitatori: ");
  scanf_s ("%d", &muzeu.nr_vizitatori); // nu mai dam lungimea pt ca citim un int
  
  // citesc muzeul
  printf ("Muzeul %s are %d vizitatori, iar biletul costa %5.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
}
```
output
``` c
Nume muzeu: Antipa
Pret bilet intrare: 30
Numar vizitatori: 500

Muzeul Antipa are 30 vizitatori, iar biletul costa 30.00 lei.

```

cod complet tutorial 7
```c
#include <iostream>

struct Muzeu{
  char* nume;
  float pret_bilet;
  int nr_vizitatori;
};

void main() {
  Muzeu muzeu;
  char buffer[20]; 
  printf ("Nume muzeu: ");  //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer, 20);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet); // nu mai dam lungimea pt ca citim un float
  printf ("Numar vizitatori: ");
  scanf_s ("%d", &muzeu.nr_vizitatori); // nu mai dam lungimea pt ca citim un int
  
  // citesc muzeul
  printf ("Muzeul %s are %d vizitatori, iar biletul costa %5.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
  
  // sterg spatiul alocat dinamic pentru nume muzeu
  free(muzeu.nume);
}



```


tutorial 8 - Metode de citire a unui articol de tip Muzeu. 
----------------------
I) prin valoare
---------------
1) facem o functie de citire: Muzeu citireMuzeu()  
1.1) Ce va returna? un Muzeu  
1.2) nume metoda/functie citireMuzeu()    


```c
Muzeu citireMuzeu() {
  Muzeu muzeu;
  char buffer[20]; // 
  printf ("Nume muzeu: ");  //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer, 20);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet); // nu mai dam lungimea pt ca citim un float
  printf ("Numar vizitatori: ");
  scanf_s ("%d", &muzeu.nr_vizitatori); // nu mai dam lungimea pt ca citim un int
  
  return muzeu;
}

```

In main ne declaram un muzeu si apelam metoda de citire

``` c
  Muzeu muzeu = citireMuzeu();

```

De asemenea, facem o metoda, afisareMuzeu(), care va primi un parametru de tipul Muzeu.

``` c
  void afisareMuzeu (Muzeu muzeu){
    printf ("Muzeul %s are %d vizitatori, iar biletul costa %5.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
  }
```

Iar in main, vom face doar apelul:

```c
  void main(){
    afisareMuzeu(muzeu);
  }
```

Astfel, codul in main este mult mai simplu, adica:
- stim ca ne declaram un muzeu
- apelam citireMuzeu (deci vom citi un muzeu)
- dupa care il afisam

Ca sa nu lasam memory leak-uri, in main stergem spatiul alocat in HEAP lui nume.

```c
  void main(){
    free (muzeu.nume);
  }
```

cod complet cu toate modificarile de mai sus

```c
#include <iostream>

struct Muzeu{
  char* nume;
  float pret_bilet;
  int nr_vizitatori;
};
  
Muzeu citireMuzeu() {
  Muzeu muzeu;
  char buffer[20]; // 
  printf ("Nume muzeu: ");  //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer, 20);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet); // nu mai dam lungimea pt ca citim un float
  printf ("Numar vizitatori: ");
  scanf_s ("%d", &muzeu.nr_vizitatori); // nu mai dam lungimea pt ca citim un int
  
  return muzeu;
}

 void afisareMuzeu (Muzeu muzeu){
    printf ("Muzeul %s are %d vizitatori, iar biletul costa %5.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
  }
  
 void main(){
    Muzeu muzeu = citireMuzeu();
    afisareMuzeu(muzeu);
    free (muzeu.nume);
 }

```

-----------------
Functia de citire - alta metoda (transmitere prin parametru).   
-----------------
II) prin parametru
------------------
1. creem o noua metoda citireMuzeuPrinParametru()  
2. va fi de tip void (nu are tip returnat)  
3. ca sa transmitem un parametru, sa fie modificat in cadrul functiei, nu vom transmite prin valoare. 
**DACA** transmitem prin valoare se va face o copie pe stiva de memorie a functiei citireMuzeuPrinParametru() iar la sfarsitul functiei stiva se va sterge, iar ceea ce eu am citit nu o sa se modifice. 
**SOLUTIE:** transmitem muzeul prin pointer:  *pMuzeu  *

Pentru ca am void nu returnez nimic. Nu am nevoie sa returnez nimic si pentru ca pMuzeu fiind primit ca pointer se va face modificarea direct in adresa unde este stocat cel ...

```c
  void citireMuzeuPrinParametru (Muzeu *pMuzeu){
    char buffer[20];
    printf("Nume muzeu");
    scanf("%s", buffer);
    pMuzeu->nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
    strcpy(pMuzeu->nume, buffer);
    printf("Pret bilet intrare");
    scanf("%f", &pMuzeu->pret_bilet);
    printf("Vizitatori: ");
    scanf("%s", &pMuzeu->nr_vizitatori);

    // nu returnez nimic pentru ca am void
  }

```

cod complet tutorial 8

``` c
#include <iostream>

struct Muzeu {
	char* nume;
	float pret_bilet;
	int nr_vizitatori;
};

Muzeu citireMuzeu() {
	Muzeu muzeu;
	// citesc muzeu
	char buffer[20];
	printf("Nume muzeu: ");
	scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(muzeu.nume, buffer);
	printf("Pret bilet intrare: ");
	scanf("%f", &muzeu.pret_bilet);
	printf("Vizitatori: ");
	scanf("%d", &muzeu.nr_vizitatori);

	return muzeu; // tip returnat Muzeu
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
	char buffer[20];
	printf("Nume muzeu: ");
	scanf("%s", buffer);
	pMuzeu->nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(pMuzeu->nume, buffer);
	printf("Pret bilet intrare: ");
	scanf("%f", &pMuzeu->pret_bilet);
	printf("Vizitatori: ");
	scanf("%d", &pMuzeu->nr_vizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori, iar biletul costa %.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
}

int main() {
	Muzeu muzeu = citireMuzeu();
	afisareMuzeu(muzeu);
	free(muzeu.nume); // pentru a nu lasa memory leak.
	Muzeu muzeu2;
	citireMuzeuPrinParametru(&muzeu2);
	afisareMuzeu(muzeu2);
	free(muzeu2.nume);
}

```

tutorial 9 - Vector alocat static cu obiecte de tip Muzeu
----------------------------------------------------------

1) declaram tipul elementelor din vectorul nostru : de tip Muzeu ``` Muzeu ```
2) numele vectorului meu vectorMuzee ``` vectorMuzee```
3) ii aloc spatiu pentru 10 muzee ``` vectorMuzee[10]; ```

```c 
int main() {
	Muzeu vectorMuzee[10];
	int numarMuzee = 0;
	vectorMuzee[0]=citireMuzeu();
	numarMuzee++;
	vectorMuzee[1]=citireMuzeu();
	numarMuzee++;
	
	for (int i = 0; i < numarMuzee; i++){
		afisareMuzeu(vectorMuzee[i]);
	}
	
	for (int i = 0; i < numarMuzee; i++) {
		free(vectorMuzee[i].nume);
	}
}

```
pot de asemenea sa citesc de la inceput si cate elemente vreau sa citesc

```c
int main() {
	Muzeu vectorMuzee[10];
	int numarMuzee = 0;
	printf("Numarul de muzee: ");
	scanf("%d", &numarMuzee);
	for (int i = 0; i < numarMuzee; i++) {
		vectorMuzee[i] = citireMuzeu();
	}

	for (int i = 0; i < numarMuzee; i++) {
		afisareMuzeu(vectorMuzee[i]);
	}

	for (int i = 0; i < numarMuzee; i++) {
		free(vectorMuzee[i].nume);
	}
}
```
cod complet tutorial 9

```c
#include <iostream>

struct Muzeu {
	char* nume;
	float pret_bilet;
	int nr_vizitatori;
};

Muzeu citireMuzeu() {
	Muzeu muzeu;
	// citesc muzeu
	char buffer[20];
	printf("Nume muzeu: ");
	scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(muzeu.nume, buffer);
	printf("Pret bilet intrare: ");
	scanf("%f", &muzeu.pret_bilet);
	printf("Vizitatori: ");
	scanf("%d", &muzeu.nr_vizitatori);

	return muzeu; // tip returnat Muzeu
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
	char buffer[20];
	printf("Nume muzeu: ");
	scanf("%s", buffer);
	pMuzeu->nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(pMuzeu->nume, buffer);
	printf("Pret bilet intrare: ");
	scanf("%f", &pMuzeu->pret_bilet);
	printf("Vizitatori: ");
	scanf("%d", &pMuzeu->nr_vizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori, iar biletul costa %.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
}

int main() {

	/*
		Muzeu vectorMuzee[10];
		int numarMuzee = 0;
		vectorMuzee[0]=citireMuzeu();
		numarMuzee++;
		vectorMuzee[1]=citireMuzeu();
		numarMuzee++;

		for (int i = 0; i < numarMuzee; i++){
			afisareMuzeu(vectorMuzee[i]);
		}

		for (int i = 0; i < numarMuzee; i++) {
			free(vectorMuzee[i].nume);
		}
	*/

	Muzeu vectorMuzee[10];
	int numarMuzee = 0;
	printf("Numarul de muzee: ");
	scanf("%d", &numarMuzee);
	for (int i = 0; i < numarMuzee; i++) {
		vectorMuzee[i] = citireMuzeu();
	}

	for (int i = 0; i < numarMuzee; i++) {
		afisareMuzeu(vectorMuzee[i]);
	}

	for (int i = 0; i < numarMuzee; i++) {
		free(vectorMuzee[i].nume);
	}
}

```


Problema la acest vector este ca eu mi-am alocat spatiu pentru 10 elemente. Eu ocup memorie pentru 10 elemente chiar daca eu folosesc 2 sau 3. Folosesc mai multa memorie decat este necesar.

De accea, in tutorialul urmator vom face vector alocat dinamic.



tutorial 10 - Vector alocat dinamic cu obiecte de tip Muzeu
-----------------------------------------------------------

1. declar un pointer unde o sa pun adresa unde o sa aloc spatiu. Declar un pointer la muzeu, deoarece trebuie sa specific ce fel de adresa o sa am eu acolo. Si o sa am un ``` Muzeu* pVectorMuzee ```.  
2. Initial il initializez cu NULL  ``` Muzeu* pVectorMuzee = NULL;```.  
3. Dupa care eu trebuie sa ii aloc spatiu, dar eu trebuie sa stiu pentru cate elemente ii aloc spatiu.  
	3.1 De aceea declar un ``` int numarMuzee;``` pe care o sa-l citesc de la utilizator.  
	3.2 Pe care il citesc de la tastatura  
	
	```c
		printf("Numar muzee: "); 
		scanf("%d", &numarMuzee);
	```
4. Aloc spatiu. Acum stiu cata memorie trebuie sa aloc.
```c
	pVectorMuzee=(Muzeu*)malloc(sizeof(Muzeu) * numarMuzee);
```
5. Incep sa citesc elementele

```c
	for (int i = 0; i < numarMuzee; i++{
		pVectorMuzee[i] = citireMuzee();
	}
```
6. Afisez muzeele citite (parcurg vectorul si apelez metoda de afisare)  
```c
	for (int i = 0; i < numarMuzee; i++){
		afisareMuzeu(pVectorMuzee[i]);
	}
```
7. Dupa ce am terminat lucrul cu vectorul meu trebuie sa dezaloc memoria  
	7.1 mai intai dezaloc memoria pentru nume

	```c
		for (int i = 0; i < numarMuzee; i++) {
			free (pVectorMuzee[i].nume);
		}
	```
	7.2 apoi dezaloc memoria alocata pentru vector

	```c
		free(pVectorMuzee);
	```

cod complet tutorial 10

```c

#include <iostream>

struct Muzeu {
	char* nume;
	float pret_bilet;
	int nr_vizitatori;
};

Muzeu citireMuzeu() {
	Muzeu muzeu;
	// citesc muzeu
	char buffer[20];
	printf("Nume muzeu: ");
	scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(muzeu.nume, buffer);
	printf("Pret bilet intrare: ");
	scanf("%f", &muzeu.pret_bilet);
	printf("Vizitatori: ");
	scanf("%d", &muzeu.nr_vizitatori);

	return muzeu; // tip returnat Muzeu
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
	char buffer[20];
	printf("Nume muzeu: ");
	scanf("%s", buffer);
	pMuzeu->nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(pMuzeu->nume, buffer);
	printf("Pret bilet intrare: ");
	scanf("%f", &pMuzeu->pret_bilet);
	printf("Vizitatori: ");
	scanf("%d", &pMuzeu->nr_vizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori, iar biletul costa %.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
}

int main() {
	//1. declar un pointer la muzeu si il initializez
	Muzeu* pVectorMuzee = NULL;
	//2. ii cer userului numarul de muzee de inserat
	int numarMuzee;
	printf("Numar muzee: ");
	scanf("%d", &numarMuzee);
	//3. aloc spatiu
	pVectorMuzee = (Muzeu*)malloc(sizeof(Muzeu)*numarMuzee);
	//4. citesc elementele
	for (int i = 0; i < numarMuzee; i++) {
		pVectorMuzee[i] = citireMuzeu();
	}
	//5. afisez elementele citite
	for (int i = 0; i < numarMuzee; i++) {
		afisareMuzeu(pVectorMuzee[i]);
	}
	//6. sterg memoria alocata pentru nume
	for (int i = 0; i < numarMuzee; i++) {
		free(pVectorMuzee[i].nume);
	}
	//7. sterm memoria alocata pentru vector
	free(pVectorMuzee);

}
```


tutorial 11 - Matrice alocata dinamic cu elemente de tip Muzeu
--------------------------------------------------------------

Matrice de muzee  

Daca vrem sa avem o matrice trebuie sa ne declaram un pointer la pointer la muzeu. ```Muzeu**```   
**De ce pointer la pointer?**   
Declaram un vector de pointeri. Dupa care la fiecare pointer din vectorul de pointeri, vom declara un vector de muzee.  
Deci, 
- primul pointer ``` * ``` va fi pentru adresa unde am vectorul de pointeri.  
- al doilea pointer ``` * ``` va fi adresa unde am vectorul de elemente de tip Muzeu  

cod complet tutorial 11

``` c
#include <iostream>

struct Muzeu {
	char* nume;
	float pretBilet;
	int nrVizitatori;
};

Muzeu citireMuzeuPrinValoare() {
	Muzeu muzeu;

	char buffer[20];
	printf("Nume muzeu: "); scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
	strcpy(muzeu.nume, buffer);

	printf("Pret bilet: "); scanf("%f", &muzeu.pretBilet);
	printf("Numar vizitatori: "); scanf("%d", &muzeu.nrVizitatori);

	return muzeu;
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
	char buffer[20];
	printf("Nume muzeu: "); scanf("%s", buffer);
	pMuzeu->nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
	strcpy(pMuzeu->nume, buffer);
	printf("Pret bilet: "); scanf("%f", &pMuzeu->pretBilet);
	printf("Numar vizitatori: "); scanf("%d", &pMuzeu->nrVizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori iar pretul biletului este de %.2f lei", muzeu.nume, muzeu.nrVizitatori, muzeu.pretBilet);
}

Muzeu** citireMatrice(int *n, int *m) {
	printf("Numarul de linii: "); scanf("%d", n); // nu mai trebuie sa ii dau adresa lui n, deoarece n este o adresa
	printf("Numarul de coloane: "); scanf("%d", m);// nu mai trebuie sa ii dau adresa lui m, deoarece n este o adresa

	//declar matricea
	Muzeu ** matrice;
	//aloc vectorul de pointer
	matrice = (Muzeu**)malloc(sizeof(Muzeu*)*(*n)); //trebuie sa dereferentiez n pentru ca n este o adresa: *n
	//aloc fiecare vector de muzee
	for (int i = 0; i < *n; i++) {
		//aloc pt fiecare pointer => matrice[i] este un pointer la muzeu
		matrice[i] = (Muzeu*)malloc(sizeof(Muzeu)*(*m)); //am alocat pentru fiecare n linii cate m elemente pentru fiecare.
	}
	//citesc matricea - o parcurg pe linii si pe coloane
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			//citesc
			matrice[i][j] = citireMuzeuPrinValoare();
		}
	}
	return matrice;
}

int main() {
	//1. matrice: pointer la pointer la muzeu
	 /*vector de pointer, apioi la fiecare pointer vector de muzee*/
	Muzeu** matrice;
	/*trebuie sa stim numarul de linii si numarul de coloane*/
	int nrLinii = 0; // numarul de elemente di vectorul de pointeri
	// pentru fiecare linie trebuie sa stim numarul de elemente de tip muzeu din fiecare vectori
	int nrColoane = 0;
	// realize o functi care sa citeasca numarul de linii si de coloane
	matrice = citireMatrice(&nrLinii, &nrColoane); //transmit numarul de linii prin adresa
		//afisam matricea

	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			afisareMuzeu(matrice[i][j]); printf("\t");
		}
		printf("\n");
	}
	//dezaloc spatiu
	//1. dezaloc numele tuturor coloanelor
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			free(matrice[i][j].nume); //sterg nume
		}
		//dezaloc pointer la muzeu
		free(matrice[i]);
	}
	//3. eliberez matricea
	free(matrice);
}

```


tutorial 12 - Lista Simplu Inlantuita - creare nod - inserare la inceput
------------------------------------------------------------------------

Lista spre deosebire de vector nu ocupa o zona contigua de memorie. De aceea pentru a avea acces de la un nod la celalalt, trebuie sa retinem adresa urmatorului nod. La vector nu este nevoie sa se retina adresa urmatorului element deoarece vin unul dupa altul. Ma puteam duce la element direct din memorie.  
  
Lista, neavand o zona contigua de memorie eu trebuie sa retin adresa urmatorului nod pentru a sti cum sa ajung la fiecare nod.  
  
De aceea, o lista este o insiruire de noduri, si fiecare nod va avea o structura compusa din:  
 - informatia utila. 
 - adresa urmatorului nod. 
 
Aceasta va fi lista simplu inlantuita.

Vom avea o structura: 

```c
struct
```

o vom numi chiar nod

```c
struct nod
```

In aceasta structura noi vom avea informatia utila: structura Muzeu.  
Deci vom avea un Muzeu pe care il vom numi "info". (eu l-am numit informatieUtila).  
Dar fiecare nod trebuie sa aiba si adresa urmatorului nod. Voi avea un nod, dar ma intereseaza adresa acestuia.  

```c
struct nod {
  Muzeu informatieUtila;
  nod* next;
};
```

cod complet tutorial 12

```c
#include <iostream>

struct Muzeu {
	char* nume;
	float pretBilet;
	int nrVizitatori;
};

Muzeu citireMuzeuPrinValoare() {
	Muzeu muzeu;

	char buffer[20];
	printf("Nume muzeu: "); scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
	strcpy(muzeu.nume, buffer);

	printf("Pret bilet: "); scanf("%f", &muzeu.pretBilet);
	printf("Numar vizitatori: "); scanf("%d", &muzeu.nrVizitatori);

	return muzeu;
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
	char buffer[20];
	printf("Nume muzeu: "); scanf("%s", buffer);
	pMuzeu->nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
	strcpy(pMuzeu->nume, buffer);
	printf("Pret bilet: "); scanf("%f", &pMuzeu->pretBilet);
	printf("Numar vizitatori: "); scanf("%d", &pMuzeu->nrVizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori iar pretul biletului este de %.2f lei", muzeu.nume, muzeu.nrVizitatori, muzeu.pretBilet);
}

Muzeu** citireMatrice(int *n, int *m) {
	printf("Numarul de linii: "); scanf("%d", n); // nu mai trebuie sa ii dau adresa lui n, deoarece n este o adresa
	printf("Numarul de coloane: "); scanf("%d", m);// nu mai trebuie sa ii dau adresa lui m, deoarece n este o adresa

	//declar matricea
	Muzeu ** matrice;
	//aloc vectorul de pointer
	matrice = (Muzeu**)malloc(sizeof(Muzeu*)*(*n)); //trebuie sa dereferentiez n pentru ca n este o adresa: *n
	//aloc fiecare vector de muzee
	for (int i = 0; i < *n; i++) {
		//aloc pt fiecare pointer => matrice[i] este un pointer la muzeu
		matrice[i] = (Muzeu*)malloc(sizeof(Muzeu)*(*m)); //am alocat pentru fiecare n linii cate m elemente pentru fiecare.
	}
	//citesc matricea - o parcurg pe linii si pe coloane
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			//citesc
			matrice[i][j] = citireMuzeuPrinValoare();
		}
	}
	return matrice;
}

struct nod {
	Muzeu info; //informatia utila
	nod* next;	//adresa urmatorului nod
};

// lista e o insiruire de astfel de noduri

//inserare la inceput
nod* creareNod(Muzeu m, nod* urmator) { //noi avem functia care ne creeaza un nod si ne va returna adresa acestuia
	nod* nodNou; //creez un nod nou
	nodNou = (nod*)malloc(sizeof(nod)); //aloc spatiu
	nodNou->info = m;//setam atributele -> problema: shallow copy +> rezolv cu urmatoarea linie (tratez ce face shallow copy)
	nodNou->info.nume = (char*)malloc(sizeof(char)*strlen(m.nume) + 1);
	strcpy(nodNou->info.nume, m.nume);
	nodNou->next = urmator;
	return nodNou;//returnam aceasta adresa undea am creat acest nod nou
}

int main() {
 /*lista nu ocupa o zona contigua de memorie, de aceea pentru avea acces de la un nod la celalalt trebuie sa retinem adresa celuilalt nod*/
	//lista e o insiruire de noduri si fiecare lista simplu inlantuita are informatia utila si 

	//imi declar o lista
		nod* lista = NULL; //avem o lista goala

		lista = creareNod(citireMuzeuPrinValoare(), lista);
		lista = creareNod(citireMuzeuPrinValoare(), lista); //imi insereaza noul nod la inceput => am inserare la inceput.
		lista = creareNod(citireMuzeuPrinValoare(), lista); //imi insereaza noul nod la inceput => am inserare la inceput.
}
```
tutorial 13 - Lista Simplu Inlantuita - parcurgerea, afisarea si stergerea listei
------------------------------------------------------------------------

tutorial 13 cod complet

```c
#include <iostream>

struct Muzeu {
	char* nume;
	float pretBilet;
	int nrVizitatori;
};

Muzeu citireMuzeuPrinValoare() {
	Muzeu muzeu;

	char buffer[20];
	printf("Nume muzeu: "); scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
	strcpy(muzeu.nume, buffer);

	printf("Pret bilet: "); scanf("%f", &muzeu.pretBilet);
	printf("Numar vizitatori: "); scanf("%d", &muzeu.nrVizitatori);

	return muzeu;
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
	char buffer[20];
	printf("Nume muzeu: "); scanf("%s", buffer);
	pMuzeu->nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
	strcpy(pMuzeu->nume, buffer);
	printf("Pret bilet: "); scanf("%f", &pMuzeu->pretBilet);
	printf("Numar vizitatori: "); scanf("%d", &pMuzeu->nrVizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori iar pretul biletului este de %.2f lei", muzeu.nume, muzeu.nrVizitatori, muzeu.pretBilet);
}

/*
Muzeu** citireMatrice(int *n, int *m) {
	printf("Numarul de linii: "); scanf("%d", n); // nu mai trebuie sa ii dau adresa lui n, deoarece n este o adresa
	printf("Numarul de coloane: "); scanf("%d", m);// nu mai trebuie sa ii dau adresa lui m, deoarece n este o adresa

	//declar matricea
	Muzeu ** matrice;
	//aloc vectorul de pointer
	matrice = (Muzeu**)malloc(sizeof(Muzeu*)*(*n)); //trebuie sa dereferentiez n pentru ca n este o adresa: *n
	//aloc fiecare vector de muzee
	for (int i = 0; i < *n; i++) {
		//aloc pt fiecare pointer => matrice[i] este un pointer la muzeu
		matrice[i] = (Muzeu*)malloc(sizeof(Muzeu)*(*m)); //am alocat pentru fiecare n linii cate m elemente pentru fiecare.
	}
	//citesc matricea - o parcurg pe linii si pe coloane
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			//citesc
			matrice[i][j] = citireMuzeuPrinValoare();
		}
	}
	return matrice;
}
*/

struct nod {
	Muzeu info; //informatia utila
	nod* next;	//adresa urmatorului nod
};

// lista e o insiruire de astfel de noduri

//inserare la inceput
nod* creareNod(Muzeu m, nod* urmator) { //noi avem functia care ne creeaza un nod si ne va returna adresa acestuia
	nod* nodNou; //creez un nod nou
	nodNou = (nod*)malloc(sizeof(nod)); //aloc spatiu
	nodNou->info = m;//setam atributele -> problema: shallow copy +> rezolv cu urmatoarea linie (tratez ce face shallow copy)
	nodNou->info.nume = (char*)malloc(sizeof(char)*strlen(m.nume) + 1);
	strcpy(nodNou->info.nume, m.nume);
	nodNou->next = urmator;
	return nodNou;//returnam aceasta adresa undea am creat acest nod nou
}

//primesc ca parametru adresa primului nod
void afisarelista(nod* cap) {
	//parcurg toata lista si afisez informatile din fiecare nod
	while (cap != NULL) {
		afisareMuzeu(cap->info); //atata timp cat am o adresa la pointerul cap inseamna ca am ce sa afisez, si afisez
		//duc pointerul la urmatorul element, adresa urmatorului element este cap->next (cap de next)
		cap = cap->next;
		printf("\n");
	}
}

nod* stergereLista(nod* cap) {
	while (cap) {
		free(cap->info.nume);
		nod* temp = cap;
		cap = cap->next;
		free(temp);
	}
	return NULL;
}

int main() {
 /*lista nu ocupa o zona contigua de memorie, de aceea pentru avea acces de la un nod la celalalt trebuie sa retinem adresa celuilalt nod*/
	//lista e o insiruire de noduri si fiecare lista simplu inlantuita are informatia utila si 

	//imi declar o lista
		nod* lista = NULL; //avem o lista goala

		lista = creareNod(citireMuzeuPrinValoare(), lista);
		lista = creareNod(citireMuzeuPrinValoare(), lista); //imi insereaza noul nod la inceput => am inserare la inceput.
		lista = creareNod(citireMuzeuPrinValoare(), lista); //imi insereaza noul nod la inceput => am inserare la inceput.

		afisarelista(lista);
		//dezaloc
		//1. trec pe la fiecare nod si sterg informatia utila si abia apoi sterg nodurile
		lista = stergereLista(lista);
}
```


tutorial 14 - Lista Simplu Inalntuita - Inserare la sfarsit
------------------------------------------------------------


cod complet tutorial 14

```c

#include <iostream>

struct Muzeu {
  char* nume;
  float pretBilet;
  int nrVizitatori;
};

Muzeu citireMuzeuPrinValoare() {
  Muzeu muzeu;
  
  char buffer[20];
  printf("Nume muzeu: "); scanf("%s", buffer);
  muzeu.nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
  strcpy(muzeu.nume, buffer);
  
  printf("Pret bilet: "); scanf("%f", &muzeu.pretBilet);
  printf("Numar vizitatori: "); scanf("%d", &muzeu.nrVizitatori);
  
  return muzeu;
}

void citireMuzeuPrinParametru(Muzeu *pMuzeu) {
  char buffer[20];
  printf("Nume muzeu: "); scanf("%s", buffer);
  pMuzeu->nume = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
  strcpy(pMuzeu->nume, buffer);
  printf("Pret bilet: "); scanf("%f", &pMuzeu->pretBilet);
  printf("Numar vizitatori: "); scanf("%d", &pMuzeu->nrVizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
  printf("Muzeul %s are %d vizitatori iar pretul biletului este de %.2f lei", muzeu.nume, muzeu.nrVizitatori, muzeu.pretBilet);
}


struct nod {
  Muzeu info; //informatia utila
  nod* next;  //adresa urmatorului nod
};

// lista e o insiruire de astfel de noduri


//inserare la inceput
nod* creareNod(Muzeu m, nod* urmator) { //noi avem functia care ne creeaza un nod si ne va returna adresa acestuia
  nod* nodNou; //creez un nod nou
  nodNou = (nod*)malloc(sizeof(nod)); //aloc spatiu
  nodNou->info = m;//setam atributele -> problema: shallow copy +> rezolv cu urmatoarea linie (tratez ce face shallow copy)
  nodNou->info.nume = (char*)malloc(sizeof(char)*strlen(m.nume) + 1);
  strcpy(nodNou->info.nume, m.nume);
  nodNou->next = urmator;
  return nodNou;//returnam aceasta adresa undea am creat acest nod nou
}

//primesc ca parametru adresa primului nod
void afisarelista(nod* cap) {
  //parcurg toata lista si afisez informatile din fiecare nod
  while (cap != NULL) {
    afisareMuzeu(cap->info); //atata timp cat am o adresa la pointerul cap inseamna ca am ce sa afisez, si afisez
    //duc pointerul la urmatorul element, adresa urmatorului element este cap->next (cap de next)
    cap = cap->next;
    printf("\n");
  }
}

nod* stergereLista(nod* cap) {
  while (cap) {
    free(cap->info.nume);
    nod* temp = cap;
    cap = cap->next;
    free(temp);
  }
  return NULL;
}

nod* inserareSfarsit(nod* cap, Muzeu m){
  //1. verific daca am sau nu lista, daca pointerul cap are o adresa
  if (cap){ // daca e diferit de 0 inseamna ca avem o lista
    //ne ducem la ultimul nod si sa inseram acolo un nou nod.
    // ca sa ne deplasam la sfarsitul listei nu ne vom deplasa cu cap, trebuie sa ne luam un alt pointer
    nod* p = cap;
    while (p->next){ //cat timp exista p-> next, eu ma deplasez
      p= p->next;
    }
    //creez un nou nod si il inserez aici
    //salvez adresa noului nod in p->next
    p->next=creareNod(m, NULL);
    return cap; //adresa primului nod
  }
  else {//nu exista cap, cap este null
    return creareNod(m, NULL); // lista mea va avea un singur nod, creat acums
  }
}
  

int main() {
  /*lista nu ocupa o zona contigua de memorie, de aceea pentru avea acces de la un nod la celalalt trebuie sa retinem adresa celuilalt nod*/
  //lista e o insiruire de noduri si fiecare lista simplu inlantuita are informatia utila si
  
  //imi declar o lista
  nod* lista = NULL; //avem o lista goala
  
//  lista = creareNod(citireMuzeuPrinValoare(), lista);
//  lista = creareNod(citireMuzeuPrinValoare(), lista); //imi insereaza noul nod la inceput => am inserare la inceput.
//  lista = creareNod(citireMuzeuPrinValoare(), lista); //imi insereaza noul nod la inceput => am inserare la inceput.
//
//  afisarelista(lista);
  //dezaloc
  //1. trec pe la fiecare nod si sterg informatia utila si abia apoi sterg nodurile
//  s lista = stergereLista(lista);
  
  lista = inserareSfarsit(lista, citireMuzeuPrinValoare());
  lista = inserareSfarsit(lista, citireMuzeuPrinValoare());
  lista = inserareSfarsit(lista, citireMuzeuPrinValoare());
  
  afisarelista(lista);
  lista=stergereLista(lista);
}

```

tutorial 15 - Lista Dublu Inlantuita - Conceptul de lista dubla
---------------------------------------------------------------
Lista dublu inlantuita, pe langa **informatia utila** din acel nod si **adresa urmatorului nod** vom avea si **adresa precedentului nod**.

Acest lucru ne va permite sa facem parcurgerea atat in mod normal cat si sa parcurgem in sens invers, de la sfarsit catre inceput. 

![LDI](https://github.com/CristinaRichter1/Anul_2-Sem_2/blob/master/Imagini%20an%202%20sem%202/LDI.PNG)

in cazul LDI este nevoie sa salvam adresa primului nod si adresa ultimului nod. Pentru a face acest lucru trebuie sa creem o structura care contine: FIRST: adresa primului nod, si LAST, adresa ultimului nod.  
Daca este sa am un obiect de acest tip, si vreau sa parcurg lista mea de la inceput spre sfarsit, ma duc la first si parcurg in mod normal, deplasandu-ma cu next.  
Daca vreau sa parcurg lista in sens invers, de la sfarsit catre inceput, ma duc la last, la ultimul nod si parcurg lista in sens invers, deplasandu-ma cu ajutorul lui prev.  

def: LDI este o insiruire de noduri, in fiecare nod am informatia utila, adresa urmatorului nod cat si adresa nodului precedent. Foarte important este ca acum vom avea o structura pentru informatia utila (pentru nod) si inca o structura pentru informatiile legate de adresele primului si ultimului nod.  

----------------


-- inserare la mijloc
while (P-> adr-> info < inf(8)
2) creez un nou nod, info utila 8
3) nu -> adr = p-> adr
4) p-> adr = nou


stergere elemente
1) ne pozitionam pe nodul anterior nodului de sters
2) conditia -> daca nodul urmatoar are valoarea noastra
3) salvam adresa intr-un aux
4) faci legatura
5) apoi sterg

liste duble (presupune sa aiba si adresa nodului precedent)
Daca vrem sa inseram la inceput
1) creem nodul nou
2) precedentul este  null
3) nextul  pointeaza catre cap
4) previous de la cap pointeaza catre adresa nodului nou
5) se mai adauga un nod in care salvam doar adresele de inceput si de sfarsit

inserare la mijloc

extragere
1) determinam mai intai nodul, ne oprim exact pe nodul pe care vreau sa il extrag
2) trebuie sa fac legaturile 


Stive si cozi
-----------------
stiva (last in first out) ultimul element introdus este primul pe care il scot. Lucrez la un capat. daca fac inserare la inceput fac extragere la inceput; daca fac inserare la sfarsit extragerea o fac tot la sfarsit.

coada (first in first out) fac inserare la un capat automat extragerea la sfarsit , sau invers.


23/24 februarie intalnire (ne anunta pe platforma)
13/14 aprilie o noua intalnire


La arbori binari se salveaza adresa nodului root. Ce e la adresa 
