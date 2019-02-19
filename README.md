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

Citim si celelalte 2 caracteristici: pret_bilet si nr_vizitatori
