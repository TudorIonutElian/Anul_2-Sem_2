#include<iostream>

struct ContBancar {
	char*titular;
	int nrTranzactii;
	float sold;
};

struct nodLSI {
	ContBancar info;
	nodLSI*next;
};
ContBancar copiazaCont(ContBancar cb);

nodLSI* inserareInceputLSI(nodLSI*cap, ContBancar cb) {
	nodLSI*nou = (nodLSI*)malloc(sizeof(nodLSI));
	nou->info = copiazaCont(cb);
	nou->next = cap;
	return nou;
}

ContBancar citesteCont() {
	ContBancar cb;
	char buffer[20];
	printf("Titular:");
	scanf("%s", buffer);
	cb.titular = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(cb.titular, buffer);

	printf("Numar tranzactii:");
	scanf("%d", &cb.nrTranzactii);
	printf("Sold:");
	scanf("%f", &cb.sold);

	return cb;
}

void afisareContBancar(ContBancar cb) {
	printf("%s are in cont %5.2f lei, in urma a %d tranzactii\n",
		cb.titular, cb.sold, cb.nrTranzactii);
}

ContBancar copiazaCont(ContBancar cb) {
	ContBancar c;
	c.titular = (char*)malloc(sizeof(char)*(strlen(cb.titular) + 1));
	strcpy(c.titular, cb.titular);
	c.nrTranzactii = cb.nrTranzactii;
	c.sold = cb.sold;
	return c;
}

struct nod {
	ContBancar info;
	nod* next;
	nod* prev;
};

struct ListaDubla {
	nod*first;
	nod*last;
};

ListaDubla inserareInceput(ListaDubla ld, ContBancar cb) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info = copiazaCont(cb);
	nou->prev =nou->next= NULL;
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
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info = copiazaCont(cb);
	nou->prev = nou->next = NULL;
	if (ld.first) {
		ld.last->next = nou;
		nou->prev = ld.last;
		ld.last = nou;
	}
	else {
		ld.last = ld.first = nou;
	}
	return ld;
}

void afisareLista(ListaDubla ld) {
	nod*p = ld.first;
	while (p) {
		afisareContBancar(p->info);
		p = p->next;
	}
}
void afisareInversaLista(ListaDubla ld) {
	nod*p = ld.last;
	while (p) {
		afisareContBancar(p->info);
		p = p->prev;
	}
}

ListaDubla inserarePePozitie(ListaDubla ld, int pozitie, ContBancar cb) {
	if (ld.first) {
		int contor = 1;
		nod*p = ld.first;
		while (p->next && contor < pozitie-1) {
			p = p->next;
			contor++;
		}
		nod* nou = (nod*)malloc(sizeof(nod));
		nou->info = copiazaCont(cb);

		nou->next = p->next;
		nou->prev = p;
		p->next = nou;
		if (nou->next) {
			nou->next->prev = nou;
		}
		else {
			ld.last = nou;
		}
	}
	else {
		ld = inserareInceput(ld, cb);
	}
	return ld;
}

ContBancar extrageCont(ListaDubla ld, float soldCautat) {
	ContBancar cb;
	if (ld.first) {
		nod*p = ld.first;
		while (p && p->info.sold != soldCautat ) {
			p = p->next;
		}
		if (p) {
			cb = copiazaCont(p->info);
			free(p->info.titular);

			if (p->prev) {
				p->prev->next = p->next;
			}
			else
			{
				ld.first = p->next;
			}
			if (p->next) {
				p->next->prev = p->prev;
			}
			else {
				ld.last = p->prev;
			}
			free(p);
		}
		else {
			cb.sold = 0;
			cb.nrTranzactii = 0;
		}
	}

	return cb;
}


nodLSI*extragereConturi(ListaDubla ld, float soldLimita) {
	nodLSI*cap = NULL;
	nod*p = ld.first;
	while (p) {
		if (p->info.sold < soldLimita) {
			cap = inserareInceputLSI(cap, extrageCont(ld, p->info.sold));
		}
	}

	return cap;
}


void main() {
	ListaDubla ld;
	ld.first = ld.last = NULL;
	ld = inserareInceput(ld, citesteCont());
	ld = inserareInceput(ld, citesteCont());
	ld = inserareInceput(ld, citesteCont());

	ld = inserarePePozitie(ld, 4, citesteCont());
	ld = inserarePePozitie(ld, 4, citesteCont());
	afisareInversaLista(ld);
	//ContBancar cb = extrageCont(ld, 10);
	//printf("\n\n");
	//afisareContBancar(cb);
	//printf("\n\n");
	//afisareLista(ld);
	printf("\n\n");
	nodLSI*cap = extragereConturi(ld, 5);
	while (cap) {
		afisareContBancar(cap->info);
		cap = cap->next;
	}
	printf("\n\n");
	afisareInversaLista(ld);

	while (ld.first) {
		nod* temp = ld.first;
		free(temp->info.titular);
		ld.first = temp->next;
		free(temp);
	}
	ld.last = NULL;
}