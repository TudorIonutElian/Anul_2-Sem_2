#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>

struct produs
{
	int cod;
	char *denumire;
	float cant;
	float pret;
};

struct nod
{
	produs pr;
    struct nod *prev, *next;
};

nod* crearelista(nod *cap, int n)
{
	nod *p, *q;
	int cod1;
	char buffer[20];
	float cant1,pret1;
	printf("\n");
	printf("Codul=");
	scanf("%d",&cod1);
	printf("Denumirea=");
	scanf("%s",buffer);
	printf("Cantitatea=");
	scanf("%f",&cant1);
	printf("Pretul=");
	scanf("%f",&pret1);
	cap=(nod*)malloc(sizeof(nod));
	cap->pr.cod=cod1;
	cap->pr.denumire=(char*)malloc((strlen(buffer)+1)*sizeof(char));
	strcpy(cap->pr.denumire,buffer);
	cap->pr.cant=cant1;
	cap->pr.pret=pret1;
	cap->prev=NULL;
	cap->next=NULL;
	p=cap;
	for (int i=1;i<n;i++)
	{
		printf("Codul=");
		scanf("%d",&cod1);
		printf("Denumirea=");
		scanf("%s",buffer);
		printf("Cantitatea=");
		scanf("%f",&cant1);
		printf("Pretul=");
		scanf("%f",&pret1);
		q=(nod*)malloc(sizeof(nod));
		q->pr.cod=cod1;
		q->pr.denumire=(char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(q->pr.denumire,buffer);
		q->pr.cant=cant1;
		q->pr.pret=pret1;
		q->next=NULL;
		q->prev=p;
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
		  printf("\n%d %s %5.2f %5.2f %5.2f",p->pr.cod, p->pr.denumire, p->pr.cant, p->pr.pret,(p->pr.cant)*(p->pr.pret));
		  val+=(p->pr.cant)*(p->pr.pret);
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
