//stack and queue on simple and double list, array
#include<iostream>

struct Plate{
	int diameter;
	float capacity;
};
//simple list
struct node{
	Plate info;
	node* next;
};

//double linked list stack

struct Dnode{
	Dnode* next;
	Dnode* prev;
	Plate info;
};

struct Dummy{
	Dnode* head;
	Dnode* tail;
};

//insert function, our list is in a dummy

Dummy insertStackDList(Dummy list,Plate plate){
	//we insert at the end, we create a new node
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));
	newNode->info = plate;
	newNode->next = NULL;
	newNode->prev = list.tail;
	if (list.tail)
	{
		list.tail->next = newNode;
	}
	else
	{
		list.head = newNode;
	}
		list.tail = newNode;
		return list;
}

//extract method
Plate extractStackDList(Dummy* list){
	if (list->tail)
	{
		Plate result = list->tail->info;
		list->tail = list->tail->prev;
		if (list->tail){
			free(list->tail->next);
			list->tail->next = NULL;
		}
		else{
			free(list->head);
			list->head = NULL;
		}

		return result; 
	}
	else{
		throw "Our stack is empty";
	}
}

//insert method
node* insertStackList(node* start, Plate plate){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->info = plate; //shallow copy but it's ok because we don't have char*
	newNode->next = start;
	return newNode;	
}

//extract method
//another* before start because the start will change
Plate extractStackList(node** start)
{
	if (*start){
		Plate plate = (*start)->info;
		//we make a temporary node
		node* temp = *start;
		(*start) = (*start)->next;
		free(temp);

		return plate;
	}
	else
	{
		throw "Our stack is empty.";
	}
}

Plate createPlate(int diameter, float capacity)
{
	Plate plate;
	plate.diameter = diameter;
	plate.capacity = capacity;
	return plate;
}
void printPlate(Plate plate)
{
	printf("%d - %5.2f\n", plate.diameter, plate.capacity); 
}
void printStackList(node** start)
{
	while (*start){
		Plate plate = extractStackList(start);
		printPlate(plate);
	}
}

//queue

Plate* insertQueueArray(Plate* plates, int* length, Plate plate)
{
	Plate* temp = (Plate*)malloc(sizeof(Plate)*(++(*length)));
	for (int i = 0; i < (*length) - 1; i++)
	{
		temp[i] = plates[i];
	}
	temp[(*length) - 1] = plate; //here we have shallow copy but it is ok because we don't have * in our struct of Plates
	free(plates);
	return temp;
}

//extract function

Plate extractQueueArray(Plate** plates, int* length){
	if ((*length) > 0){
		Plate* temp = (Plate*)malloc(sizeof(Plate)*(--(*length)));
		Plate result = (*plates)[0];
		for (int i = 1; i < (*length)+1; i++)
		{
			temp[i - 1] = (*plates)[i];
		}
		free(*plates);
		*plates = temp;
		return result;
	}
}

void printQueueArray(Plate** plates, int *length)
{
	while ((*length) > 0)
	{
		Plate plate = extractQueueArray(plates, length);
		printPlate(plate);
	}
}

void printStackDList(Dummy* list)
{
	while (list->head)
	{
		Plate plate = extractStackDList(list);
		printPlate(plate);
	}
}
void main()
{
	//we create a stack
	/*node* stack = NULL;
	stack = insertStackList(stack, createPlate(10, 200));
	stack = insertStackList(stack, createPlate(11, 300));
	stack = insertStackList(stack, createPlate(12, 400));

	printStackList(&stack);
	printStackList(&stack);*/

	/*Plate* queue = NULL;
	int length = 0;
	queue = insertQueueArray(queue, &length, createPlate(10, 500));
	queue = insertQueueArray(queue, &length, createPlate(11, 600));
	queue = insertQueueArray(queue, &length, createPlate(12, 700));
	queue = insertQueueArray(queue, &length, createPlate(13, 800));

	printQueueArray(&queue, &length);*/

	Dummy stack;
	stack.head = stack.tail = NULL;

	stack = insertStackDList(stack, createPlate(10, 10));
	stack = insertStackDList(stack, createPlate(20, 20));
	stack = insertStackDList(stack, createPlate(30, 40));

	printStackDList(&stack);
}