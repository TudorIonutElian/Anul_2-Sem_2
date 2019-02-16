#include <iostream>

struct ContBancar {
	char *titular;
	int nrTranzactii;
	float sold;

};

struct nodLSI {
	ContBancar info;
	nodLSI *next;
};

struct nod {
	ContBancar info;
	nod *next;
	nod *prev;
};

struct ListaDubla {
	nod *first;
	nod *last;
};

ContBancar copiazaCont(ContBancar cb);
ContBancar extrageCont(ListaDubla *ld, float sold_cautat);

nodLSI* inserareInceputLSI(nodLSI* cap, ContBancar cb) {
	nodLSI* nou = (nodLSI*)malloc(sizeof(nodLSI));
	nou->info = copiazaCont(cb);
	nou->next = cap;

	return nou;
}

nodLSI* extragereConturi(ListaDubla ld, float soldLimita) {
	nodLSI* cap = NULL;
	nod* p = ld.first;
	while (p) {
		if (p->info.sold < soldLimita) {
			cap = inserareInceputLSI(cap, extrageCont(&ld, p->info.sold));
		}
		// daca p devine dangling pointer (point-eaza catre o adresa de memorie care nu mai e folosita in acest moment -> am extras primul element din lista)
		// verificarea nu e buna - aparent nu exista o metoda standard pentru a verifica daca un pointer este dangling pointer
		if (!p->info.titular)
			p = ld.first;
		else
			p = p->next;

	}


	return cap;
}

nodLSI* extragereConturi2(ListaDubla *ld, float soldLimita) {
	nodLSI* cap = NULL;
	nod* p = ld->first;
	bool flag;
	float soldAnterior = 0;

	while (p) {
		flag = 1;
		if (p->info.sold < soldLimita) {
			ContBancar temp = copiazaCont(p->info);
			cap = inserareInceputLSI(cap, temp);

			//setare variabile ajutatoare
			soldAnterior = temp.sold;
			flag = 0;
			free(temp.titular);
		}
		p = p->next;
		if (!flag)
			extrageCont(ld, soldAnterior);
	}

	return cap;
}


ContBancar citesteCont() {
	ContBancar cb;
	char buffer[20];
	printf("Introduceti nume titular: ");
	scanf("%s", buffer);
	cb.titular = (char*)malloc(sizeof(char)* strlen(buffer) + 1);
	strcpy(cb.titular, buffer);

	printf("Introduceti numar tranzactii: ");
	scanf("%d", &cb.nrTranzactii);

	printf("Introduceti sold: ");
	scanf("%f", &cb.sold);
	return cb;
}

void afisareContBancar(ContBancar cb) {
	printf("%s are in cont %5.2f lei in urma a %d tranzactii.\n", cb.titular, cb.sold, cb.nrTranzactii);
}



ContBancar copiazaCont(ContBancar cb) {
	ContBancar c;
	c.titular = (char*)malloc(sizeof(char)* strlen(cb.titular) + 1);
	strcpy(c.titular, cb.titular);
	c.nrTranzactii = cb.nrTranzactii;
	c.sold = cb.sold;

	return c;
}


ListaDubla inserareInceput(ListaDubla ld, ContBancar cb) {
	nod *nou = (nod*)malloc(sizeof(nod));
	nou->info = copiazaCont(cb);
	nou->prev = nou->next = NULL;
	if (ld.first) {
		ld.first->prev = nou;
		nou->next = ld.first;
		ld.first = nou;
	}
	else {
		ld.first = ld.last = nou;
	}

	return ld;
}

ListaDubla inserareSfarsit(ListaDubla ld, ContBancar cb) {
	nod *nou = (nod*)malloc(sizeof(nod));
	nou->info = copiazaCont(cb);
	nou->prev = nou->next = NULL;
	if (ld.first) {
		ld.last->next = nou;
		nou->prev = ld.last;
		ld.last = nou;
	}
	else
		ld.first = ld.last = nou;

	return ld;
}

void afisareLista(ListaDubla ld) {
	nod* p = ld.first;
	while (p) {
		afisareContBancar(p->info);
		p = p->next;
	}
}

void afisareInversaLista(ListaDubla ld) {
	nod* p = ld.last;
	while (p) {
		afisareContBancar(p->info);
		p = p->prev;
	}
}

ListaDubla inserarePePozitie(ListaDubla ld, int pozitie, ContBancar cb) {
	if (ld.first) {
		int contor = 1;
		nod *p = ld.first;
		while (p->next && contor < pozitie - 1) {
			p = p->next;
			contor++;
		}
		nod *nou = (nod*)malloc(sizeof(nod));
		nou->info = copiazaCont(cb);
		nou->next = p->next;
		nou->prev = p;
		p->next = nou;
		if (nou->next)
			nou->next->prev = nou;
		else
			ld.last = nou;
	}
	else
		ld = inserareInceput(ld, cb);

	return ld;
}

ContBancar extrageCont(ListaDubla *ld, float sold_cautat) {
	ContBancar cb;
	if (ld->first) {
		nod* p = ld->first;
		while (p && p->info.sold != sold_cautat) {
			p = p->next;
		}
		if (p) {
			cb = copiazaCont(p->info);
			free(p->info.titular);

			if (p->prev)
				p->prev->next = p->next;
			else
				ld->first = p->next;
			if (p->next)
				p->next->prev = p->prev;
			else
				ld->last = p->prev;
			free(p);
		}
		else {
			cb.sold = 0;
			cb.nrTranzactii = 0;
			cb.titular = (char*)malloc(strlen("Anonim") + 1);
			strcpy(cb.titular, "Anonim");
		}
	}

	return cb;
}

void main() {
	ListaDubla ld;
	ld.first = ld.last = NULL;

	printf("\nInserare la inceput.\n");
	ld = inserareInceput(ld, citesteCont());
	ld = inserareInceput(ld, citesteCont());
	//ld = inserareInceput(ld, citesteCont());
	printf("\nInserare la sfarsit.\n");
	ld = inserareSfarsit(ld, citesteCont());

	printf("\nInserare pe pozitie.\n");
	ld = inserarePePozitie(ld, 3, citesteCont());
	//ld = inserarePePozitie(ld, 4, citesteCont());
	//ld = inserarePePozitie(ld, 4, citesteCont());

	printf("\nAfisare lista.\n");
	afisareLista(ld);


	printf("\nExtrage cont. \n");
	ContBancar cb = extrageCont(&ld, 10);
	printf("\n\n");

	printf("\nAfisare cont. ");
	afisareContBancar(cb);
	printf("\n\n");
	afisareLista(ld);


	printf("\nNod simplu inlantuit.\nextragereConturi2\n");
	nodLSI* cap = extragereConturi2(&ld, 5);
	while (cap) {
		afisareContBancar(cap->info);
		cap = cap->next;
	}

	printf("\nAfisareInversaLista\n ");
	afisareInversaLista(ld);


	printf("Dezalocare spatiu\n");
	while (ld.first) {
		nod *temp = ld.first;
		free(temp->info.titular);
		ld.first = temp->next;
		free(temp);
	}
	ld.last = NULL;


	return;
}