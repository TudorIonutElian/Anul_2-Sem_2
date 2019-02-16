/*LISTA SIMPLU INLANTUITA
	INSERARE LA SFARSIT
*/

include <iostream>

struct Muzeu{
    char* nume;
    float pret_bilet;
    int nr_vizitatori;
};
    
Muzeu citireMuzeu(){
    Muzeu muzeu;
    char buffer[20];
    printf("Nume muzeu: "); scanf_s("%s", buffer, 20);
    muzeu.nume = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy_s(muzeu.nume, strlen(buffer)+1,buffer);
    printf("Pret bilet intrare:"); scanf_s("%f",&muzeu.pret_bilet);
    printf("Numar vizitatori:"); scanf_s("%d",muzeu.nr_vizitatori);
}

void afisareMuzeu(Muzeu muzeu){
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

nod* creareNod (Muzeu m, nod* urmator){//prin aceasta metoda INSEREZ LA INCEPUT
    /*1*/nod* nodNou;
    /*2*/nodNou = (nod*)malloc(sizeof(nod));
    /*3. atribut 1*/ nodNou -> info = m;//shallow copy - nume e cu pointer
		/*rezolv problema shallow copy*/
    nodNou -> nume =(char*)malloc(sizeof(char)*(strlen(m.nume)+1));//i-am alocat spatiu
    strcpy_s(nodNou->info.nume, strlen(m.nume)+1), m.nume);
		/*end rezolv problema shallow copy*/
    /*3. atribut 2*/
	nodNou -> next = urmator;
    /*4*/return nodNou;
}
		/***************/
		/*AFISARE LISTA*/
		/***************/

/*1. Parcurg toata lista*/
/*2. Afisez toate informatiile din fiecare nod*/

void afisareLista(nod* cap){
	while (cap){
		afisareMuzeu(cap->info);
		cap=cap->next;
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

nod* stergereLista(nod* cap){//puteam sa il numesc si altfel, nu numai cap
	while(cap){/*cat timp avem adresa la acel pointer*/
		free(cap->info.nume);
		nod* temp = cap;
		cap = cap->next;
		free(temp);
	}
	return NULL;
}

void main(){
    /*declar o lista in main*/
    nod* lista = NULL;
    /*INSERARE LA INCEPUT*/
    lista=creareNod(citireMuzeu(), lista);
    lista=creareNod(citireMuzeu(), lista);
    lista=creareNod(citireMuzeu(), lista);
	
	/*apelez in main afisareLista()*/
	afisareLista(lista);
	
	/*apelez in main stergereLista()*/
	lista  +r= stergereLista(lista);

}

