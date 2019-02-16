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

nod* conversie(produs *v, int n, nod* cap)
{  
    nod* nou=(nod*)malloc(sizeof(nod));
	nou->pr=v[0];
	nou->next=NULL;
	nou->prev=NULL;
	cap=nou;
	nod* p=cap;
    for(int i=1;i<n;i++) 
    {  
	  nou=(nod*)malloc(sizeof(nod));
	  nou->pr=v[i];
	  nou->next=NULL;
	  nou->prev=p;
	  p->next=nou;
	  p=nou;
    }
    return cap;
}

void traversare(nod *cap)
{
	  nod *p,*q;
	  float val=0;
	  printf("\nCod Denumire Cantitate Pret Valoare");
      p=cap; 
	  while(p)
      {
		  printf("\n%d %s %5.2f %5.2f %5.2f",*p->pr.cod, p->pr.denumire, *p->pr.cant, *p->pr.pret, (*p->pr.cant)*(*p->pr.pret));
		  val+=(*p->pr.cant)*(*p->pr.pret);
	      p=p->next;
	  }
	  printf("\nValoare totala=%5.2f",val);
	  //dezalocare memorie
	  /*p=cap;
	  while(p)
	  {
		  q=p->next;
		  free(p->pr.cod);
		  free(p->pr.denumire);
		  free(p->pr.cant);
		  free(p->pr.pret);
		  free(p);
		  p=q;
	  }*/
}

void main()
{
	 nod* cap=NULL;
	 produs *v;
     int i,n;
	 char buffer[20];
     printf("Nr. de elemente ale vectorului=");
     scanf("%d",&n);
     v=(produs*)malloc(n*sizeof(produs));
     for(i=0;i<n;i++)
     {
		printf("Codul=");
		v[i].cod=(int*)malloc(sizeof(int));
		scanf("%d",v[i].cod);
		printf("Denumirea=");
		scanf("%s",buffer);
		v[i].denumire=(char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(v[i].denumire,buffer);
		printf("Cantitatea=");
		v[i].cant=(float*)malloc(sizeof(float));
		scanf("%f",v[i].cant);
		printf("Pretul=");
		v[i].pret=(float*)malloc(sizeof(float));
		scanf("%f",v[i].pret);
	 }

	 cap=conversie(v,n,cap);
     traversare(cap);
	 
	 //dezalocare memorie
	 for (i=0;i<n;i++)
	 {
		free(v[i].cod);
		free(v[i].denumire);
		free(v[i].cant);
		free(v[i].pret);
	 }
	 free(v);

	 getch();
 }
