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
		} //end while
	}
}//end fcn insNod

void afisInOrdine_SRD(bynarytreenode* root) {
	if (root) 
	{
		afisInOrdine_SRD(root->left);
		printf("\n ISBN = %d, price = %5.2f", root->inf->ISBN, root->inf->price);
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
		printf("price = "); scanf("%f", &carte->price);
		radacina = insertNode(radacina, carte);
		carte = (book*)malloc(1 * sizeof(book));
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte->ISBN);
	}
	afisInOrdine_SRD(radacina);
	_getch();
}