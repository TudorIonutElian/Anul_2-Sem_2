#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ------------------------------ Definire structuri ------------------------------ */

/* Tipul de date sesiune */
typedef struct sesiune {
    int id;
    int id_user;
    char* ip_user;
    int id_browser;
    int nr_pagini;
    int nr_clickuri;
    char* timestamp;
} sesiune;

/* Element lista simpla */
typedef struct nod {
    sesiune info;
    struct nod *urm;
} nod;

/* Element arbore */
typedef struct nodArbore {
    sesiune info;
    struct nodArbore *st;
    struct nodArbore *dr;
} nodArbore;

/* Structura vector de liste */
typedef struct HashTable {
	int dim;
	nod** elemente;
} HashTable;

/* ------------------------------ Prototip functii ------------------------------ */

void apasaEnter();

/* --------------- Functii lista simpla --------------- */

/* Inserare element la inceputul unei liste */
nod* inserareInputElementLista(nod* cap, sesiune info);

/* Inserare element la sfarsitul unei liste */
nod* inserareSfarsitElementLista(nod* cap, sesiune info);

/* Inserare element in ordinea crescatoare a listei */
nod* inserareCrescatoareElementLista(nod* cap, sesiune info);

/* Stergere element din lista */
nod* stergereElementLista(nod* cap, int id);

/* Stergere lista. Dezalocare spatiu */
nod* stergereLista(nod* cap);

/* Citeste date din fisier intr-o lista simpla */
nod* citesteLista();

/* Afisare lista simpla */
void afisareLista(nod* cap);

/* Afisare date in functie de id-ul userului */
void filtrareIdUser(nod* cap);

/* Numara elemente din lista */
int numaraElementeLista(nod *cap);


/* --------------- Functii vector --------------- */

/* Citire elemente vector din lista simpla */
sesiune *citireVector(nod *cap, int nrSesiuni);

/* Afisare elemente vector */
void afisareVector(sesiune *sesiuni, int nrSesiuni);

/* Stergere element vector */
sesiune* stergereElementVector(sesiune* sesiuni, int nrSesiuni, int id);

/* Stergere vector. Dezalocare spatiu */
void stergereVector(sesiune *sesiuni, int nrSesiuni);


/* --------------- Functii arbore --------------- */

/* Creare nod */
nodArbore* creareNod(sesiune info, nodArbore* st, nodArbore* dr);

/* Inserare nod in arbore */
nodArbore* inserare(nodArbore*radacina, sesiune info);

/* Citire elemente arbore din vector */
nodArbore* citireArbore(sesiune *sesiuni, int nrSesiuni);

/* Afisare arbore */
void SRD(nodArbore*rad);

/* Stergere arbore. Dezalocare memorie */
void stergereArbore(nodArbore* radacina);

/* Sterge element din arbore */
nodArbore* stergeNodArbore(nodArbore* radacina, int id);

/* Gaseste element minim in arbore */
nodArbore* gasesteMinim(nodArbore* radacina);

/* --------------- Functii tabela de dispersie --------------- */

/* Generare hashCode - indexul folosit pentru inserare */
int hashCode(int cod, HashTable tabela);

/* Initializarea tabelei de dispersie. Alocarea spatiului */
HashTable initializareHashTable(int lungime);

/* Inserare sesiune in hashTable */
void inserareHashTable(HashTable ht, sesiune info);

/* Citire hashTable din vectorul dinamic creat anterior */
HashTable citireHashTable(sesiune *sesiuni, int nrSesiuni);

/* Afisare hashTable */
void afisareHashTable(HashTable ht);

/* Sterge hashTable */
void stergereHashTable(HashTable ht);

/* Sterge lista din hashTable recursiv */
nod* stergeListaRecursiv(nod* cap);

/* Sterge element din HashTable */
HashTable stergereElementHashTable(HashTable ht, int id);

