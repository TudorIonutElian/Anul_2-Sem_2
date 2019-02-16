#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

struct information 
{
	int key;//could be for more generalized pattern use instead int - char* or even void*
	int position;
};

struct BinaryTreeNode 
{
	information info;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

extern "C" _declspec(dllimport) BinaryTreeNode* insertNode(BinaryTreeNode* root, information info);

extern "C" void _declspec(dllimport) writeLeftRRight(BinaryTreeNode* root);
