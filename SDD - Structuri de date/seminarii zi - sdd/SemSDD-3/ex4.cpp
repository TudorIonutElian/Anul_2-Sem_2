#include <stdio.h>
#include <conio.h>

struct book
{
	int *ISBN;
	float *price;
};

struct nod_stiva
{
	book* inf;
	nod_stiva *nextstack;
};

//adauga un nod in stiva
nod_stiva* push(book* val, nod_stiva *stiva)
{
	if (stiva == NULL)
	{
		stiva = new nod_stiva;
		stiva->inf = val;
		stiva->nextstack = NULL;
	}
	else
	{
		nod_stiva *nou = new nod_stiva;
		nou->inf = val;
		nou->nextstack = stiva;
		stiva = nou;
	}
	return stiva;
}

//afiseaza stiva
void afisare_stiva(nod_stiva *stiva)
{
	nod_stiva *aux = stiva;
	while (aux)
	{
		printf("\nISBN=%d, price=%5.2f ", *aux->inf->ISBN, *aux->inf->price);
		aux = aux->nextstack;
	}
	printf("\n");
}

//dezalocare memorie
void dezalocare_stiva(nod_stiva *stiva)
{
	nod_stiva *p = stiva, *q;
	while(p)
	{
		q=p->nextstack;
		delete p->inf->ISBN;
		delete p->inf->price;
		delete p->inf;
		delete p;
		p=q;
	}
}

void main()
{
	nod_stiva *stiva = NULL;
	book* carte = NULL;

	int n;
	printf("Nr. carti=");
	scanf("%d",&n);
	
	for (int i=0;i<n;i++)
	{
		carte = new book;
		printf("ISBN(!=0) = "); 
		carte->ISBN = new int;
		scanf("%d", carte->ISBN);
		printf("price = "); 
		carte->price = new float;
		scanf("%f", carte->price);
		stiva=push(carte,stiva);
	}
	
	//afisare stiva
	printf("Elementele stivei sunt:\n");
	afisare_stiva(stiva);
	
	//dezalocare stiva
	dezalocare_stiva(stiva);
	printf("\nStiva a fost dezalocata!");

	getch();
}