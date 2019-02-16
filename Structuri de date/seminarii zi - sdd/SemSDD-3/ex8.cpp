#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct student 
{
	int cod;
	char* nume;
	int varsta;
};

struct nod_coada
{
	student inf;
	nod_coada *nextqueue;
};

void push(nod_coada **p, nod_coada **u, student stud)
{
	nod_coada* tmp=new nod_coada;
	tmp->inf.cod=stud.cod;
	tmp->inf.nume=new char[strlen(stud.nume)+1];
	strcpy(tmp->inf.nume,stud.nume);
	tmp->inf.varsta=stud.varsta;
	tmp->nextqueue=NULL;
	if (*p==NULL && *u==NULL)
	{
		*u=tmp;
		*p=tmp;
	}
	else 
	{
		(*u)->nextqueue=tmp;
		*u=tmp;
	}
}

int pop(nod_coada **p, nod_coada **u, student *s)
{
	if (*p==NULL) 
	{
		*u=NULL;
		return 0;
	}
	else if (*p!=NULL)
	{
		nod_coada *temp=*p;
		*p=(*p)->nextqueue;
		*s=temp->inf;
		delete temp;
		return 1;
	}
}

// conversie coada - vector
void conversie(nod_coada *p, nod_coada *u, student *v, int *k)
{
	(*k)=0;
	student s;
	while (pop(&p,&u,&s))
	{
		v[*k]=s;
		(*k)++;
	}
}

//afiseaza coada
void afisare_coada(nod_coada *p, nod_coada *u)
{
	nod_coada *prim=p;
	nod_coada *ultim=u;
	while (prim!=NULL)
	{
		printf("\nStudentul %s are codul %d si varsta %d",prim->inf.nume,prim->inf.cod,prim->inf.varsta);
		prim=prim->nextqueue;
	}
	if (prim==NULL) ultim=NULL;
}

//dezalocare coada
void dezalocare_coada(nod_coada *p, nod_coada *u)
{
	nod_coada *aux = p, *q;
	while(aux)
	{
		q=aux->nextqueue;
		delete aux;
		aux=q;
	}
	if (p==NULL) u=NULL;
}

void main()
{
	nod_coada *p = NULL;
	nod_coada *u = NULL;

	student stud;
	char buffer[20];
	int nrelem=0;
	printf("cod(!=0) = "); 
	scanf("%d", &stud.cod);
	while (stud.cod != 0) 
	{
		printf("nume = ");
		scanf("%s",buffer);
		stud.nume=new char[strlen(buffer)+1];
		strcpy(stud.nume,buffer);
		printf("varsta = ");
		scanf("%d", &stud.varsta);
		nrelem++;
		push(&p,&u,stud);
		printf("cod(!=0) = "); 
	    scanf("%d", &stud.cod);
	}

	//afisare coada
	printf("Coada este:\n");
	afisare_coada(p,u);

    student *vector = new student[nrelem];
	conversie(p,u,vector,&nrelem);
	//afisare vector
	printf("\n\nVectorul este:");
	for (int i=0;i<nrelem;i++) printf("\nStudentul %s are codul %d si varsta %d",vector[i].nume,vector[i].cod,vector[i].varsta);

	//dezalocare coada
	//dezalocare_coada(p,u);
	printf("\n\nCoada a fost dezalocata!");

	//dezalocare vector
	for (int i=0;i<nrelem;i++) delete [] vector[i].nume;
	delete [] vector;
	printf("\n\nVectorul a fost dezalocat!");

	getch();
}
