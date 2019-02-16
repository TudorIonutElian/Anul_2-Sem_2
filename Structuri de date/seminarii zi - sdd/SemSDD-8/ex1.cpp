#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct book
{
	int ISBN;
	float price;
};

struct bynarytreenode
{
	book* inf;
	int BF;
	bynarytreenode *left, *right;
};

//determinarea numarului de nivele ale unui arbore binar
int nr_nivele(bynarytreenode* root)
{
	if (root) 
	{
		int i = 1 + nr_nivele(root->left);
		int j = 1 + nr_nivele(root->right);
		if (i<j) return j;
		else return i;
	}
	else return 0;
}

bynarytreenode* createNode(book* c, bynarytreenode* l, bynarytreenode* r) 
{
	bynarytreenode* temp = (bynarytreenode*)malloc(1 * sizeof(bynarytreenode));
	temp->inf = c;
	temp->left = l;
	temp->right = r;
	return temp;
}

bynarytreenode* insertNode(bynarytreenode* rad, book* pcinf) 
{
	bynarytreenode* aux = NULL;
	if (!rad) 
    {
		return createNode(pcinf, NULL, NULL);
	} 
	else 
	{
		aux = rad;
		while(1) 
		{
			if (pcinf->ISBN < rad->inf->ISBN) 
			{
				if (rad->left) 
				{
					rad = rad->left;
				} 
				else 
				{
					rad->left = createNode(pcinf, NULL, NULL);
					return aux;
				}
			} 
			else 
			{
				if (pcinf->ISBN > rad->inf->ISBN) 
				{
					if (rad->right) 
					{
						rad = rad->right;
					} else 
					{
						rad->right = createNode(pcinf, NULL, NULL);
						return aux;
					}
				} else 
				{
					//nodul exista deja
					return aux;
				}
			}
		} 
	}
}

void calcul_BF(bynarytreenode* root) 
{
	if (root) 
	{
		root->BF = nr_nivele(root->right)-nr_nivele(root->left);
		calcul_BF(root->left);
		calcul_BF(root->right);
	}
}

void afisInOrdine_SRD(bynarytreenode* root) 
{
	if (root) 
	{
		afisInOrdine_SRD(root->left);
		printf("\n ISBN = %d, price = %5.2f, BF = %d", root->inf->ISBN, root->inf->price, root->BF);
		afisInOrdine_SRD(root->right);
	}
}

void main()
{
	bynarytreenode* radacina = NULL;
	book* carte = NULL;

	carte = (book*)malloc(1 * sizeof(book));
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte->ISBN);
	while (carte->ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte->price);
		radacina = insertNode(radacina, carte);
		carte = (book*)malloc(1 * sizeof(book));
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte->ISBN);
	}
	calcul_BF(radacina);
	afisInOrdine_SRD(radacina);
	getch();
}
