#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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

void main()
{
	//matricea de adiacenta
	int mat[10][10];

	coada *p=NULL;
	coada *u=NULL;
	int n,i;
	printf("Numarul de noduri ale grafului:");
	scanf("%d",&n);

	//matricea de adiacenta este populata cu 0
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		mat[i][j]=0;
	}	

	int ii, jj;
	char c='d';
	while(c=='d' || c=='D')
	{	
		printf("Nodul de la care porneste arcul:");
		fflush(stdin);
		scanf("%d",&ii);
		printf("Nodul la care ajunge arcul:");
		scanf("%d",&jj);
		//matricea de adiacenta este populata cu 1 
		mat[ii][jj]=1;
		mat[jj][ii]=1;
		cout<<"Mai introduceti d/n: ";
		cin>>c;
	}

	//vectorul de noduri vizitate
	int viz[10];
	printf("Parcurgere in latime de la nodul :");
	int nod;
	scanf("%d",&nod);
	for (i=1;i<=n;i++) viz[i]=0;
	//se viziteaza nodul "nod"
	viz[nod]=1;
	put(p,u,nod);

	printf("Parcurgerea in latime este urmatoarea:");
	while(p!=NULL)
	{ 
		//se extrage nodul "nod" din coada
		get(p,u,&nod);
		printf("%d-",nod);
		for (int k=1;k<=n;k++)
		{
			//se pun in coada toate nodurile adiacente nevizitate
			if (mat[nod][k]==1 && viz[k]==0)
			{

				put(p,u,k);
				viz[k]=1;
			}
		}
	}
	getch();
}
