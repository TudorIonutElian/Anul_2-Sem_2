#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <iostream>
using namespace std;

//definire nod lista simpla
struct nod
{
	int sursa, destinatie; //nodul de start si nodul terminal
	struct nod* next;
};

//functie pentru reprezentarea unui graf prin lista simpla
nod* transform_lista(nod *cap, int **a, int n)
{
    nod *p;
    //for(int i=0;i<n;i++)
	//for(int j=0;j<n;j++)
	for(int i=0;i<n-1;i++)
		  for (int j=i+1;j<n;j++)
		  {
			  if(a[i][j]) 
			  {
				  nod* nou=(nod*)malloc(sizeof(nod));
				  nou->sursa=i+1;
				  nou->destinatie=j+1;
				  if (cap==NULL) 
				  {
					  nou->next=NULL;
					  cap=nou;
				  }
				  else
				  {
					  for (p=cap;p->next;p=p->next);
					  p->next=nou;
					  nou->next=NULL;
					  p=nou;
				  }
			  }
		 }
	 return cap;
}

void dezalocare(nod* cap)
{
	nod *p,*q;
	p=cap;
	while (p)
	{
		q=p->next;
		free(p);
		p=q;
	}
}

void main()
{
	int n;
	printf("Nr. de noduri=");
	scanf ("%d", &n);
	
	int **mat=new int*[n];
	for (int i=0;i<n;i++) mat[i]=new int [n];

	//for (int i=0;i<n;i++)
	//for (int j=0;j<n;j++)
	for(int i=0;i<n-1;i++)
	for (int j=i+1;j<n;j++)
	{
		printf("Matr[%d][%d]=", i+1,j+1);
		scanf("%d",&mat[i][j] );
	}
	
	nod *cap=NULL;
	cap=transform_lista(cap,mat,n);
	nod *p=cap;
	while (p)
	{
		printf("(%d,%d) ", p->sursa, p->destinatie);
		p=p->next;
	}

	//dezalocare lista
	dezalocare(cap);
	getch();
}