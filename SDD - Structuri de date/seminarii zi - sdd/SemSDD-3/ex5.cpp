#include <stdio.h>
#include <conio.h>

struct book
{
	int ISBN;
	float price;
};

struct nod_stiva
{
	book inf;
	nod_stiva *nextstack;
};

//adauga un nod in stiva
void push(book val, nod_stiva **stiva)
{
	if (stiva == NULL)
	{
		(*stiva) = new nod_stiva;
		(*stiva)->inf = val;
		(*stiva)->nextstack = NULL;
	}
	else
	{
		nod_stiva *nou = new nod_stiva;
		nou->inf = val;
		nou->nextstack = (*stiva);
		(*stiva) = nou;
	}
}

//scoate un nod din stiva
int pop(book *val, nod_stiva **stiva)
{
	if (!(*stiva)) return -1;
	*val = (*stiva)->inf;
	nod_stiva *aux = (*stiva);
	(*stiva) = (*stiva)->nextstack;
	delete aux;
	return 0;
}

// conversie stiva - vector
void conversie(nod_stiva *stiva, book *v, int *k)
{
	(*k)=0;
	if (!stiva) return;
	book val;
	while (pop(&val, &stiva) == 0)
	{
		v[*k] = val;
		(*k)++;
	}
}

//afiseaza stiva
void afisare_stiva(nod_stiva *stiva)
{
	nod_stiva *aux = stiva;
	while (aux)
	{
		printf("\nISBN=%d, price=%5.2f ", aux->inf.ISBN, aux->inf.price);
		aux = aux->nextstack;
	}
	printf("\n");
}

//dezalocare stiva
void dezalocare_stiva(nod_stiva *stiva)
{
	nod_stiva *p = stiva, *q;
	while(p)
	{
		q=p->nextstack;
		delete p;
		p=q;
	}
}

void main()
{
	nod_stiva *stiva = NULL;
	book carte;
	int nrelem=0;
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte.ISBN);
	while (carte.ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte.price);
		nrelem++;
		push(carte,&stiva);
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte.ISBN);
	}

	//afisare stiva
	printf("Elementele stivei sunt:\n");
	afisare_stiva(stiva);

	book* vector = new book[nrelem];
	conversie(stiva,vector,&nrelem);
	//afisare vector
	printf("Elementele vectorului sunt:\n");
	for (int i=0;i<nrelem;i++) printf("\nISBN=%d, price=%5.2f ", vector[i].ISBN, vector[i].price);

	//dezalocare stiva
	//dezalocare_stiva(stiva);
	printf("\nStiva a fost dezalocata!");

	//dezalocare vector
	delete [] vector;
	printf("\nVectorul a fost dezalocat!");

	getch();
}
