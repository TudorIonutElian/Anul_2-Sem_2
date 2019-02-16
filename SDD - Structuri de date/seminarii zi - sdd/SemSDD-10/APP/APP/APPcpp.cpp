#include "APPh.h"

void main()
{
	BinaryTreeNode *radacina = NULL;
	information elem;

	printf("key(!=0) = "); 
	scanf("%d", &elem.key);
	while (elem.key != 0) 
	{
		printf("position = "); 
		scanf("%d", &elem.position);
		radacina = insertNode(radacina, elem);
		printf("key(!=0) = "); 
	    scanf("%d", &elem.key);
	}
	writeLeftRRight(radacina);
	getch();
}