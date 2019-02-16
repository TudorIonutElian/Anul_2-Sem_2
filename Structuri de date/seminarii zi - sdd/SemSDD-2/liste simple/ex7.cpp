#include<stdio.h>
#include<malloc.h>
#include<conio.h>

typedef struct nod
{
	float inf;
    struct nod* next;
};

void crearelista(nod **cap)
{
	nod *p, *q;
	float inf1;
	printf("\n");
	printf("Capul listei=");
	scanf("%f", &inf1);
	(*cap)=(nod*)malloc(sizeof(nod));
	(*cap)->inf=inf1;
	(*cap)->next=NULL;
	p=(*cap);
	printf("Informatie nod sau CTRL-Z=");
	scanf("%f",&inf1);
	while(!feof(stdin))
	{
		q=(nod*)malloc(sizeof(nod));
		q->inf=inf1;
		q->next=NULL;
		p->next=q;
		p=q;
		printf("Informatie nod sau CTRL-Z=");
		scanf("%f",&inf1);
	}
}

void stergere_nod_cu_inf_data(nod** cap,float inf2)
{
	nod *p, *q;
	if((*cap)&&((*cap)->inf==inf2)) 
	{
	p=*cap;
	(*cap)=(*cap)->next;
	free(p);
	}
	if(*cap)
	{
		p=*cap;
		{
			while ((p->next)&&(p->next->inf!=inf2))
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

int stergere_dupa_pozitie(nod* cap,int k)
{
    int er,i;
    nod* aux;
    int contor=0;
    nod* aux2;
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

int sterg_lista(nod* cap)
{
	nod* p;
	while (cap)
	{
		p=cap;
		cap=cap->next;
		free (p);
	}
return NULL;
}

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

nod* sterg_inainte_inf(nod* cap, float a, int *er)
{
	nod *p,*q;
	if (!cap) *er=2;
	else 
	{
		p=cap;
		if(cap->inf==a)*er=1;
		else 
		if(cap->next)
		if (cap->next->inf==a)
		{
			*er=0;
			p=cap;
			cap=cap->next;
		free(p);
		}
		else if (cap->next->next)
		{
			p=cap;
			while((p->next->next)&&(p->next->next->inf!=a))
			p=p->next;
			if (p->next->next)
			{
				q=p->next;
				p->next=p->next->next;
				free(q);
				* er=0;
			}
			else *er=2;
		}
	}
return cap;
}

int main(void)
{
     nod *cap,*p,*q;
     int rest,intinfo,n,i,k,er,optiune;
     float a, inf2;
     char rasp[2];
     printf("\nCREAREA UNEI LISTE SIMPLU INLANTUITE");
     printf("\n------------------------------------");
     crearelista(&cap);
      //afisare lista
      printf("\n");
      p=cap;
      while(p)
      {
	      printf("\t %5.2f",p->inf);
	      p=p->next;
	      }
       int x;
       printf("\n");
       printf("\nPROGRAM CU VARIANTE DE STERGERE DINTR-O LISTA SIMPLU INLANTUITA");
       printf("\n---------------------------------------------------------------");
       printf("\n");
       printf("\n1 - Stergerea elementului de pe pozitia K");
       printf("\n2 - Stergerea elementului cu o anumita valoare citita");
       printf("\n    -para");
       printf("\n    -impara");
       printf("\n    -oarecare");
       printf("\n3 - Stergerea elementelor de pe pozitii pare");
       printf("\n4 - Stergerea elementelor de pe pozitii impare");
       printf("\n5 - Stergerea nodului situat inaintea unui nod cu informatie data");
       printf("\n6 - Stergerea intregii liste");
       printf("\n");
       printf("\nIntroduceti varianta de stergere:");
       scanf("%i",&x);
       while (!feof(stdin)) {
       if (x==1)
       {
       printf ("Introduceti pozitia K:    ");
       scanf("%i",&k);
       er=stergere_dupa_pozitie(cap,k);

		printf("\n");
      p=cap;
      while(p)
      {
	      printf("\t %5.2f",p->inf);
	      p=p->next;
      }//afiseaza lista dupa stergerea nodului dupa pozitia k
      }
      else
      if (x==2) {
      printf("\n     Valoarea pe care doriti sa o stergeti este:");
      printf("\n       1 - para");
      printf("\n       2 - impara");
      printf("\n       3 - oarecare");
      printf("\n\t\tAlegeti tipul valorii:");
      scanf("%i",&optiune);
      if(optiune==1)
      {
      printf("\n       Acum introduceti valoarea pe care doriti sa o stergeti:  ");
      scanf("%f",&inf2);
      intinfo=int(inf2);
      rest=intinfo%2;
      if(rest)
      {
      printf("\n Valoarea introdusa este impara, reintroduceti o alta valoare care sa fie para=");
      scanf("%f",&inf2);
      }
      stergere_nod_cu_inf_data(&cap,inf2);
      }
      else
      if (optiune==2)
      {
      printf("\n        Acum introduceti valoarea pe care doriti sa o stergeti:  ");
      scanf("%f",&inf2);
      intinfo=int(inf2);
      rest=intinfo%2;
      if(rest==0)
      {
      printf("\n Valoarea introdusa este para, reintroduceti o alta valoare care sa fie impara=");
      scanf("%f",&inf2);
      }
      stergere_nod_cu_inf_data(&cap,inf2);
      }
      else
      if (optiune==3)
      {
      printf("\n        Acum introduceti valoarea pe care doriti sa o stergeti:  ");
      scanf("%f",&inf2);
      stergere_nod_cu_inf_data(&cap,inf2);
      }
      printf("\n");
      p=cap;
      while(p)
      {
	      printf("\t %5.2f",p->inf);
	      p=p->next;
	      }//afiseaza lista dupa stergerea nodului de informatie introdusa de la tastatura
	}
	else
	  if (x==3) 
	  {
		sterge_poz_pare(cap);//sterge nodurile pare din lista
		printf("\n");
		p=cap;
		while(p)
		{
	      printf("\t %5.2f",p->inf);
	      p=p->next;
	    }//afiseaza lista dupa stergerea nodului de informatie introdusa de la tastatura
		}
		else
		if (x==4) 
		{
		sterge_poz_impare(cap);//sterge nodurile impare din lista
		printf("\n");
		p=cap;
		while(p)
		{
	      printf("\t %5.2f",p->inf);
	      p=p->next;
	      }//afiseaza lista dupa stergerea nodului de informatie introdusa de la tastatura
		}
		else
		if (x==5) 
		{
			printf("Introduceti informatia=");
			scanf("%f",&a);
			cap=sterg_inainte_inf(cap,a,&er);
			if (er==2) printf("lista vida!");
			else if (er==1) printf("Nu exista elementul respectiv!");
			else printf("Stergere realizata!");
			printf("\n");
			p=cap;
			while (p)
			{
				printf("\t %5.2f",p->inf);
				p=p->next;
			}
		}
		else
		if (x==6) 
		{
			sterg_lista(cap);//sterge lista
			printf("Lista a fost stearsa\n");
		} 
		printf("\nIntroduceti varianta de stergere sau CTRL-Z=");
		scanf("%i",&x);
      }
      return 0;
      getch();
}
