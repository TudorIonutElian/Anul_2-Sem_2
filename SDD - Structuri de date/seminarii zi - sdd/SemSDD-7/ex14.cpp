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

// functie pentru stergerea nodului radacina 
void StergeNod(bynarytreenode* &root)
{
       // salvam un pointer la nodul de sters
       bynarytreenode* nod = root;
       // daca avem un subarbore drept
       if (nod->right != NULL)
       {
              // facem legatura
              root = nod->right;
              // daca avem si un subarbore stang
              if (nod->left != NULL)
              {
                     // cautam cel mai mic element din subarborele drept
                     bynarytreenode* temp = nod->right;
                     while (temp->left != NULL) temp = temp->left;
                     // si adaugam subarborele stang
                     temp->left = nod->left;
              }
       }
       else
              // daca avem doar un subarbore stang
              if (nod->left != NULL)
                     // facem legatura la acesta
                     root = nod->left;
              else
                     // daca nu avem nici un subarbore
                     root = NULL;
       // stergem nodul
       delete nod;
}

// sterge un nod dintr-un arbore de cautare
void ArbSterge(bynarytreenode *&root, int isbn_cautat)
{
       // Cazul 1: arbore vid
       if (root==NULL) return;
       // Cazul 2: stergere radacina
	   if (root->inf->ISBN == isbn_cautat)
       {
              // salvam un pointer la radacina
              bynarytreenode * nod = root;
              // daca avem un subarbore drept
              if (nod->right)
              {
                     // facem legatura
                     root = nod->right;
                     // daca avem si un subarbore stang
                     if (nod->left)
                     {
                           // cautam cel mai mic element din subarborele drept
                           bynarytreenode * temp = nod->right;
                           while (temp->left != NULL) temp = temp->left;
                           // si adaugam subarborele stang
                           temp->left = nod->left;
                     }
              }
              else
                     // daca avem doar un subarbore stang
                     if (nod->left != NULL)
                           // facem legatura la acesta
                           root = nod->left;
                     else
                           // daca nu avem nici un subarbore
                           root = NULL;
              // stergem vechea radacina
              delete nod;
              return;
       }
       // Cazul 3: stergere nod in arbore nevid
       bynarytreenode * nodCurent = root;
       while (true)
       {      
		   if (isbn_cautat < nodCurent->inf->ISBN)
                     if (nodCurent->left == NULL)
                           break; // nodul nu exista
                     else
						 if (nodCurent->left->inf->ISBN == isbn_cautat)
                                  // nodul de sters este descendentul stang
                                  StergeNod(nodCurent->left);
                           else
                                  // continuam cautarea in subarborele stang
								  nodCurent = nodCurent->left;
              else
                     if (nodCurent->right == NULL) 
							break; // nodul nu exista
                     else
						 if (nodCurent->right->inf->ISBN == isbn_cautat)
                                  // nodul de sters este descendentul drept
                                  StergeNod(nodCurent->right);
                           else
                                  // continuam cautarea in subarborele stang
								  nodCurent = nodCurent->right;
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

	afisInOrdine_SRD(radacina);
    
	int is;
	printf("\nISBN de sters= ");
	scanf("%d", &is);
	ArbSterge(radacina,is);

	afisInOrdine_SRD(radacina);

	_getch();
}