# include <stdio.h>
# include <malloc.h>
# include <conio.h>

typedef struct nod 
{
	float inf;
	struct nod *leg;
};

nod* ins(nod* cap,float d,int *er)
{
	nod* nou;
	if (nou=(nod*)malloc(sizeof(nod)))
	{ 
		*er=0;
		if (cap==NULL) 
		{ 
			nou->inf=d;
			nou->leg=nou;
			return nou; 
		}
	else 
	{ 
		nod* p=cap;
		while (p->leg!=cap) p=p->leg;
		nou->inf=d;
		p->leg=nou;
		nou->leg=cap;
		return cap;
	}
	}
	else 
	{ 
		*er=1;
		return cap;
	}
}

void main()
{
	int n,i,er;
	nod* cap=NULL;
	printf("\n Nr. noduri=");
	scanf("%i",&n);
	er=0;
	float d,k;
	for (i=0;(i<n)&&(!er);i++)
	{
		printf("Informatia=");
		scanf("%f",&d);
		cap=ins(cap,d,&er);
	}
	if (er) printf("Nu se poate crea");
	else 
	{
		printf("%5.0f",cap->inf);
		for (nod* p=cap;p->leg!=cap;p=p->leg) printf("%5.0f",p->leg->inf);
	}
	getch();
}
