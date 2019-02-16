/*LISTA SIMPLU INLANTUITA
PARCURGERE LISTA
AFISARE LISTA
STERGERE LISTA
*/

include <iostream>

struct Muzeu {
	char* nume;
	float pret_bilet;
	int nr_vizitatori;
};

Muzeu citireMuzeu() {
	Muzeu muzeu;
	char buffer[20];
	printf("Nume muzeu: "); scanf_s("%s", buffer, 20);
	muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy_s(muzeu.nume, strlen(buffer) + 1, buffer);
	printf("Pret bilet intrare:"); scanf_s("%f", &muzeu.pret_bilet);
	printf("Numar vizitatori:"); scanf_s("%d", muzeu.nr_vizitatori);
}

void afisareMuzeu(Muzeu muzeu) {
	printf("Muzeul %s are %d vizitatori, iar biletul costa %5.2f lei\n", muzeu.nume, muzeu.nr_vizitatori, muzeu.pret_bilet);
}

struct nod {
	Muzeu info; /*informatia utila*/
	nod* next; /*Adresa urmatorului nod*/
};
/*********************/
/*    CREARE  NOD    */
/*INSERARE LA INCEPUT*/
/*********************/
/*
PASI creare nod:
1) creez nodul
2) Ii aloc spatiu
3) Setez cele 2 atribute (info utila si adresa);
4) Retunam adresa unde am creat nodul nostru
*/

nod* creareNod(Muzeu m, nod* urmator) {//prin aceasta metoda INSEREZ LA INCEPUT
	/*1*/nod* nodNou;
	/*2*/nodNou = (nod*)malloc(sizeof(nod));
	/*3. atribut 1*/ nodNou->info = m;//shallow copy - nume e cu pointer
									  /*rezolv problema shallow copy*/
	nodNou->nume = (char*)malloc(sizeof(char)*(strlen(m.nume) + 1));//i-am alocat spatiu
	strcpy_s(nodNou->info.nume, strlen(m.nume) + 1), m.nume);
	/*end rezolv problema shallow copy*/
	/*3. atribut 2*/
	nodNou->next = urmator;
	/*4*/return nodNou;
}

/***************/
/*AFISARE LISTA*/
/***************/

/*functie de afisare a listei -> parametru adresa primului nod*/
//Nu va returna nimic, doar afiseaza

/*1. Parcurg toata lista*/
/*2. Afisez toate informatiile din fiecare nod*/
/* Avem adresa primului nod ne putem muta ca si pointer sa trecem pe la fiecare nod
si sa afisam informatiile de la fiecare nod. cu while atata timp cat cap este diferit de NULL
adica atata timp cat am o adresa in pointerul cap inseamna ca am ce sa afisez.*/

void afisareLista(nod* cap) {
	while (cap) {
		afisareMuzeu(cap->info);
		/*dupa ce am afisat trebuie sa duc pointerul la urmatorul element.*/
		/*adresa urmatorului element este cap->next;*/
		cap = cap->next;//cap primeste valoarea lui cap de next, si astfel eu ma duc la adresa urmatorului nod;
						/*In momentul in care cap a ajuns la null iese din loop si
						s-a terminat metoda de afisare.*/
	}
}

/****************/
/*STERGERE LISTA*/
/****************/

/*1. trec pe la fiecare nod*/
/*2. sterg informatia utila (nume muzeu)*/
/*3. sterg nodurile*/
/*4. returneaza adresa noii liste*/
/*5. cand am sters toata lista vom returna NULL*/

nod* stergereLista(nod* cap) {//puteam sa il numesc si altfel, nu numai cap
	while (cap) {/*cat timp avem adresa la acel pointer*/
				 /*sterg primul info*/
		free(cap->info.nume);
		/*daca ma mut la urmatorul nu mai am acces la urmatorul nod*/
		/*imi iau un alt pointer temporar temp*/
		nod* temp = cap; //acum si temp si cap au aceeasi adresa.
						 /*acum pe cap pot sa il mut la urmatorul nod*/
		cap = cap->next;
		/*in momentul de fata temp pointeaza catre primul    nod din lista mea
		cap  pointeaza catre al doilea nod din lista mea*/
		free(temp);
		/*dupa ce l-am sters pe temp intra din nou in while*/
		/*repet pana cand cap devine null*/
	}
	/*cand ies din while trebuie sa returneze*/
	return NULL;
}

void main() {
	/*declar o lista in main*/
	nod* lista = NULL;
	/*INSERARE LA INCEPUT*/
	lista = creareNod(citireMuzeu(), lista); // primul nod (precedent NULL) -> apoi devine al doilea, apoi al treilea
	lista = creareNod(citireMuzeu(), lista); // nod inserat in fata precedentului -> apoi devine al doilea
	lista = creareNod(citireMuzeu(), lista); // nod inserat in fata precedentului, devine primul

											 /*apelez in main afisareLista()*/
	afisareLista(lista);

	/* am terminat de lucrat cu lista, acum trebuie sa o dezaloc => STEREGERE LISTA*/
	/*apelez in main stergereLista()*/
	lista = stergereLista(lista);

}