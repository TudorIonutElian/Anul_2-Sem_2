//#include<iostream>
//#include <math.h>
//
///*
//parcuri si dimensiunea lor
//1. Cismigiu 16.7 ha
//2. Gradina Botanica 17.5 ha
//3. Kiseleff 31.25 ha
//4. Carol I 40.75 ha
//5. Herastrau 110.3 ha
//*/
//
//struct Parc {
//	char* numeParc;
//	int nr_vizitatori;
//	float suprafataParc;
//};
//
//Parc citesteParc() {
//	Parc parc;
//	char buffer[20];
//	printf("Nume Parc: \t");
//	scanf("%s", buffer);
//	parc.numeParc = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(parc.numeParc, buffer);
//	printf("Numar de vizitatori: \t");
//	scanf("%d", &parc.nr_vizitatori);
//	printf("Suprafata parcului: \t");
//	scanf("%f", &parc.suprafataParc);
//
//	return parc;
//}
//
//void afisareParc(Parc p) {
//	printf("Parcul %s are %d de vizitatori, iar suprafata lui este de %5.2f\n",
//		p.numeParc, p.nr_vizitatori, p.suprafataParc);
//}
//
///*definirea structurii unui nod dintr-o lista dubla
//nod *next, *prev;
//
//spre deosebire de lista simpla care are doar
//nod *next;
//*/
//
//struct nod {
//	nod *next, *prev;
//	//nod*prev;
//	Parc info;
//};
//
////incapsularea adreselor primului si ultimului nod al listei duble
//struct ListaDubla {
//	nod*first;
//	nod*last;
//};
//
//ListaDubla inserareInceput(ListaDubla ld, Parc pc) {
//	/*alocarea de memorie heap pentru un nod al listei duble*/
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info.numeParc = (char*)malloc(sizeof(char)*(strlen(pc.numeParc) + 1));
//	strcpy(nou->info.numeParc, pc.numeParc);
//	nou->info.nr_vizitatori = pc.nr_vizitatori;
//	nou->info.suprafataParc = pc.suprafataParc;
//	nou->prev = NULL;
//	if (ld.first) {
//		nou->next = ld.first;
//		ld.first->prev = nou;
//		ld.first = nou;
//	}
//	else {
//		ld.first = ld.last = nou;
//		nou->next = NULL;
//	}
//	return ld;
//}
//
//ListaDubla inserareSfarsit(ListaDubla ld, Parc par) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info.numeParc = (char*)malloc(sizeof(char)*(strlen(par.numeParc) + 1));
//	strcpy(nou->info.numeParc, par.numeParc);
//	nou->info.nr_vizitatori = par.nr_vizitatori;
//	nou->info.suprafataParc = par.suprafataParc;
//	nou->next = NULL;
//	if (ld.last) {
//		nou->prev = ld.last;
//		ld.last->next = nou;
//		ld.last = nou;
//	}
//	else {
//		ld.last = ld.first = nou;
//		nou->prev = NULL;
//	}
//	return ld;
//}
//
//void afisareOrdineListaDubla(ListaDubla ld) {
//	nod*b = ld.first;
//	while (b)
//	{
//		afisareParc(b->info);
//		b = b->next;
//	}
//}
//
//void afisareINordineListaDubla(ListaDubla ld) {
//	nod* b = ld.last;
//	while (b) {
//		afisareParc(b->info);
//		b = b->prev;
//	}
//}
//
//
////ListaDubla inserareSortata(ListaDubla ld, Parc pr) {
////	nod* nou = (nod*)malloc(sizeof(nod));
////	nou->info.numeParc = (char*)malloc(sizeof(char)*(strlen(pr.numeParc) + 1));
////	strcpy(nou->info.numeParc, pr.numeParc);
////	nou->info.nr_vizitatori = pr.nr_vizitatori;
////	nou->info.suprafataParc = pr.suprafataParc;
////	nod*b = ld.first;
////	while (b && pr.suprafataParc > b->info.suprafataParc) {
////		b = b->next;
////	}
////	if (b) {
////		nou->next = b;
////		nou->prev = b->prev;
////		b->prev = nou;
////		if (nou->prev) {
////			nou->prev->next = nou;
////		}
////	}
////	else {
////		ld = inserareSfarsit(ld, pr);
////	}
////	return ld;
////}
//
////ListaDubla inserarePePozitie(ListaDubla ld, Parc m, int pozitie) {
////	nod* nou = (nod*)malloc(sizeof(nod));
////	nou->info.numeParc = (char*)malloc(sizeof(char)*(strlen(m.numeParc) + 1));
////	strcpy(nou->info.numeParc, m.numeParc);
////	nou->info.nr_vizitatori = m.nr_vizitatori;
////	nou->info.suprafataParc = m.suprafataParc;
////	nod*b = ld.first;
////	int contor = 0;
////	while (b && contor<pozitie) {
////		b = b->next;
////		contor++;
////	}
////	if (b) {
////		nou->next = b;
////		nou->prev = b->prev;
////		b->prev = nou;
////		if (nou->prev) {
////			nou->prev->next = nou;
////		}
////	}
////	else {
////		ld = inserareSfarsit(ld, m);
////	}
////	return ld;
////}
//
//
////filtrare dupa Suprafata unui parc
//Parc Filtrare(ListaDubla*ld, float cautaSuprafataParc) {
//	nod*b = ld->first;
//	Parc parc;
//	while (b && b->info.suprafataParc != cautaSuprafataParc) {
//		b = b->next;
//	}
//	if (b) {
//		//SHALLOW COPY
//		parc = b->info;
//		if (b->prev) {
//			b->prev->next = b->next;
//		}
//		else {
//			ld->first = b->next;
//		}
//		if (b->next) {
//			b->next->prev = b->prev;
//		}
//		else {
//			ld->last = b->prev;
//		}
//		free(b);
//	}
//	else {
//		parc.nr_vizitatori = 0;
//		parc.suprafataParc = 0;
//	}
//
//	return parc;
//}
//
//void main() {
//	ListaDubla ld;
//	ld.first = NULL;
//	ld.last = NULL;
//
//	//inserare ca in stiva
//	ld = inserareInceput(ld, citesteParc());
//	printf("\n");
//	ld = inserareInceput(ld, citesteParc());
//	printf("\n");
//	ld = inserareInceput(ld, citesteParc());
//	printf("\n");
//
//	afisareOrdineListaDubla(ld);
//	printf("\n");
//	afisareINordineListaDubla(ld);
//	printf("\n");
//	Filtrare(&ld, 16.7);
//
//
//	//dezalocare memorie
//	while (ld.first) {
//		free(ld.first->info.numeParc);
//		ld.first = ld.first->next;
//		if (ld.first) {
//			free(ld.first->prev); //dezalocare memorie heap
//		}
//		else {
//			//dezalocare memorie heap 
//			free(ld.last);
//		}
//	}
//	ld.first = ld.last = NULL;
//
//
//}