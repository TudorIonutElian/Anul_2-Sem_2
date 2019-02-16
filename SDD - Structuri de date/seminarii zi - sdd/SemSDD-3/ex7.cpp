#include <stdio.h>
#include <conio.h>

struct book
{
	int ISBN;
	float price;
};

struct nod_coada
{
	book inf;
	nod_coada *nextqueue;
};

void push(nod_coada **p, nod_coada **u, book c)
{
	nod_coada* tmp=new nod_coada;
	tmp->inf=c;
	tmp->nextqueue=NULL;
	if (*p==NULL && *u==NULL)
	{
		*u=tmp;
		*p=tmp;
	}
	else 
	{
		(*u)->nextqueue=tmp;
		*u=tmp;
	}
}

void pop(nod_coada **p, nod_coada **u, book *c)
{
	if (*p!=NULL)
	{
		nod_coada *temp=*p;
		*p=(*p)->nextqueue;
		*c=temp->inf;
		delete temp;
	}
	if (*p==NULL) *u=NULL;
}

//afiseaza coada
void afisare_coada(nod_coada *p, nod_coada *u)
{
	nod_coada *prim=p;
	nod_coada *ultim=u;
	while (prim!=NULL)
	{
		nod_coada *temp=prim;
		prim=prim->nextqueue;
		printf("\nISBN=%d, price=%5.2f ", temp->inf.ISBN, temp->inf.price);
	}
	if (prim==NULL) ultim=NULL;
}

//dezalocare coada
void dezalocare_coada(nod_coada *p, nod_coada *u)
{
	nod_coada *aux = p, *q;
	while(aux)
	{
		q=aux->nextqueue;
		delete aux;
		aux=q;
	}
	if (p==NULL) u=NULL;
}

void main()
{
	nod_coada *p = NULL;
	nod_coada *u = NULL;

	book carte;
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte.ISBN);
	while (carte.ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte.price);
		push(&p,&u,carte);
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte.ISBN);
	}

	//afisare coada
	printf("Coada este:\n");
	afisare_coada(p,u);

	//dezalocare coada
	dezalocare_coada(p,u);
	printf("\nCoada a fost dezalocata!");

	getch();
}
