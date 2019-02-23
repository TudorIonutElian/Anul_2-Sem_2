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

cod complet cu  toate modificarile de mai sus

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
**SOLUTIE:** transmitem muzeul prin pointer.

```c
  void citireMuzeuPrinParametru (Muzeu *pMuzeu){
//add code here
  }

```

tutorial 10 - Lista Simplu Inlantuita - creare nod - inserare la inceput
------------------------------------------------------------------------

Lista spre deosebire de vector nu ocupa o zona contigua de memorie. De aceea pentru a avea acces de la un nod la celalalt, trebuie sa retinem adresa urmatorului nod. La vector nu este nevoie sa se retina adresa urmatorului element deoarece vin unul dupa altul. Ma puteam duce la element direct din memorie.  
  
Lista, neavand o zona contigua de memorie eu trebuie sa retin adresa urmatorului nod pentru a sti cum sa ajung la adresa fiecarui nod.  
  
De aceea, o lista este o insiruire de noduri, si fiecare nod va avea o structura compusa din:  
 - informatia utila. 
 - adresa urmatorului nod. 
 
Aceasta va fi lista simplu inlantuita.

Vom avea o structura




-- inserare la mijloc?? da fac
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
