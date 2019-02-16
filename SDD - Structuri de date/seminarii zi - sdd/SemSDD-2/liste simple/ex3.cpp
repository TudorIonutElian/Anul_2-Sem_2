#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct produs
{	
	int cod;
	float cantitate;
	float pret;
};

struct nod
{
	produs inf;
    struct nod* next;
};

nod* crearelista(nod *cap, int n)
{
	nod *p, *q;
	cap=(nod*)malloc(sizeof(nod));
	printf("\n");
	printf("Codul=");
	scanf("%d",&cap->inf.cod);
	printf("Cantitatea=");
	scanf("%f",&cap->inf.cantitate);
	printf("Pretul=");
	scanf("%f",&cap->inf.pret);
	cap->next=NULL;
	p=cap;
	for (int i=1;i<n;i++)
	{
		q=(nod*)malloc(sizeof(nod));
		printf("Codul=");
		scanf("%d",&q->inf.cod);		
		printf("Cantitatea=");
		scanf("%f",&q->inf.cantitate);
		printf("Pretul=");
		scanf("%f",&q->inf.pret);
		q->next=NULL;
		p->next=q;
		p=q;
	}
return cap;
}

void traversare(nod *cap)
{
	  nod *p;
	  float val=0;
	  printf("\nCod Cantitate Pret Valoare");
      p=cap; 
	  while(p)
      {
		  printf("\n%d %5.2f %5.2f %5.2f",p->inf.cod, p->inf.cantitate, p->inf.pret,(p->inf.cantitate)*(p->inf.pret));
		  val+=(p->inf.cantitate)*(p->inf.pret);
	      p=p->next;
	  }
	  printf("\nValoare totala=%5.2f",val);
}

void main()
{
     nod *cap=NULL;
     int n;
	 printf("Numar produse=");
	 scanf("%d",&n);
	 cap=crearelista(cap,n);
     traversare(cap);    
	 getch();
}
