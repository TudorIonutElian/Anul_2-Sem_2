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
	book *inf;
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

void afisInOrdine_SRD(bynarytreenode* root) {
	if (root) {
		afisInOrdine_SRD(root->left);
		printf("\n ISBN = %d, price = %5.2f", root->inf->ISBN, root->inf->price);
		afisInOrdine_SRD(root->right);
	}
}

//conversie arbore binar - vector
void bynarytree_to_array(bynarytreenode *root, book *v, int *k)
{
	if (root)
	{
		v[*k].ISBN=root->inf->ISBN;
		v[*k].price=root->inf->price;
		(*k)++;
		bynarytree_to_array(root->left, v, k);
		bynarytree_to_array(root->right, v, k);
	}
}

void main()
{
	bynarytreenode* radacina = NULL;
	book* carte = NULL;
	carte = (book*)malloc(1 * sizeof(book));
	int nrnoduri = 0;
	printf("ISBN(!=0) = "); 
	scanf("%d", &carte->ISBN);
	while (carte->ISBN != 0) 
	{
		printf("price = "); 
		scanf("%f", &carte->price);
		nrnoduri++;
		radacina = insertNode(radacina, carte);
		carte = (book*)malloc(1 * sizeof(book));
		printf("ISBN(!=0) = "); 
		scanf("%d", &carte->ISBN);
	}
	afisInOrdine_SRD(radacina);
	
	printf("\nAfisare vector:");
	book *vector=(book*)malloc(nrnoduri*sizeof(book));
	nrnoduri = 0;
    bynarytree_to_array(radacina, vector, &nrnoduri);
	for (int i=0; i<nrnoduri; i++) printf("\n ISBN = %d, price = %5.2f", vector[i].ISBN, vector[i].price);
	
	_getch();
}