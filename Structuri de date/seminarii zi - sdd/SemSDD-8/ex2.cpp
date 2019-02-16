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

void rotatie_dreapta(bynarytreenode *&root)
{
	printf("\n Rotatie dreapta\n");
	bynarytreenode *Node1 = root->left;				
	root->left= Node1->right;
	Node1->right = root;
	root = Node1;
}

void rotatie_stanga_dreapta(bynarytreenode *&root)
{
	printf("\n Rotatie stanga-dreapta\n");
	bynarytreenode *Node1 = root->left;				
	bynarytreenode *Node2 = Node1->right;
	Node1->right = Node2->left;
	Node2->left = Node1;
	root->left = Node2->right;
	Node2->right = root;
	root = Node2;
}

void rotatie_stanga(bynarytreenode *&root)
{
	printf("\n Rotatie stanga\n");
	bynarytreenode *Node1 = root->right;				
	root->right= Node1->left;
	Node1->left = root;				
	root = Node1;
}

void rotatie_dreapta_stanga(bynarytreenode *&root)
{
	printf("\n Rotatie dreapta-stanga\n");
	bynarytreenode *Node1 = root->right;				
	bynarytreenode *Node2 = Node1->left;
	Node1->left = Node2->right;
	Node2->right = Node1;
	root->right = Node2->left;
	Node2->left = root;
	root = Node2;
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
		calcul_BF(radacina);
		if ((radacina->BF==2)&&(radacina->right->BF==1)) { rotatie_stanga(radacina); calcul_BF(radacina); }
		else if ((radacina->BF==2)&&(radacina->right->BF==-1)) { rotatie_dreapta_stanga(radacina); calcul_BF(radacina); }
		else if ((radacina->BF==-2)&&(radacina->left->BF==-1)) { rotatie_dreapta(radacina); calcul_BF(radacina); }
		else if ((radacina->BF==-2)&&(radacina->left->BF==1)) { rotatie_stanga_dreapta(radacina); calcul_BF(radacina); }

		carte = (book*)malloc(1 * sizeof(book));
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte->ISBN);
	}
	
	afisInOrdine_SRD(radacina);
	printf("\nSubarborele stang:");
	afisInOrdine_SRD(radacina->left);
	printf("\nSubarborele drept:");
	afisInOrdine_SRD(radacina->right);

	getch();
}
