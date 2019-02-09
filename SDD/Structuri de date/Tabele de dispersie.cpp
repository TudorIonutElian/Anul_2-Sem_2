#include <stdio.h>
#include<iostream>


//TABELE DE DISPERSIE

//structura informatii
struct vagon{
	int cod;
	char* tip;
};

//structura nod pentru a creea liste
struct nod{
	vagon info;
	nod* next;
};

//structura vector de liste pentru a salva listele
struct HashTable{
	int dim;
	nod** elemente;
};


int hashCode(int cod, HashTable tabela){
	return cod%tabela.dim;
}


HashTable initializare(int lungime){
	HashTable ht;
	ht.dim = lungime;
	ht.elemente = (nod**)malloc(sizeof(nod*)*lungime);

	//initializez elementele cu null
	for (int i = 0; i < lungime; i++){
		ht.elemente[i] = NULL;
	}

	return ht;
}


void inserare(vagon v, HashTable ht){
	if (ht.dim>0){
		int hash = hashCode(v.cod, ht);

		//creez nodul care va fi adaugat in vector
		nod* nou = (nod*)malloc(sizeof(nod));		
		nou->info.cod = v.cod;
		nou->info.tip = (char*)malloc(sizeof(char)*(strlen(v.tip)));
		strcpy(nou->info.tip, v.tip);
		nou->next = NULL;

		//verific daca pozitia este null
		if (ht.elemente[hash] == NULL){
			//adaug nodul nou pe prima pozitie a listei din vector
			ht.elemente[hash] = nou;

		//daca lista nu este goala se parcurge lista si se adauga la sfarsit
		}
		else{

			nod* aux = ht.elemente[hash];
			//caut ultimul element al listei
			while (aux->next){
				aux = aux->next;
			}
			//adaug noul nod pe ultima pozitie
			aux->next = nou;

		}

	//daca tabela de dispersie HashTable nu este initializata arunc o eroare pentru a anunta utilizatorul
	}else{
		throw "HashTable neinitializat";
	}
	
}

//citire din fisier
vagon citireVagonFisier(FILE * f){
	vagon v;
	fscanf(f,"%d", &v.cod);
	char aux[20];
	fscanf(f,"%s", aux);
	v.tip = (char*)malloc(sizeof(char)* (strlen(aux) + 1));
	strcpy(v.tip, aux);

	return v;
}

//scriere in fisier
void scriereVagonfisier(char* fisier, HashTable ht){
	//deschid fisierul
	FILE* f = fopen(fisier, "w");

	//parcurg vectorul de liste
	for (int i = 0; i < ht.dim; i++){
		//daca exita o inregistrare parcurgem lista
		if (ht.elemente[i] != NULL){
			
			nod* cap = ht.elemente[i];
			//iterez pana la sfarsitul listei si scriu vagoanele
			while (cap){
				fprintf(f, "%d - %s\n", cap->info.cod, cap->info.tip);
				cap = cap->next;
			}
		}

	}
}


void main(){
	//creez fisier
	FILE* f;
	//deschid fisierul
	f = fopen("fisier.txt", "r+");

	//initializez un vagon citit din fisier
	vagon v = citireVagonFisier(f);

	//initializez tabela de dispersie
	HashTable ht = initializare(4);
	//inserez vagonul citit din fisier in tabela
	inserare(v, ht);


	inserare(citireVagonFisier(f), ht);

	//inserez in tabela vagoane citite din fisier prin iteratie
	for (int i = 0; i < 3; i++){
		inserare(citireVagonFisier(f), ht);
	}

	// !!!!!!!! inchid fisierul dupa ce lucrul cu acesta s-a incheiat
	fclose(f);

	//scriu in fisier vagoanelea citite anterior
	scriereVagonfisier("scriere.txt", ht);

};