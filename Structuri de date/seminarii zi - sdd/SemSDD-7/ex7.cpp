#include <stdio.h>
#include <conio.h>

struct book
{
	int ISBN;
	float price;
};

typedef struct nod_stiva
{
	book inf;
	struct nod_stiva *nextstack;
};

typedef struct nod_arbore
{
	book inf;
	struct nod_arbore *left;
	struct nod_arbore *right;
};

//adauga un nod in stiva
void push(book val, nod_stiva **stiva)
{
	if (stiva == NULL)
	{
		(*stiva) = new nod_stiva;
		(*stiva)->inf = val;
		(*stiva)->nextstack = NULL;
	}
	else
	{
		nod_stiva *nou = new nod_stiva;
		nou->inf = val;
		nou->nextstack = (*stiva);
		(*stiva) = nou;
	}
}

//scoate un nod din stiva
int pop(book &val, nod_stiva *&stiva)
{
	if (!stiva) return -1;
	val = stiva->inf;
	nod_stiva *aux = stiva;
	stiva = stiva->nextstack;
	delete aux;//free(aux);
	return 0;
}

//conversie stiva -> arbore
void conversie(nod_stiva* &stiva, nod_arbore* &arb)
{
	if (!stiva) return;
	book val;
	while (pop(val, stiva) == 0)
	{
		//adauga un nod in arbore
		if (arb == NULL)
			{
				arb = new nod_arbore;
				arb->inf = val;
				arb->left = arb->right = NULL;
			}
			else
			{
				nod_arbore *aux = arb, 
				*parent = arb;
				while (aux)
				{
					parent = aux;
					if (val.ISBN <= aux->inf.ISBN)
						aux = aux->left;
					else
						aux = aux->right;
				}

				if (val.ISBN <= parent->inf.ISBN)
				{
					parent->left = new nod_arbore;
					parent->left->inf = val;
					parent->left->right = NULL;
					parent->left->left = NULL;
				}
				else
				{
					parent->right = new nod_arbore;
					parent->right->inf = val;
					parent->right->right = NULL;
					parent->right->left = NULL;
				}
			}
	}
}

//afiseaza stiva
void afisare_stiva(nod_stiva *stiva)
{
	nod_stiva *aux = stiva;
	while (aux)
	{
		printf("\nISBN=%d, price=%5.2f ", aux->inf.ISBN, aux->inf.price);
		aux = aux->nextstack;
	}
	printf("\n");
}

//afiseaza arbore
void SRD(nod_arbore* root) 
{
	if (root) 
	{
		SRD(root->left);
		printf("\nISBN=%d, price=%5.2f", root->inf.ISBN, root->inf.price);
		SRD(root->right);
	}
}

void main()
{
	nod_stiva *stiva = NULL;
	nod_arbore *radacina = NULL;

	book carte;
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte.ISBN);
	while (carte.ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte.price);
		push(carte,&stiva);
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte.ISBN);
	}

	printf("Stiva este:\n");
	afisare_stiva(stiva);

    conversie(stiva, radacina);

	printf("\nArborele binar este:");
    SRD(radacina); 

	_getch();
}
