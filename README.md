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
1.1) ne luam un buffer alocat static
1.2) vom citi in acest buffer
1.3) vom aloca spatiu pe baza acestui buffer

```c
void main() {
  Muzeu muzeu;
  char buffer[20]; // 
  printf ("Nume muzeu: ");                                             //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
}
```

Citim si celelalte 2 caracteristici: pret_bilet 

```c
void main() {
  Muzeu muzeu;
  char buffer[20]; // 
  printf ("Nume muzeu: ");                                             //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
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
  char buffer[20]; // 
  printf ("Nume muzeu: ");                                             //indic user-ului ca trebuie sa introduca numele unui muzeu
  scanf_s("%s", buffer);
  muzeu.nume = (char*) malloc (sizeof(char) * (strlen(buffer) + 1));  // alocam spatiu numelui muzeului
  strcpy_s (muzeu.nume, strlen(buffer) + 1, buffer);
  printf ("Pret bilet intrare: ");
  scanf_s ("%f", &muzeu.pret_bilet);
  printf ("Numar vizitatori: ");
  scanf_s ("%f", &muzeu.nr_vizitatori);
}
```
