//Numar componente conexe

#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

typedef struct coada
{
	int inf;
	struct coada* next;
};

void put(coada* &p,coada* &u,int i)
{
	coada* tmp=new coada;
	tmp->inf=i;
	tmp->next=NULL;
	if (p==NULL && u==NULL)
	{
		u=tmp;
		p=tmp;
	}
	else 
	{
		u->next=tmp;
		u=tmp;
	}
}

void get(coada* &p,coada* &u,int* nod)
{
	if (p!=NULL)
	{
		coada * t=p;
		p=p->next;
		*nod=t->inf;
		free(t);
	}
	if (p==NULL) u=NULL;
}

int a[10][10],viz[10],n,i,j;
coada *p=NULL;
coada *u=NULL;

void latime(int x)
{
	//se viziteaza nodul "x"
	viz[x]=1;
	put(p,u,x);

	while(p!=NULL)
	{ 
		//se extrage nodul "nod" din coada
		get(p,u,&x);
		//printf("%d-",x);
		for (int k=1;k<=n;k++)
		{
			//se pun in coada toate nodurile adiacente nevizitate
			if (a[x][k]==1 && viz[k]==0)
			{
				put(p,u,k);
				viz[k]=1;
			}
		}
	}
}

void main()
{
	FILE *f;
    f=fopen("ex7_date.txt","r");
	if (f)
	{
	  fscanf(f,"%d",&n);
	  for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		   fscanf(f,"%d",&a[i][j]);
	}
	else printf("\nNu exista fisier!");

	//vectorul de noduri vizitate
	for (i=1;i<=n;i++) viz[i]=0;

	int nr=0;
	for (j=1;j<=n;j++)
		if (viz[j]==0)
		{
			nr++;
			latime(j);
		}

	if (nr==1) printf("\nGraful este conex!");
	else printf("\nGraful nu este conex! El are %d componente conexe!",nr);

	getch();
}