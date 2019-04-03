//#include<iostream>
//
//struct Muzeu {
//	char* nume;
//	int nr_expozitii;
//	float pret_bilet;
//};
//
//struct nod {
//	Muzeu info;
//	nod* next;
//};
//
//nod* inserareInceput(nod* cap, Muzeu muzeu) {
//	nod* nou;
//	nou = (nod*)malloc(sizeof(nod));
//	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(muzeu.nume) + 1));
//	strcpy(nou->info.nume, muzeu.nume);
//	nou->info.nr_expozitii = muzeu.nr_expozitii;
//	nou->info.pret_bilet = muzeu.pret_bilet;
//	nou->next = cap;
//	return nou;
//}
//
//Muzeu citesteMuzeu() {
//	Muzeu muzeu;
//	char buffer[20];
//	printf("Nume:");
//	scanf("%s", buffer);
//	muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(muzeu.nume, buffer);
//	printf("Numar expozitii:");
//	scanf("%d", &muzeu.nr_expozitii);
//	printf("Pret bilet:");
//	scanf("%f", &muzeu.pret_bilet);
//
//	return muzeu;
//}
//
//void afisareMuzeu(Muzeu m) {
//	printf("Muzeul %s are %d expozitii, iar biletul costa %5.2f\n",
//		m.nume, m.nr_expozitii, m.pret_bilet);
//}
//
//void afisareLista(nod* cap) {
//	while (cap) {
//		afisareMuzeu(cap->info);
//		cap = cap->next;
//	}
//}
//
//nod* inserareSfarsit(nod* cap, Muzeu muzeu) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(muzeu.nume) + 1));
//	strcpy(nou->info.nume, muzeu.nume);
//	nou->info.nr_expozitii = muzeu.nr_expozitii;
//	nou->info.pret_bilet = muzeu.pret_bilet;
//	nou->next = NULL;
//	
//	if (cap) {
//		nod*aux = cap;
//		while (cap->next != NULL) {
//			cap = cap->next;
//		}
//		cap->next = nou;
//		return aux;
//	}
//	else {
//		cap = nou;
//		return cap;
//	}
//}
//
//nod*inserareSf2(nod* cap, Muzeu m) {
//	nod*aux = cap;
//	while (aux->next) {
//		aux = aux->next;
//	}
//	aux->next = inserareInceput(NULL, m);
//	return cap;
//}
//
//void main() {
//	nod* lista = NULL;
//	lista = inserareInceput(lista, citesteMuzeu());
//	lista = inserareInceput(lista, citesteMuzeu());
//	lista = inserareSfarsit(lista, citesteMuzeu());
//
//	afisareLista(lista);
//
//	while (lista) {
//		free(lista->info.nume);
//		nod*aux = lista;
//		lista = lista->next;
//		free(aux);
//	}
//}