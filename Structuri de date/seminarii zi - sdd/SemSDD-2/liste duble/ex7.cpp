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

nod* conversie(nod *cap, produs **a, int nrlin, int nrcol)
{
    nod *p;
    for(int i=0;i<nrlin;i++)
		 for(int j=0;j<nrcol;j++)
		  {
				  nod* nou=(nod*)malloc(sizeof(nod));
				  //nou->pr=a[i][j];
				  nou->pr.cod=(int*)malloc(sizeof(int));
				  nou->pr.denumire=(char*)malloc((strlen(a[i][j].denumire)+1)*sizeof(char));
				  nou->pr.cant=(float*)malloc(sizeof(float));
				  nou->pr.pret=(float*)malloc(sizeof(float));
				  *nou->pr.cod=*a[i][j].cod;
				  strcpy(nou->pr.denumire,a[i][j].denumire);
				  *nou->pr.cant=*a[i][j].cant;
				  *nou->pr.pret=*a[i][j].pret;
				  if (cap==NULL) 
				  {
					nou->next=NULL;
					nou->prev=NULL;
					cap=nou;
				  }
				  else
				  {
					for (p=cap;p->next;p=p->next);
					p->next=nou;
					nou->prev=p;
					nou->next=NULL;
					p=nou;
				  }
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
	  p=cap;
	  while(p)
	  {
		  q=p->next;
		  free(p->pr.cod);
		  free(p->pr.denumire);
		  free(p->pr.cant);
		  free(p->pr.pret);
		  free(p);
		  p=q;
	  }
}

void main()
{
	 nod* cap=NULL;
	 produs **a;
	 int n,m,i,j;
	 char buffer[20];
	 printf("\nNr. linii=");
	 scanf("%d",&n);
     printf("\nNr. coloane=");
	 scanf("%d",&m);
     a=(produs**)malloc(n*sizeof(produs*));
	 for (i=0;i<n;i++) a[i]=(produs*)malloc(m*sizeof(produs));
	 for (i=0;i<n;i++)
		 for (j=0;j<m;j++) 
		 {
			  printf("Codul=");
			  a[i][j].cod=(int*)malloc(sizeof(int));
			  scanf("%d",a[i][j].cod);
			  printf("Denumirea=");
			  scanf("%s",buffer);
			  a[i][j].denumire=(char*)malloc((strlen(buffer)+1)*sizeof(char));
			  strcpy(a[i][j].denumire,buffer);
			  printf("Cantitatea=");
			  a[i][j].cant=(float*)malloc(sizeof(float));
			  scanf("%f",a[i][j].cant);
			  printf("Pretul=");
			  a[i][j].pret=(float*)malloc(sizeof(float));
			  scanf("%f",a[i][j].pret);
		 }
 	 cap=conversie(cap,a,n,m);
     traversare(cap);

	 //dezalocare memorie
	 for (i=0;i<n;i++)
	 {
		for (j=0;j<m;j++) 
		{
			free(a[i][j].cod);
			free(a[i][j].denumire);
			free(a[i][j].cant);
			free(a[i][j].pret);
		}
		free(a[i]);
	 }
	 free(a);

	 getch();
 }
