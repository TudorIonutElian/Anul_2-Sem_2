//#include<iostream>
//
///*
//Am ales coada , care este de obicei implemetata cu doubly linked list (lista dublu inlantuita)
//*/
//
////structura Parc
//struct Parc {
//	int id; //numar inregistrare parc
//	char* numeParc;
//	int nrVizitatori;
//	float suprafataParc;
//};
//
//Parc creareParc(int id, char* nume, int nrVizitatori, float suprafataParc) {
//	Parc p;
//	p.numeParc = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy_s(p.numeParc, strlen(nume) + 1, nume);
//	p.nrVizitatori = nrVizitatori;
//	p.suprafataParc = suprafataParc;
//
//	return p;
//}
//
//struct nodDublu {
//	nodDublu *next, *prev;
//	Parc info;
//};
//
////incapsularea adreselor primului si ultimului nod al listei duble
////LDI => Lista Dublu Inlantuita
//struct LDI {
//	nodDublu* primul;
//	nodDublu* ultimul;
//};
//
//nodDublu* creareNod(Parc p, nodDublu* next, nodDublu* prev) {
//	nodDublu* nou = (nodDublu*)malloc(sizeof(nodDublu));
//	nou->next = next;
//	nou->prev = prev;
//	nou->info = creareParc(p.id, p.numeParc, p.nrVizitatori, p.suprafataParc);
//	return nou;
//}
//
//Parc citesteParc() {
//	Parc parc;
//	printf("ID: \t\t\t");
//	scanf("%d", &parc.id);
//	char buffer[20];
//	printf("Nume Parc: \t\t");
//	scanf("%s", buffer);
//	parc.numeParc = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(parc.numeParc, buffer);
//	printf("Numar vizitatori: \t");
//	scanf("%d", &parc.nrVizitatori);
//	printf("Suprafata parcului: \t");
//	scanf("%f", &parc.suprafataParc);
//
//	return parc;
//}
//
//void afisareParc(Parc p) {
//	printf("ID %d... Parcul %s are %d de vizitatori, iar suprafata lui este de %5.2f hectare.\n",
//		p.id, p.numeParc, p.nrVizitatori, p.suprafataParc);
//}
//
//
//
//LDI inserareInceput(LDI ld, Parc pc) {
//	/*alocarea de memorie heap pentru un nod al listei duble*/
//	nodDublu* nou = (nodDublu*)malloc(sizeof(nodDublu));
//	nou->info.id = pc.id;
//	nou->info.numeParc = (char*)malloc(sizeof(char)*(strlen(pc.numeParc) + 1));
//	strcpy(nou->info.numeParc, pc.numeParc);
//	nou->info.nrVizitatori = pc.nrVizitatori;
//	nou->info.suprafataParc = pc.suprafataParc;
//	nou->prev = NULL;
//	if (ld.primul) {
//		nou->next = ld.primul;
//		ld.primul->prev = nou;
//		ld.primul = nou;
//	}
//	else {
//		ld.primul = ld.ultimul = nou;
//		nou->next = NULL;
//	}
//	return ld;
//}
//
//void afisareOrdineListaDubla(LDI ld) {
//	nodDublu*b = ld.primul;
//	while (b)
//	{
//		afisareParc(b->info);
//		b = b->next;
//	}
//}
//
//void afisareOrdineInversa(LDI lista) {
//	nodDublu* b = lista.ultimul;
//	while (b) {
//		afisareParc(b->info);
//		b = b->prev;
//	}
//
//	//for (nodDublu* p = lista.ultimul; p != NULL; p = p->prev) {
//	//	afisareParc(p->info);
//	//}
//}
//
////Filtrarea se face in functie de id (numar de inregistrare parc);
//Parc Filtrare(LDI*ld, int filtruID) {
//	nodDublu*b = ld->primul;
//	Parc parc;
//	while (b && b->info.id != filtruID) {
//		b = b->next;
//	}
//	if (b) {
//		parc = b->info;
//		if (b->prev) {
//			b->prev->next = b->next;
//		}
//		else {
//			ld->primul = b->next;
//		}
//		if (b->next) {
//			b->next->prev = b->prev;
//		}
//		else {
//			ld->ultimul = b->prev;
//		}
//		free(b);
//	}
//	else {
//		parc.id = 0;
//		parc.nrVizitatori = 0;
//		parc.suprafataParc = 0;
//	}
//
//	return parc;
//}
//
//void main() {
//	LDI ld;
//	ld.primul = NULL;
//	ld.ultimul = NULL;
//
//	ld = inserareInceput(ld, citesteParc());
//	printf("\n");
//	ld = inserareInceput(ld, citesteParc());
//	printf("\n");
//	ld = inserareInceput(ld, citesteParc());
//	printf("\n");
//
//	afisareOrdineInversa(ld);
//	printf("\n");
//	
//
//	//Filtrarea se face in functie de id (numar de inregistrare parc);
//
//	int valFiltru = 0;
//	printf("Introduceti ID-ul parcului care trebuie filtrat:\t");
//	printf("\n");
//
//	scanf("%d", &valFiltru);
//	if (valFiltru >0) {
//		printf("Afisare dupa filtrare\n");
//		printf("\nFiltrare parc cu ID-ul: %d\n", valFiltru);
//		Parc p = Filtrare(&ld, valFiltru);
//		afisareOrdineInversa(ld);
//	}
//	else {
//		printf("Introduceti o valoare pentru a executa filtrarea.\n");
//	}
//
//
//	//dezalocare memorie
//	while (ld.primul) {
//		free(ld.primul->info.numeParc);
//		ld.primul = ld.primul->next;
//		if (ld.primul) {
//			free(ld.primul->prev);
//		}
//		else {
//			free(ld.ultimul);
//		}
//	}
//	ld.primul = ld.ultimul = NULL;
//}