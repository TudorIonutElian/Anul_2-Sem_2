#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>

struct produs
{
	int *cod;
	char *denumire;
	float *cant;
	float *pret;
};

struct nod
{
	produs pr;
    struct nod *prev, *next;
};

nod* inserare(nod* cap, produs prod)
{
	nod* nou;
	nou=(nod*)malloc(sizeof(nod));
	if (cap==NULL) 
	{ 
		nou->pr=prod;
		nou->next=nou;
		nou->prev=nou;
		return nou; 
	}
	nod* p=cap;
	while (p->next!=cap) p=p->next;
	nou->pr=prod;
	p->next=nou;
	nou->prev=p;
	nou->next=cap;
	cap->prev=nou;
	return cap;
}

void traversare(nod *cap)
{
	  nod *p,*q;
	  float val=0;
	  printf("\nCod Denumire Cantitate Pret Valoare");
      p=cap; 
	  while(p->next!=cap)
      {
		  printf("\n%d %s %5.2f %5.2f %5.2f",*p->pr.cod, p->pr.denumire, *p->pr.cant, *p->pr.pret, (*p->pr.cant)*(*p->pr.pret));
		  val+=(*p->pr.cant)*(*p->pr.pret);
	      p=p->next;
	  }
	  printf("\n%d %s %5.2f %5.2f %5.2f",*p->pr.cod, p->pr.denumire, *p->pr.cant, *p->pr.pret, (*p->pr.cant)*(*p->pr.pret));
	  val+=(*p->pr.cant)*(*p->pr.pret);
	  printf("\nValoare totala=%5.2f",val);
	  //dezalocare memorie
	  p=cap;
	  while(p->next!=cap)
	  {
		  q=p->next;
		  free(p->pr.cod);
		  free(p->pr.denumire);
		  free(p->pr.cant);
		  free(p->pr.pret);
		  free(p);
		  p=q;
	  }
	  free(p->pr.cod);
	  free(p->pr.denumire);
	  free(p->pr.cant);
	  free(p->pr.pret);
	  free(p);
}

void main()
{
     nod *cap=NULL;
     int n;
	 char buffer[20];
	 produs inf;
	 printf("Numar produse=");
	 scanf("%d",&n);
	 for (int i=0;i<n;i++)
     {
		printf("Codul=");
		inf.cod=(int*)malloc(sizeof(int));
		scanf("%d",inf.cod);
		printf("Denumirea=");
		scanf("%s",buffer);
		inf.denumire=(char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(inf.denumire,buffer);
		printf("Cantitatea=");
		inf.cant=(float*)malloc(sizeof(float));
		scanf("%f",inf.cant);
		printf("Pretul=");
		inf.pret=(float*)malloc(sizeof(float));
		scanf("%f",inf.pret);
		cap=inserare(cap,inf);
	 }
     traversare(cap); 
	 getch();
 }
