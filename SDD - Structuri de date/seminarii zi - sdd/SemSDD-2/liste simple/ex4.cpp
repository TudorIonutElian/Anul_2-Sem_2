#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>

struct produs
{	
	int cod;
	char *denumire;
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
	char buffer[20];
	cap=(nod*)malloc(sizeof(nod));
	printf("\n");
	printf("Codul=");
	scanf("%d",&cap->inf.cod);
	printf("Denumirea=");
	scanf("%s",buffer);
	cap->inf.denumire=(char*)malloc(strlen(buffer)*sizeof(char));
	strcpy(cap->inf.denumire,buffer);
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
		printf("Denumirea=");
		scanf("%s",buffer);
		q->inf.denumire=(char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(q->inf.denumire,buffer);
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
	  printf("\nCod Denumire Cantitate Pret Valoare");
      p=cap; 
	  while(p)
      {
		  printf("\n%d %s %5.2f %5.2f %5.2f",p->inf.cod, p->inf.denumire, p->inf.cantitate, p->inf.pret,(p->inf.cantitate)*(p->inf.pret));
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
