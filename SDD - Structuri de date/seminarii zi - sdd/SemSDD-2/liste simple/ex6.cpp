#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct nod
{
	float cod,cant,pret;
    struct nod* next;
};

nod* crearelista(nod *cap)
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
	cap=(nod*)malloc(sizeof(nod));
	cap->cod=cod1;
	cap->cant=cant1;
	cap->pret=pret1;
	cap->next=NULL;
	p=cap;
	while (!feof(stdin))
	{
		printf("Codul=");
		scanf("%f",&cod1);
		if (!feof(stdin)) 
		{
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
return cap;
}

//stergerea primului nod cu informatie data
void stergere_nod_cu_cod_dat(nod** cap, float cod2)
{
	nod *p, *q;
	if((*cap)&&((*cap)->cod==cod2)) 
	{
		p=*cap;
		(*cap)=(*cap)->next;
		free(p);
	}
	if(*cap)
		{
			p=*cap;
			{
				while ((p->next)&&(p->next->cod!=cod2))
				p=p->next;
				if (p->next)
				{
					q=p->next;
					p->next=p->next->next;
					free(q);
				}
			}
		}
}

//stergerea primului nod situat inaintea unui nod cu informatie data
nod* sterg_inainte_inf(nod* cap, float a, int *er)
{
	nod *p,*q;
	if (!cap) *er=2;
	else 
	{
		p=cap;
		if(cap->cod==a)*er=1;
		else 
		if(cap->next)
		if (cap->next->cod==a)
		{
			*er=0;
			p=cap;
			cap=cap->next;
			free(p);
		}
		else if (cap->next->next)
		{
			p=cap;
			while((p->next->next)&&(p->next->next->cod!=a))
			p=p->next;
			if (p->next->next)
			{
				q=p->next;
				p->next=p->next->next;
				free(q);
				*er=0;
			}
			else *er=2;
		}
	}
return cap;
}

//calcul numar de noduri ale listei
int numar_noduri(nod *cap)
{
    int nr=0;
    nod *aux;
    aux=cap;
    while(aux)
    {
	      aux=aux->next;
	      nr++;
    }
    return nr;
}

//stergere nod de pe pozitia "k"
int stergere_pozitie(nod* cap, int k)
{
    int er,i,contor=0;
    nod *aux,*aux2;
    int nr=numar_noduri(cap);
    if ((k>nr) || (k<0)) er=1;
    else
    {
	if (k==0)
	{
		  aux=cap;
		  cap=cap->next;
		  free(aux);
		  er=1; //s-a facut stergerea
	}
         else
         {
            aux=cap;
			while((aux->next!=NULL)&&(contor<k-1))
			{
			aux=aux->next;
			contor++;
	     }
	     aux2=aux->next;
	     aux->next=aux2->next;
	     free(aux2);
	     er=1;
	}
    }
    return er;
}

//stergere noduri de pe pozitii pare
void sterge_poz_pare(nod *&cap)
{
	nod *a,*pa;
	int contor=1;
	pa=NULL;
	a=cap;
	while(a)
	{
		if(contor%2==0)//cand sterg
		{
			if(pa==NULL)
			{
				cap=cap->next;
				free(a);
				a=cap;
			}
			else
			{
				pa->next=a->next;
				free(a);
				a=pa->next;
			}
		}
		else
		{
			pa=a;//asta se intampla cand nu sterg
			a=a->next;
		}
		contor++;
	}
}

//stergere noduri de pe pozitii impare
void sterge_poz_impare(nod *&cap)
{
	nod *a,*pa;
	int contor=1;
	pa=NULL;
	a=cap;
	while(a)
	{
		if(contor%2==1)// cand sterg
		{
			if(pa==NULL)
			{
				cap=cap->next;
				free(a);
				a=cap;
			}
			else
			{
				pa->next=a->next;
				free(a);
				a=pa->next;
			}
		}
		else
		{
			pa=a;//asta se intampla cand nu sterg
			a=a->next;
		}
		contor++;
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
	      printf("\n%5.2f %5.2f %5.2f %5.2f",p->cod, p->cant, p->pret,(p->cant)*(p->pret));
		  val+=(p->cant)*(p->pret);
	      p=p->next;
	  }
	  printf("\nValoare totala=%5.2f",val);
}

void main()
{
     nod *cap=NULL;
	 cap=crearelista(cap);
     traversare(cap);
	 
	 //stergerea primului nod cu informatie data
	 float codd;
     printf("\nIntroduceti codul produsului pe care doriti sa-l stergeti:  ");
     scanf("%f",&codd);
     stergere_nod_cu_cod_dat(&cap,codd);
	 traversare(cap);

	 //stergerea primului nod situat inaintea unui nod cu informatie data
	 float codi;
     printf("\nIntroduceti codul produsului:  ");
     scanf("%f",&codi);
	 int er;
	 cap=sterg_inainte_inf(cap,codi,&er);
     if (er==2) printf("Lista vida!");
     else if (er==1) printf("Nu exista elementul respectiv!");
     else printf("Stergere realizata!");
     traversare(cap);

	 //stergere nod de pe pozitia "k"
	 int pozitie, eroare;
	 printf("\nIntroduceti pozitia k a nodului pe care doriti sa-l stergeti:  ");
     scanf("%d",&pozitie);
     eroare=stergere_pozitie(cap,pozitie);
	 if (eroare) traversare(cap);

	 //stergere noduri de pe pozitii pare
     sterge_poz_pare(cap);
	 traversare(cap);

     //stergere noduri de pe pozitii impare
	 sterge_poz_impare(cap);
	 traversare(cap);

	 getch();
 }
