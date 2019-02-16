#include <iostream>
#include <stdio.h> 
#include <conio.h>
#pragma warning (disable:4996)

struct tara {
	int id;
	char *nume;
	int nr_locuitori;
	float suprafata;
};

struct nod {
	tara info;
	nod* st; 
	nod* dr;
};  

tara taraNoua(int id, char*nume , int nrl, float suprafata){
	tara t1;
	t1.nume = (char*)malloc((strlen(nume) + 1)*sizeof(char));
	strcpy(t1.nume, nume);
	t1.id = id;
	t1.nr_locuitori = nrl;
	t1.suprafata = suprafata;

	return t1;
}
nod* creareNod(tara info, nod * stg, nod* drt){
	nod* p = (nod*)malloc(sizeof(nod));
	p->st = stg;
	p->dr = drt;
	p->info.nume = (char*)malloc(sizeof(char)*(strlen(info.nume) + 1));
	strcpy(p->info.nume, info.nume);
	p->info.id = info.id;
	p->info.nr_locuitori = info.nr_locuitori;
	p->info.suprafata = info.suprafata;
return p;
}


nod* inserare(nod *radacina, tara t)
{
	if (radacina == NULL){
		radacina = creareNod(t, NULL, NULL);
			return radacina;
	}
	else {
		if (t.id < radacina->info.id){
			radacina->st = inserare(radacina->st, t);
		}
		else {
		radacina->dr = inserare(radacina->dr, t);
		}
		return radacina;
		}
		
	}

void srd(nod* rad){
	if (rad){
		srd(rad->st);
		printf("%d. %s \n", rad->info.id,rad->info.nume);
		srd(rad->dr);
	}
}
int nivele(nod*rad){
	if (rad){}
}
void main(){
	tara t1 = taraNoua(3, "Romania", 18, 1000);
	tara t2 = taraNoua(1, "Somalia", 50, 100);
	tara t3 = taraNoua(7, "India", 100, 10);


	nod* radacina = NULL;
	radacina = inserare(radacina, t1);
	radacina = inserare(radacina, t2);
	radacina = inserare(radacina, t3);
	srd(radacina);
	_getch();


}