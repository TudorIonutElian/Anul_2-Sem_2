#include<iostream>

struct Muzeu {
	char* nume;
	int nr_expozitii;
	float pret_bilet;
};



Muzeu citesteMuzeu() {
	Muzeu muzeu;
	char buffer[20];
	printf("Nume:");
	scanf("%s", buffer);
	muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(muzeu.nume, buffer);
	printf("Numar expozitii:");
	scanf("%d", &muzeu.nr_expozitii);
	printf("Pret bilet:");
	scanf("%f", &muzeu.pret_bilet);

	return muzeu;
}

void afisareMuzeu(Muzeu m) {
	printf("Muzeul %s are %d expozitii, iar biletul costa %5.2f\n",
		m.nume, m.nr_expozitii, m.pret_bilet);
}

struct nod {
	nod*next;
	nod*prev;
	Muzeu info;
};

struct ListaDubla {
	nod*first;
	nod*last;
};

ListaDubla inserareInceput(ListaDubla ld, Muzeu m) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(m.nume) + 1));
	strcpy(nou->info.nume, m.nume);
	nou->info.nr_expozitii = m.nr_expozitii;
	nou->info.pret_bilet = m.pret_bilet;
	nou->prev = NULL;
	if (ld.first) {
		nou->next = ld.first;
		ld.first->prev = nou;
		ld.first = nou;
	}
	else {
		ld.first = ld.last = nou;
		nou->next = NULL;
	}
	return ld;
}

ListaDubla inserareSfarsit(ListaDubla ld, Muzeu m) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(m.nume) + 1));
	strcpy(nou->info.nume, m.nume);
	nou->info.nr_expozitii = m.nr_expozitii;
	nou->info.pret_bilet = m.pret_bilet;
	nou->next = NULL;
	if (ld.last) {
		nou->prev = ld.last;
		ld.last->next = nou;
		ld.last = nou;
	}
	else {
		ld.last = ld.first = nou;
		nou->prev = NULL;
	}
	return ld;
}

void afisareOrdineListaDubla(ListaDubla ld) {
	nod*p = ld.first;
	while (p)
	{
		afisareMuzeu(p->info);
		p = p->next;
	}
}

void afisareINordineListaDubla(ListaDubla ld) {
	nod* p = ld.last;
	while (p) {
		afisareMuzeu(p->info);
		p = p->prev;
	}
}


ListaDubla inserareSortata(ListaDubla ld, Muzeu m) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(m.nume) + 1));
	strcpy(nou->info.nume, m.nume);
	nou->info.nr_expozitii = m.nr_expozitii;
	nou->info.pret_bilet = m.pret_bilet;
	nod*p = ld.first;
	while (p && m.pret_bilet > p->info.pret_bilet) {
		p = p->next;
	}
	if (p) {
		nou->next = p;
		nou->prev = p->prev;
		p->prev = nou;
		if (nou->prev) {
			nou->prev->next = nou;
		}
	}
	else {
		ld = inserareSfarsit(ld, m);
	}
	return ld;
}

ListaDubla inserarePePozitie(ListaDubla ld, Muzeu m, int pozitie) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(m.nume) + 1));
	strcpy(nou->info.nume, m.nume);
	nou->info.nr_expozitii = m.nr_expozitii;
	nou->info.pret_bilet = m.pret_bilet;
	nod*p = ld.first;
	int contor = 0;
	while (p && contor<pozitie) {
		p = p->next;
		contor++;
	}
	if (p) {
		nou->next = p;
		nou->prev = p->prev;
		p->prev = nou;
		if (nou->prev) {
			nou->prev->next = nou;
		}
	}
	else {
		ld = inserareSfarsit(ld, m);
	}
	return ld;
}

Muzeu extragereMuzeu(ListaDubla*ld, float pretCautat) {
	nod*p = ld->first;
	Muzeu m;
	while (p && p->info.pret_bilet != pretCautat) {
		p = p->next;
	}
	if (p) {
		//SHALLOW COPY
		m = p->info;
		if (p->prev) {
			p->prev->next = p->next;
		}
		else {
			ld->first = p->next;
		}
		if (p->next) {
			p->next->prev = p->prev;
		}
		else {
			ld->last = p->prev;
		}
		free(p);
	}
	else {
		m.nr_expozitii = 0;
		m.pret_bilet = 0;
	}

	return m;
}

void main() {
	ListaDubla ld;
	ld.first = NULL;
	ld.last = NULL;

	ld = inserareInceput(ld, citesteMuzeu());
	ld = inserareInceput(ld, citesteMuzeu());
	ld = inserareInceput(ld, citesteMuzeu());
	ld = inserareSfarsit(ld, citesteMuzeu());
	ld = inserareSfarsit(ld, citesteMuzeu());

	afisareOrdineListaDubla(ld);
	printf("\n");
	afisareINordineListaDubla(ld);

	while (ld.first) {
		free(ld.first->info.nume);
		ld.first = ld.first->next;
		if (ld.first) {
			free(ld.first->prev);
		}
		else {
			free(ld.last);
		}
	}
	ld.first = ld.last = NULL;


}