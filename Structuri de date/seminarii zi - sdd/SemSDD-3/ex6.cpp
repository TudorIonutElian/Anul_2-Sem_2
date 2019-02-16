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

struct nod_lista
{
	book inf;
	nod_lista *prev;
	nod_lista *next;
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

//conversie stiva - lista dubla
void conversie(nod_stiva *stiva, nod_lista **cap)
{
	if (!stiva) return;
	book val;
	while (pop(&val, &stiva) == 0)
	{
		//adauga un nod in lista
		if (*cap == NULL)
			{
				nod_lista *nou = new nod_lista;
				nou->inf=val;
				nou->next=NULL;
				nou->prev=NULL;
				(*cap)=nou;
			}
			else
			{
                nod_lista *nou = new nod_lista;
				nod_lista *p;
				for (p=(*cap);p->next;p=p->next);
				nou->inf=val;
				p->next=nou;
				nou->prev=p;
				nou->next=NULL;
			}
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

//dezalocare lista
void dezalocare_lista(nod_lista *cap)
{
	nod_lista *p = cap, *q;
	while(p)
	{
		q=p->next;
		delete p;
		p=q;
	}
}

void main()
{
	nod_stiva *stiva = NULL;
	nod_lista *cap = NULL;

	book carte;
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte.ISBN);
	while (carte.ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte.price);
		push(carte,&stiva);
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte.ISBN);
	}

	//afisare stiva
	printf("Elementele stivei sunt:\n");
	afisare_stiva(stiva);

	//conversie stiva - lista dubla
    conversie(stiva, &cap);

	//afisare lista
	printf("\nElementele listei duble sunt:");
    for (nod_lista *p=cap; p; p=p->next) printf("\nISBN=%d, price=%5.2f ", p->inf.ISBN, p->inf.price);

	//dezalocare stiva
	//dezalocare_stiva(stiva);
	printf("\nStiva a fost dezalocata!");

	//dezalocare lista
	dezalocare_lista(cap);
	printf("\nLista dubla a fost dezalocata!");

	getch();
}
