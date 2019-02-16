/*LISTA SIMPLU INLANTUITA
****CREARE NOD****
INSERARE LA INCEPUT*/

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

/*Creez o structura nod; O lista va fi o insiruire de astfel de noduri*/
struct nod {
    Muzeu info; /*informatia utila*/
    nod* next; /*Adresa urmatorului nod*/
};

/*Creez o functie care sa imi creeze un nod si sa returneaza adresa acelui nod nou creat(pentru ca il creeaza)*/

//in paranteza primim informatia utila si adresa urmatorului nod.
nod* creareNod (Muzeu m, nod* urmator){//prin aceasta metoda INSEREZ LA INCEPUT
    nod* nodNou;/*Creez un nod nou*/
    /*Ii aloc spatiu*/
    nodNou = /*cast la nod pointer*/ (nod*)malloc(sizeof(nod)/*vrem sa alocam 1 deci nu il inmultim cu nimic*/);
    /*setam cele 2 atribute*/
    nodNou -> info = m; /*shallow copy (se copiaza adresa si nu valoarea*/
    /*2 metode pentru a rezolva shallow copy*/
    /*1. facem o metoda de deep copy, care sa copieze toata informatia*/
    /*2.Sau ii aloc spatiu, ca sa tratam punctele unde face shallow copy.
    Adica la *nume se copiaza adresa in loc de valoare*/
    nodNou -> nume =/*cast la*/ (char*)malloc(sizeof(char)*(strlen(m.nume)+1));//i-am alocat spatiu
    /*copiem din m.nume in nodNou*/
    strcpy_s(nodNou->info.nume, strlen(m.nume)+1), m.nume);
    
    
    nodNou -> next = /*parametrul numit "urmator"*/ urmator;
    /*retunam adresa unde am creat nodul nostru*/
    return nodNou;
}


void main(){
    /*declar o lista in main*/
    /*declar o adresa la nod si o initializez cu NULL pentru ca este goala*/
    nod* lista = NULL;
    /*apelam in main functia creareNod care returneaza adresa noului nod creat*/
    
    /*INSERARE LA INCEPUT*/
    lista=creareNod(citireMuzeu(),/*NULL sau direct lista ca e initializata cu NULL*/ lista;
    /*creez inca un nod, si voi obtine adresa acestuia*/
    lista=creareNod(citireMuzeu(), lista);//imi insereaza un nod in fata nodului creat anterior
    /*inca o data inserare la inceputul listei mele*/
    lista=creareNod(citireMuzeu(), lista);
}

