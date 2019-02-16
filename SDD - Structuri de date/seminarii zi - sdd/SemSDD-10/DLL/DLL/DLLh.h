#define _EXPORTING
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

extern "C" _declspec(dllexport) BinaryTreeNode* createNode(information inf, BinaryTreeNode* l, BinaryTreeNode* r);
extern "C" _declspec(dllexport) BinaryTreeNode* insertNode(BinaryTreeNode* root, information info);
extern "C" _declspec(dllexport) void writeRLeftRight(BinaryTreeNode* root);
extern "C" _declspec(dllexport) void writeLeftRRight(BinaryTreeNode* root);
extern "C" _declspec(dllexport) void writeLeftRightR(BinaryTreeNode* root);