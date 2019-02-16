#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

typedef struct stiva
{
	int inf;
	struct stiva* next;
};

void push(stiva* &p,int i)
{
	stiva* tmp = new stiva;
	tmp->inf=i;
	tmp->next=NULL;
	if (p==NULL)
	{
		p=tmp;
	}
	else 
	{
		tmp->next=p;
		p=tmp;
	}
}

void pop(stiva* &p,int* nod)
{
	if (p!=NULL)
	{
		stiva *t=p;
		p=p->next;
		(*nod)=t->inf;
		free(t);
	}
}

void main()
{
	//matricea de adiacenta
	int mat[10][10];

	//varful stivei
	stiva* p=NULL;
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
	printf("Introducere arce:\r\n");
	while(c=='d' || c=='D')
	{	
		printf("Nodul de la care porneste arcul:");
		fflush(stdin);
		scanf("%d",&ii);
		printf("Nodul la care ajunge arcul:");
		scanf("%d",&jj);
		//matricea de adiacenta este populata cu 1 
		mat[ii][jj]=1;
		//mat[jj][ii]=1;
		cout<<"Mai introduceti d/n: ";
		cin>>c;
	}

	printf("Parcurgere in adancime de la nodul:");
	int nod;
	scanf("%d",&nod);

	//vectorul de noduri vizitate
	int viz[100];
	for (i=1;i<=n;i++) viz[i]=0;
	//se viziteaza nodul "nod"
	viz[nod]=1;
	push(p,nod);

	printf("Parcurgerea in adancime este urmatoarea:");
	while(p!=NULL)
	{ 
		//se extrage nodul "nod" din stiva
		pop(p,&nod);
		printf("%d-",nod);
		for (int k=1;k<=n;k++)
		{ 
			//se pun in stiva toate nodurile adiacente nevizitate
			if (mat[nod][k]==1 && viz[k]==0)
			{
				push(p,k);
				viz[k]=1;
			}
		}
	}
	getch();
}