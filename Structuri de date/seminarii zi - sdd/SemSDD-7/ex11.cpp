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

struct listnode
{
	book *inf;
	listnode *next;
	listnode *prev;
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
	if (root) 
	{
		afisInOrdine_SRD(root->left);
		printf("\n ISBN = %d, price = %5.2f", root->inf->ISBN, root->inf->price);
		afisInOrdine_SRD(root->right);
	}
}

listnode* inserare(listnode* cap, book *b)
{
	listnode* nou = (listnode*)malloc(sizeof(listnode));
	listnode* temp;
	nou->inf=b;
	nou->next=NULL;
	if (cap==NULL) 
	{
		nou->prev=NULL;
		return nou;
	}
	temp=cap;
	while (temp->next) temp=temp->next;
	temp->next=nou;
	nou->prev=temp;
	return cap;
}

//conversie arbore binar - lista dubla (varianta recursiva)
void bynarytree_to_list(bynarytreenode *root, listnode** cap)
{
	if (root)
	{
		*cap=inserare(*cap, root->inf);
		bynarytree_to_list(root->left, cap);
		bynarytree_to_list(root->right, cap);
	}
}

void main()
{
	bynarytreenode* radacina = NULL;
	listnode* cap = NULL;
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
	afisInOrdine_SRD(radacina);
	
	bynarytree_to_list(radacina, &cap);
	printf("\n Afisare lista dubla:");
	listnode* p=cap;
	while (p)
	{
		printf("\n ISBN = %d, price = %5.2f", p->inf->ISBN, p->inf->price);
		p=p->next;
	}
	_getch();
}