void apasaEnter()
{
    printf("Apasa enter pentru a continua...\n");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

/* ------------------------------ Functii lista simpla ------------------------------ */

nod* inserareInputElementLista(nod*cap, sesiune info)
{
    nod *aux=(nod*)malloc(sizeof(nod));
    aux->info=info;
    aux->urm=cap;

    return aux;
}

nod* inserare_sfarsit(nod*cap, sesiune info)
{
    nod* nou=(nod*)malloc(sizeof(nod));
    nou->info=info;
    nou->urm=NULL;
    if(cap)
    {
        nod*p=cap;
        while(p->urm)
        {
            p=p->urm;
        }
        p->urm=nou;
    }
    else
    {
        cap=nou;
    }

    return cap;
}

nod* inserareCrescatoareElementLista(nod* cap, sesiune info)
{
    nod* nou = (nod*)malloc(sizeof(nod));
    nou->info = info;
    nou->urm = NULL;
    if (cap)
    {

        if (cap->info.id > info.id)
        {
            cap = inserareInputElementLista(cap, info);
            return cap;
        }
        else
        {
            nod *p=cap;
            while(p->urm && p->urm->info.id < info.id)
                p=p->urm;
            nou->urm=p->urm;
            p->urm=nou;
            return cap;
        }
    }
    else
    {
        return nou;
    }
}

nod* stergereElementLista(nod* cap, int id)
{
    if (cap)
    {
        if (cap->info.id == id)
        {
            nod* p = cap;
            cap = cap->urm;
            free(p->info.ip_user);
            free(p->info.timestamp);
            free(p);
        }
        else
        {
            nod* p = cap;
            while(p->urm && p->urm->info.id != id)
            {
                p = p->urm;
            }
            nod* aux = p->urm;
            p->urm = p->urm->urm;
            free(aux->info.ip_user);
            free(aux->info.timestamp);
            free(aux);
        }
    }

    return cap;
}

nod* stergereLista(nod* cap)
{
    while(cap)
    {
        nod*p=cap;
        cap=cap->urm;
        free(p->info.ip_user);
        free(p->info.timestamp);
        free(p);
    }
    return NULL;
}

nod* citesteLista()
{
    FILE *fisier;
    nod *cap = NULL;
    sesiune info;
    char nume[30], timestamp[20], ip[20];
    printf("Introdu numele fisierului de date: "); scanf("%s", &nume);
    fisier = fopen(nume, "r");


    while (fscanf(fisier, "%d %d %s %d %d %d %s", &info.id, &info.id_user, ip, &info.id_browser, &info.nr_clickuri, &info.nr_pagini, timestamp) >= 1) {
        info.ip_user = (char*)malloc((strlen(ip)+1)*sizeof(char));
        strcpy(info.ip_user, ip);
        info.timestamp=(char*)malloc((strlen(timestamp)+1)*sizeof(char));
        strcpy(info.timestamp, timestamp);
        cap = inserareCrescatoareElementLista(cap, info);
    }

    fclose(fisier);
    return cap;
}

void afisareLista(nod*cap)
{
    nod*p=cap;
    while(p)
    {
        printf("Informatii sesiunea %d: %d %s %d %d %d %s\n", p->info.id, p->info.id_user, p->info.ip_user, p->info.id_browser, p->info.nr_clickuri, p->info.nr_pagini, p->info.timestamp);
        p=p->urm;
    }
}

void filtrareIdUser(nod* cap)
{
    int id;
    nod* p = cap;
    printf("\nIntroduceti id-ul userului cautat: ");
    scanf("%d", &id);
    printf("Sesiunile userului cu id-ul %d:\n", id);
    while(p)
    {
        if (p->info.id_user == id)
        {
            printf("Informatii sesiunea %d: %d %s %d %d %d %s\n", p->info.id, p->info.id_user, p->info.ip_user, p->info.id_browser, p->info.nr_clickuri, p->info.nr_pagini, p->info.timestamp);
        }
        p = p->urm;
    }
}

int numaraElementeLista(nod *cap)
{
    nod*p=cap;
    int count = 0;

    while(p)
    {
        count++;
        p=p->urm;
    }

    return count;
}

/* ------------------------------ Functii vector ------------------------------ */

sesiune *citireVector(nod *cap, int nrSesiuni)
{
    int i=0;
    sesiune *sesiuni = (sesiune*)malloc(nrSesiuni*sizeof(sesiune));
    nod *p = cap;

    while(p)
    {
        sesiuni[i].id = p->info.id;
        sesiuni[i].id_browser = p->info.id_browser;
        sesiuni[i].id_user = p->info.id_user;
        sesiuni[i].ip_user = (char*)malloc(strlen(p->info.ip_user)*sizeof(char));
        strcpy(sesiuni[i].ip_user, p->info.ip_user);
        sesiuni[i].nr_clickuri = p->info.nr_clickuri;
        sesiuni[i].nr_pagini = p->info.nr_pagini;
        sesiuni[i].timestamp = (char*)malloc(strlen(p->info.timestamp)*sizeof(char));
        strcpy(sesiuni[i].timestamp, p->info.timestamp);

        p=p->urm;
        i++;
    }

    return sesiuni;
}

void afisareVector(sesiune* sesiuni, int nrSesiuni)
{
    int i;

    for(i = 0;i < nrSesiuni; i++)
    {
        printf("Informatii sesiunea %d: %d %s %d %d %d %s\n", sesiuni[i].id, sesiuni[i].id_user, sesiuni[i].ip_user, sesiuni[i].id_browser, sesiuni[i].nr_clickuri, sesiuni[i].nr_pagini, sesiuni[i].timestamp);
    }
}

void stergereVector(sesiune *sesiuni, int nrSesiuni)
{
    int i;
    for(i=0;i<nrSesiuni;i++)
    {
        free(sesiuni[i].ip_user);
        free(sesiuni[i].timestamp);
    }
    free(sesiuni);
}

sesiune* stergereElementVector(sesiune* sesiuni, int nrSesiuni, int id)
{
    int i, j = -1;
    sesiune* temp = (sesiune*)malloc((nrSesiuni - 1) * sizeof(sesiune));

    for (i = 0; i < nrSesiuni; i++)
    {
        if (sesiuni[i].id == id)
            continue;
        else
            j++;

        temp[j].id = sesiuni[i].id;
        temp[j].id_browser = sesiuni[i].id_browser;
        temp[j].id_user = sesiuni[i].id_user;
        temp[j].ip_user = (char*)malloc(strlen(sesiuni[i].ip_user)*sizeof(char));
        strcpy(temp[j].ip_user, sesiuni[i].ip_user);
        free(sesiuni[i].ip_user);
        temp[j].nr_clickuri = sesiuni[i].nr_clickuri;
        temp[j].nr_pagini = sesiuni[i].nr_pagini;
        temp[j].timestamp = (char*)malloc(strlen(sesiuni[i].timestamp)*sizeof(char));
        strcpy(temp[j].timestamp, sesiuni[i].timestamp);
        free(sesiuni[j].timestamp);

    }
    free (sesiuni);

    return temp;
}


/* ------------------------------ Functii arbore ------------------------------ */

nodArbore* creareNod(sesiune info, nodArbore* st, nodArbore* dr)
{
    nodArbore* temp=(nodArbore*)malloc(sizeof(nodArbore));
    temp->info.id=info.id;
    temp->info.id_browser=info.id_browser;
    temp->info.id_user = info.id_user;
    temp->info.ip_user = (char*)malloc(strlen(info.ip_user)*sizeof(char));
    strcpy(temp->info.ip_user, info.ip_user);
    temp->info.nr_clickuri = info.nr_clickuri;
    temp->info.nr_pagini = info.nr_pagini;
    temp->info.timestamp = (char*)malloc(strlen(info.timestamp)*sizeof(char));
    strcpy(temp->info.timestamp, info.timestamp);

    temp->dr=dr;
    temp->st=st;

    return temp;
}

nodArbore* inserare(nodArbore*radacina, sesiune info)
{
    if(radacina==NULL)
    {
        radacina=creareNod(info, NULL, NULL);
        return radacina;
    }
    else
    {
        if(info.id < radacina->info.id)
        {
            radacina->st=inserare(radacina->st, info);
        }
        else
        {
            radacina->dr=inserare(radacina->dr, info);
        }
        return radacina;
    }
}

nodArbore* citireArbore(sesiune *sesiuni, int nrSesiuni)
{
    int i;
    nodArbore *radacina = NULL;

    for(i=0;i<nrSesiuni;i++)
    {
        radacina = inserare(radacina, sesiuni[i]);
    }
    return radacina;
}

void SRD(nodArbore *radacina)
{
    if(radacina)
    {
        SRD(radacina->st);
        printf("Informatii sesiunea %d: %d %s %d %d %d %s\n", radacina->info.id, radacina->info.id_user, radacina->info.ip_user, radacina->info.id_browser, radacina->info.nr_clickuri, radacina->info.nr_pagini, radacina->info.timestamp);
        SRD(radacina->dr);
    }
}

nodArbore* stergeNodArbore(nodArbore* radacina, int id)
{
    if (radacina == NULL) return radacina;
    else if (radacina->info.id > id) radacina->st = stergeNodArbore(radacina->st, id);
    else if (radacina->info.id < id) radacina->dr = stergeNodArbore(radacina->dr, id);
    else
    {
        if (radacina->st == NULL && radacina->dr == NULL)
        {
            free(radacina->info.ip_user);
            free(radacina->info.timestamp);
            free(radacina);
            radacina = NULL;
        }
        else if (radacina->st == NULL)
        {
            nodArbore* temp = radacina;
            radacina = radacina->dr;
            free(temp->info.ip_user);
            free(temp->info.timestamp);
            free(temp);
        }
        else if (radacina->dr == NULL)
        {
            nodArbore* temp = radacina;
            radacina = radacina->st;
            free(temp->info.ip_user);
            free(temp->info.timestamp);
            free(temp);
        }
        else
        {
            nodArbore* temp = gasesteMinim(radacina->dr);
            radacina->info = temp->info;
            radacina->dr = stergeNodArbore(radacina->dr, temp->info.id);
        }
    }
    return radacina;
}

nodArbore* gasesteMinim(nodArbore* radacina)
{
    if (radacina == NULL)
    {
        return radacina;
    }
    else if (radacina->st == NULL)
    {
        return radacina;
    }

    return gasesteMinim(radacina->st);
}

void stergereArbore(nodArbore* radacina)
{
    if(radacina)
    {
        stergereArbore(radacina->st);
        stergereArbore(radacina->dr);
        free(radacina->info.ip_user);
        free(radacina->info.timestamp);
        free(radacina);
    }
}


/* ------------------------------ Functii tabela de dispersie ------------------------------ */

int hashCode(int cod, HashTable tabela){
	return cod%tabela.dim;
}

HashTable initializareHashTable(int lungime){
	int i;
	HashTable ht;
	ht.dim = lungime;
	ht.elemente = (nod**)malloc(sizeof(nod*)*lungime);

	for (i = 0; i < lungime; i++){
		ht.elemente[i] = NULL;
	}

	return ht;
}

void inserareHashTable(HashTable ht, sesiune info){
	if (ht.dim>0){
		int hash = hashCode(info.id, ht);

		nod* temp = (nod*)malloc(sizeof(nod));
        temp->info.id=info.id;
        temp->info.id_browser=info.id_browser;
        temp->info.id_user = info.id_user;
        temp->info.ip_user = (char*)malloc(strlen(info.ip_user)*sizeof(char));
        strcpy(temp->info.ip_user, info.ip_user);
        temp->info.nr_clickuri = info.nr_clickuri;
        temp->info.nr_pagini = info.nr_pagini;
        temp->info.timestamp = (char*)malloc(strlen(info.timestamp)*sizeof(char));
        strcpy(temp->info.timestamp, info.timestamp);
        temp->urm = NULL;

        if (ht.elemente[hash] == NULL){
            ht.elemente[hash] = temp;
        }
		else
        {
			nod* p = ht.elemente[hash];
			while (p->urm){
				p=p->urm;
			}
			p->urm = temp;
		}
	}
}

/* Citire hashTable din vector */
HashTable citireHashTable(sesiune *sesiuni, int nrSesiuni)
{
    int i;
    HashTable ht = initializareHashTable(4);

    for(i=0;i<nrSesiuni;i++)
    {
        inserareHashTable(ht, sesiuni[i]);
    }
    return ht;
}

/* Afisare HashTable */
void afisareHashTable(HashTable ht)
{
    int i;

	for (i = 0; i < ht.dim; i++){
		if (ht.elemente[i] != NULL){
			nod* p = ht.elemente[i];
			while (p){
				printf("Informatii sesiunea %d: %d %s %d %d %d %s\n", p->info.id, p->info.id_user, p->info.ip_user, p->info.id_browser, p->info.nr_clickuri, p->info.nr_pagini, p->info.timestamp);
                p=p->urm;
			}
		}

	}
}

void stergereHashTable(HashTable ht)
{
    int i;

    if (ht.elemente != NULL)
    {
        for (i = 0; i < ht.dim; i++){
            ht.elemente[i] = stergeListaRecursiv(ht.elemente[i]);
		}
		free(ht.elemente);

	}
}

nod* stergeListaRecursiv(nod* cap)
{
    if(cap)
    {
        cap->urm = stergeListaRecursiv(cap->urm);
        free(cap);
        return NULL;
    }
    else
        return NULL;
}

HashTable stergereElementHashTable(HashTable ht, int id)
{
    int i, hash = hashCode(id, ht);

    ht.elemente[hash] = stergereElementLista(ht.elemente[hash], id);

    return ht;
}


int main() {

    apasaEnter();

    /* ------------------------------ Liste simple ------------------------------ */

    printf("\n/* ------------------------------ Liste simple ------------------------------ */\n");

    /* Se creaza lista. Se populeaza cu elementele din fisier */
    nod* cap;
    int nrElemente;
    cap = citesteLista();
    nrElemente = numaraElementeLista(cap);
    afisareLista(cap);
    filtrareIdUser(cap);
    apasaEnter();


    /* ------------------------------ Vectori alocati dinamic ------------------------------ */

    printf("\n/* ------------------------------ Vectori alocati dinamic ------------------------------ */\n");

    /* Se creaza vectorul. Se populeaza cu elementele din lista */
    sesiune *sesiuniDinamic;
    sesiuniDinamic = citireVector(cap, nrElemente);
    afisareVector(sesiuniDinamic, nrElemente);
    apasaEnter();


    /* ------------------------------ Arbori ------------------------------ */

    printf("\n/* ------------------------------ Arbori ------------------------------ */\n");

    /* Se creaza arborele. Se populeaza cu elementele din vector */
    nodArbore *radacina;
    radacina = citireArbore(sesiuniDinamic, nrElemente);
    SRD(radacina);
    apasaEnter();


    /* ------------------------------ HashTable ------------------------------ */

    printf("\n/* ------------------------------ HashTable ------------------------------ */\n");

    /* Se creaza hashTable. Se populeaza cu elementele din vector */
    HashTable ht;
    ht = citireHashTable(sesiuniDinamic, nrElemente);
    afisareHashTable(ht);
    apasaEnter();


    /* ------------------------------ Stergere element din structuri date ------------------------------ */

    printf("\n/* ------------------------------ Stergere element din structuri date ------------------------------ */\n");
    int id = 9;

    /* Stergere element din lista */
    cap = stergereElementLista(cap, id);
    printf("Elementul cu id-ul %d a fost sters!\n", id);
    printf("\n/* ------------------------------ Lista dupa stergere element ------------------------------ */\n");
    afisareLista(cap);
    apasaEnter();

    /* Stergere element din vector */
    sesiuniDinamic = stergereElementVector(sesiuniDinamic, nrElemente, id);
    printf("Elementul cu id-ul %d a fost sters!\n", id);
    printf("\n/* ------------------------------ Vector dupa stergere element ------------------------------ */\n");
    afisareVector(sesiuniDinamic, nrElemente - 1);
    apasaEnter();

    /* Stergere element din hashTable */
    radacina = stergeNodArbore(radacina, id);
    printf("Elementul cu id-ul %d a fost sters!\n", id);
    printf("\n/* ------------------------------ Arbore dupa stergere element ------------------------------ */\n");
    SRD(radacina);
    apasaEnter();

    /* Stergere element din hashTable */
    ht = stergereElementHashTable(ht, id);
    printf("Elementul cu id-ul %d a fost sters!\n", id);
    printf("\n/* ------------------------------ HashTable dupa stergere element ------------------------------ */\n");
    afisareHashTable(ht);
    apasaEnter();


    /* ------------------------------ Stergere structuri date ------------------------------ */

    /* Stergere lista. Dezalocare spatiu */
    cap = stergereLista(cap);

    /* Stergere vector. Dezalocare spatiu */
    stergereVector(sesiuniDinamic, nrElemente);

    /* Stergere arbore. Dezalocare memorie */
    stergereArbore(radacina);

    /* Stergere hashTable. Dezalocare memorie */
    stergereHashTable(ht);

    printf("Toate structurile de date au fost sterse!\n");

    printf("\nSfarsit!\n");

    return 0;
}
