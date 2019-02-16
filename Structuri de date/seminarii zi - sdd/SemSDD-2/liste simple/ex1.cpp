#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct nod
{
	float cod,cant,pret;
	struct nod* next;
};

void crearelista(nod **cap, int n)
{
	nod *p, *q;
	float cod1,cant1,pret1;
	printf("\n");
	printf("Codul=");
	scanf("%f",&cod1);
	printf("Cantitatea=");
	scanf("%f",&cant1);
	printf("Pretul=");
	scanf("%f",&pret1);
	(*cap)=(nod*)malloc(sizeof(nod));
	(*cap)->cod=cod1;
	(*cap)->cant=cant1;
	(*cap)->pret=pret1;
	(*cap)->next=NULL;
	p=(*cap);
	for (int i=1;i<n;i++)
	{
		printf("Codul=");
		scanf("%f",&cod1);
		printf("Cantitatea=");
		scanf("%f",&cant1);
		printf("Pretul=");
		scanf("%f",&pret1);
		q=(nod*)malloc(sizeof(nod));
		q->cod=cod1;
		q->cant=cant1;
		q->pret=pret1;
		q->next=NULL;
		p->next=q;
		p=q;
	}
}

void traversare(nod *cap)
{
	  nod *p;
	  float val=0;
	  printf("\nCod Cantitate Pret Valoare");
      p=cap; 
	  while(p)
      {
	      printf("\n%5.2f %5.2f %5.2f %5.2f",p->cod, p->cant,p->pret,(p->cant)*(p->pret));
		  val+=(p->cant)*(p->pret);
	      p=p->next;
	  }
	  printf("\nValoare totala=%5.2f",val);
}

int main(void)
{
     nod *cap;
     int n;
	 printf("Numar produse=");
	 scanf("%d",&n);
     crearelista(&cap,n);
     traversare(cap);    
	 getch();
	 return 0;
 }
