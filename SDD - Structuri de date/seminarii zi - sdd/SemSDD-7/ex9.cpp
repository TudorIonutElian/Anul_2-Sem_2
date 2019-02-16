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
	bynarytreenode* left;
	book* inf;
	bynarytreenode* right;
};

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
	if (!rad) {
		return createNode(pcinf, NULL, NULL);
	} else {
		aux = rad;
		while(1) {
			if (pcinf->ISBN < rad->inf->ISBN) {
				if (rad->left) {
					rad = rad->left;
				} else {
					rad->left = createNode(pcinf, NULL, NULL);
					return aux;
				}
			} else {
				if (pcinf->ISBN > rad->inf->ISBN) {
					if (rad->right) {
						rad = rad->right;
					} else {
						rad->right = createNode(pcinf, NULL, NULL);
						return aux;
					}
				} else {
					//nodul exista deja
					return aux;
				}
			}
		} 
	}
}

void afisInOrdine_SRD(bynarytreenode* root) 
{
	if (root) 
	{
		afisInOrdine_SRD(root->left);
		printf("\n ISBN = %d, price = %5.2f", root->inf->ISBN, root->inf->price);
		afisInOrdine_SRD(root->right);
	}
}

//cautare recursiva a nodului cu un anumit ISBN
bynarytreenode* cauta_recursiv(bynarytreenode* root, int cheie)
{
	if (root)
	{
		if (cheie==root->inf->ISBN) return root;
		else if (cheie<root->inf->ISBN) cauta_recursiv(root->left,cheie);
		else cauta_recursiv(root->right,cheie);
	}
	else return NULL;
}

//cautare iterativa a nodului cu un anumit ISBN
bynarytreenode* cauta_iterativ(bynarytreenode* root, int cheie) 
{
	bynarytreenode* aux = NULL;
	if (!root) return aux;
	while (1) {
		if(cheie < root->inf->ISBN) 
		{
			if (root->left) root = root->left;
			else return aux;
		} 
		else 
		{
			if (cheie > root->inf->ISBN) 
			{
				if (root->right) root = root->right;
				else return aux;
			} 
			else 
			{
				aux = root;
				return aux;
			}
		}
	}
}

void main()
{
	bynarytreenode* radacina = NULL;
	book* carte = NULL;
    int isbn;
	carte = (book*)malloc(1 * sizeof(book));
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte->ISBN);
	while (carte->ISBN != 0) 
	{
		printf("price = "); scanf("%f", &carte->price);
		radacina = insertNode(radacina, carte);
		carte = (book*)malloc(1 * sizeof(book));
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte->ISBN);
	}
	afisInOrdine_SRD(radacina);

	printf("\n ISBN de cautat = ");
	scanf("%d",&isbn);
	bynarytreenode* cautat = NULL;
	cautat=cauta_recursiv(radacina,isbn);
	//cautat=cauta_iterativ(radacina,isbn);
	if (cautat) printf("\n ISBN = %d, price = %5.2f", cautat->inf->ISBN, cautat->inf->price);
	else printf("\n ISBN negasit!");

	_getch();
}