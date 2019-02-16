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

void afisInOrdine_SRD(bynarytreenode* root) 
{
	if (root) 
	{
		afisInOrdine_SRD(root->left);
		printf("\n ISBN = %d, price = %5.2f, BF = %d", root->inf->ISBN, root->inf->price, root->BF);
		afisInOrdine_SRD(root->right);
	}
}

bynarytreenode* insertNode(bynarytreenode* root, book* info, int *H)
{
	bynarytreenode *Node1;
	bynarytreenode *Node2;
	if(!root)
	{
		root = (bynarytreenode*) malloc(sizeof(bynarytreenode));
		root->inf = info;
		root->left = NULL;
		root->right = NULL;
		root->BF = 0;
		*H = 1;
		return root;
	}
	if(info->ISBN < root->inf->ISBN)
	{
		root->left = insertNode(root->left, info, H);
		if(*H)
		// ramura stanga este mai mare
		{
			switch(root->BF)
			{
			case -1: // arbore inclinat spre dreapta
				root->BF = 0;
				*H = 0;
				break;
			case 0: // arbore echilibrat
				root->BF = 1;
				break;
			case 1: // arbore inclinat spre stanga
				Node1 = root->left;
				if(Node1->BF == 1)
				{
					printf("\n Rotatie dreapta\n");
					printf("\n Subarbore stang\n");
					afisInOrdine_SRD(root->left);
					printf("\n Subarbore drept\n");
					afisInOrdine_SRD(root->right);

					root->left= Node1->right;
					Node1->right = root;
					root->BF = 0;
					root = Node1;
				}
				else
				{
					printf("\n Rotatie stanga-dreapta\n");
					printf("\n Subarbore stang\n");
					afisInOrdine_SRD(root->left);
					printf("\n Subarbore drept\n");
					afisInOrdine_SRD(root->right);

					Node2 = Node1->right;
					Node1->right = Node2->left;
					Node2->left = Node1;
					root->left = Node2->right;
					Node2->right = root;
					if(Node2->BF == 1) root->BF = -1;
					else root->BF = 0;
					if (Node2->BF == -1) Node1->BF = 1;
					else Node1->BF = 0;
					root = Node2;
				}
				root->BF = 0;
				*H = 0;
			}
		}
	}

	if(info->ISBN > root->inf->ISBN)
	{
		root->right = insertNode(root->right, info, H);
		if(*H)
		// ramura dreapta este mai mare
		{
			switch(root->BF)
			{
			case 1: // arbore inclinat spre stanga
				root->BF = 0;
				*H = 0;
				break;
			case 0: // arbore echilibrat
				root->BF = -1;
				break;

			case -1: // arbore inclinat spre dreapta
				Node1 = root->right;
				if(Node1->BF == -1)
				{
					printf("\n Rotatie stanga\n");
					printf("\n Subarbore stang\n");
					afisInOrdine_SRD(root->left);
					printf("\n Subarbore drept\n");
					afisInOrdine_SRD(root->right);

					root->right= Node1->left;
					Node1->left = root;
					root->BF = 0;
					root = Node1;
				}
				else
				{
					printf("\n Rotatie dreapta-stanga\n");
					printf("\n Subarbore stang\n");
					afisInOrdine_SRD(root->left);
					printf("\n Subarbore drept\n");
					afisInOrdine_SRD(root->right);

					Node2 = Node1->left;
					Node1->left = Node2->right;
					Node2->right = Node1;
					root->right = Node2->left;
					Node2->left = root;

					if(Node2->BF == -1) root->BF = 1;
					else root->BF = 0;
					if(Node2->BF == 1) Node1->BF = -1;
					else Node1->BF = 0;
					root = Node2;
				}
				root->BF = 0;
				*H = 0;
			}
		}
	}
	return(root);
}

void main()
{
	bynarytreenode* radacina = NULL;
	book* carte = NULL;
	int H;

	carte = (book*)malloc(1 * sizeof(book));
	printf("\nISBN(!=0) = "); 
	scanf("%d", &carte->ISBN);
	while (carte->ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte->price);
		radacina = insertNode(radacina, carte, &H);
		carte = (book*)malloc(1 * sizeof(book));
		printf("\nISBN(!=0) = "); 
		scanf("%d", &carte->ISBN);
	}
	afisInOrdine_SRD(radacina);
	
	getch();
}
