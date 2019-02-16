#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
	int cod;
	char* nume;
	int varsta;
};

struct bynarytreenode 
{
	student *info; // informatia utila este pointer
	bynarytreenode *left, *right;
};

bynarytreenode* createnode(student *stud, bynarytreenode *l, bynarytreenode *r) 
{
	bynarytreenode *temp;
	temp=(bynarytreenode*)malloc(sizeof(bynarytreenode));
	temp->info=new student; // se aloca memorie si pentru informatia utila
	temp->info->cod=stud->cod;
	temp->info->nume=(char*)malloc((strlen(stud->nume)+1)*sizeof(char));
	strcpy(temp->info->nume,stud->nume);
	temp->info->varsta=stud->varsta;
	temp->left=l;
	temp->right=r;
	return temp;
}

bynarytreenode* insertnode(student *stud, bynarytreenode *root) 
{
	bynarytreenode *aux; 
	aux = root;

	if(!root) 
	{ 
		aux=createnode(stud,NULL,NULL);
		return aux;
	} 
	else {
		//structura repetitiva la infinit, iese prin return
		while(1)
		{
			if(stud->cod > aux->info->cod) 
			{ 
				if(aux->right) aux=aux->right;
				else 
				{ 
					aux->right=createnode(stud,NULL,NULL);
					return root;
				}				
			} 
			else 
			{ 
				if(stud->cod < aux->info->cod) 
				{
					if (aux->left) aux=aux->left;
					else 
					{ 
						aux->left=createnode(stud,NULL,NULL);
						return root;
					}					
				} 
				else 
				{
					printf("\n Nod existent");
					return root;
				}
			}
		}
	}
}

//functie pentru numararea elementelor din arbore
void numara(bynarytreenode* root, int *nr) 
{
	if (root != NULL) 
	{
		numara(root->left,nr);
		(*nr)++;
		numara(root->right,nr);
	}
}

//preordine
void printRLeftRight(bynarytreenode* root) 
{
	if (root != NULL) 
	{
		printf("\n Studentul %s are codul %d si varsta %d", root->info->nume, root->info->cod, root->info->varsta);
		printRLeftRight(root->left);
		printRLeftRight(root->right);
	}
}

//inordine
void printLeftRRight(bynarytreenode* root) 
{
	if (root != NULL) 
	{
		printLeftRRight(root->left);
		printf("\n Studentul %s are codul %d si varsta %d", root->info->nume, root->info->cod, root->info->varsta);
		printLeftRRight(root->right);
	}
}

//postordine
void printLeftRightR(bynarytreenode* root) 
{
	if (root != NULL) 
	{
		printLeftRightR(root->left);		
		printLeftRightR(root->right);
		printf("\n Studentul %s are codul %d si varsta %d", root->info->nume, root->info->cod, root->info->varsta);
	}
}

void main() 
{
	bynarytreenode* r = NULL;
	student* elem;

	elem = new student; // se aloca memorie
	elem->cod = 90;
	elem->nume = (char*) malloc((strlen("Ion")+1)*sizeof(char));
	strcpy(elem->nume, "Ion");
	elem->varsta = 24;
	r = insertnode(elem, r);
	free(elem->nume);
	free(elem); // se dezaloca

	elem = new student; // se aloca memorie
	elem->cod = 60;
	elem->nume = (char*) malloc((strlen("Gigel")+1)*sizeof(char));
	strcpy(elem->nume, "Gigel");
	elem->varsta = 24;
	r = insertnode(elem, r);
	free(elem->nume);
	free(elem); // se dezaloca

	elem = new student; // se aloca memorie
	elem->cod = 80;
	elem->nume = (char*) malloc((strlen("Maricica")+1)*sizeof(char));
	strcpy(elem->nume, "Maricica");
	elem->varsta = 24;
	r = insertnode(elem, r);
	free(elem->nume);
	free(elem); // se dezaloca
	
	printLeftRRight(r);
    
	int nr=0;
	numara(r,&nr);
	printf("\nArborele are %d noduri",nr);

	_getch();
}