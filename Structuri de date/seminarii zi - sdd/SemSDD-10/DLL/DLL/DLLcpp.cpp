#include "DLLh.h"

_declspec(dllexport) BinaryTreeNode* createNode(information inf, BinaryTreeNode* l, BinaryTreeNode* r) 
{
	BinaryTreeNode* temp;
	temp = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
	temp->left = l; 
	temp->right = r;
	temp->info.key = inf.key;
	temp->info.position = inf.position;
	return temp;
}

_declspec(dllexport) BinaryTreeNode* insertNode(BinaryTreeNode* root, information info) 
{
	BinaryTreeNode* aux; 
	aux = root;
	if(!root) { 
		aux=createNode(info,NULL,NULL);
		return aux;
	} else {
		//structura repetitiva la infinit, iese prin return
		while(1){
			if(info.key > aux->info.key) { 
				if(aux->right) aux=aux->right;
				else { 
					aux->right=createNode(info,NULL,NULL);
					return root;
				}				
			} else { 
				if(info.key < aux->info.key) {
					if (aux->left) aux=aux->left;
					else { 
						aux->left=createNode(info,NULL,NULL);
						return root;
					}					
				} else {
					printf("\n Nod existent");
					return root;
				}
			}
		}
	}
}

void _declspec(dllexport) writeRLeftRight(BinaryTreeNode* root) {
	if (root) {
		printf("\nThe key %d has the position %d", root->info.key, root->info.position);
		writeRLeftRight(root->left);
		writeRLeftRight(root->right);
	}
}

void _declspec(dllexport) writeLeftRRight(BinaryTreeNode* root) {
	if (root) {
		writeLeftRRight(root->left);
		printf("\nThe key %d has the position %d", root->info.key, root->info.position);
		writeLeftRRight(root->right);
	}
}

void _declspec(dllexport) writeLeftRightR(BinaryTreeNode* root) {
	if (root) {
		writeLeftRightR(root->left);
		writeLeftRightR(root->right);
		printf("\nThe key %d has the position %d", root->info.key, root->info.position);
	}
}
