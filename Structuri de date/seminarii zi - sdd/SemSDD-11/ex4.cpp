//Inchiderea tranzitiva a grafului

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

void afisare(int a[20][20],int n)
{
  int i,j;
  for(i=1;i<=n;i++)
    {
		for(j=1;j<=n;j++)
		printf("%6d",a[i][j]);
		printf("\n");
    }
}

void main()
{
	int a[20][20],a_tranz[20][20],viz[20],nod,n,i,j,k;

	//varful stivei
	stiva* p=NULL;
	
	FILE *f;
    f=fopen("ex4_date.txt","r");
	if (f)
	{
	  fscanf(f,"%d",&n);
	  for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		   fscanf(f,"%d",&a[i][j]);
	}
	else printf("\nNu exista fisier!");

	printf("\nGraful are %d noduri, matricea sa de adiacenta fiind:\n",n);
	afisare(a,n);

	//se creeza matricea închiderii tranzitive iniþialã plecând de la matricea de adiacenþã a grafului
	for(i = 1; i<=n; i++)
		for(j = 1; j<=n; j++)
			if(i==j) 
				a_tranz[i][j] = 1;
			else
				a_tranz[i][j] = a[i][j];
	
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++) viz[j]=0;

		//se viziteaza nodul "i"
		viz[i]=1;
		push(p,i);

		while(p!=NULL)
		{ 
			//se extrage nodul "nod" din stiva
			pop(p,&nod);
			printf("%d-",nod);
			a_tranz[i][nod]=1;

			for (int k=1;k<=n;k++)
			{ 
				//se pun in stiva toate nodurile adiacente nevizitate
				if (a[nod][k]==1 && viz[k]==0)
				{
					push(p,k);
					viz[k]=1;
				}
			}
		}
		printf("\n");
	}

	//se afiseaza inchiderea tranzitiva a grafului
	printf("\nInchiderea tranzitiva a grafului este:\n",n);
	afisare(a_tranz,n);
  	 
	getch();
}