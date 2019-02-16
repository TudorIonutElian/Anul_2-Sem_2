#include <conio.h>
#include <iostream>
using namespace std;

struct HeapStruct {
	// --- Datele structurii --- //
	int* elemente;	  // pointer la vectorul de elemente

	// Invariant: dimensiuneHeap <= memorieAlocata
	int memorieAlocata; // dimensiunea mem alocate (ca nr de elem)
	int dimensiuneHeap; // nr de elemente existente în heap
};

void Interschimb(HeapStruct heap, int index1, int index2)
{
	int temp = heap.elemente[index1];
	heap.elemente[index1] = heap.elemente[index2];
	heap.elemente[index2] = temp;
}

void Filtrare(HeapStruct heap, int index)
{
	// 1. Determinam maximul dintre elemente[index], 
	// elemente[Stanga(index)] si elemente[Dreapta(index)]
	int indexMax = index;
	int indexStanga = 2 * index + 1;
	int indexDreapta = 2 * index + 2;

	if (indexStanga < heap.dimensiuneHeap && heap.elemente[indexStanga] > heap.elemente[indexMax])
	{
		indexMax = indexStanga;
	}

	if (indexDreapta < heap.dimensiuneHeap && heap.elemente[indexDreapta] > heap.elemente[indexMax])
	{
		indexMax = indexDreapta;
	}

	// 2. Daca varful actual nu respecta proprietatea de ordonare atunci 
	// coboram nodul in arbore si reapelam recursiv procedura
	if (index != indexMax)
	{
		Interschimb(heap, index, indexMax);
		Filtrare(heap, indexMax);
	}
}

void Aloca(HeapStruct* heap, int elemente[], int numarElemente)
{
	// initializam campurile
	heap->memorieAlocata = numarElemente;	
	heap->dimensiuneHeap = numarElemente;

	// copiem elementele din vector in structura
	heap->elemente = new int[heap->memorieAlocata];			
	for (int i = 0; i < numarElemente; i++)
	{
		heap->elemente[i] = elemente[i];
	}

	// Rearanjam elem a.i. sa satisfaca prop de ordonare folosind
	// metoda Filtrare pt coborarea elem in arbore (elementele din 
	// a doua jumatate a masivului respecta implicit proprietatea
	// de heap deoarece reprezinta subarbori cu maxim un element)
	for (int i = (numarElemente - 1) / 2; i >= 0; i--)
	{
		Filtrare(*heap, i);
	}
}

void CresteMemoriaAlocata(HeapStruct *heap)
{
	// alocam un vector nou de dimensiune dubla si copiem elementele
	int* masivNou = new int[heap->memorieAlocata * 2];
	for (int i = 0; i < heap->memorieAlocata; i++)
	{
		masivNou[i] = heap->elemente[i];
	}

	// inlocuim vectorul existent cu cel nou si actualizam dimensiunea
	delete []  heap->elemente;	
	heap->elemente = masivNou;

	heap->memorieAlocata = heap->memorieAlocata * 2;
}

void ScadeMemoriaAlocata(HeapStruct *heap)
{
	// alocam un vector nou mai mic si copiem elementele
	int* masivNou = new int[heap->memorieAlocata / 2];
	for (int i = 0; i < heap->memorieAlocata / 2; i++)
	{
		masivNou[i] = heap->elemente[i];
	}

	// inlocuim vectorul existent cu cel nou si actualizam dimensiunea
	delete [] heap->elemente;	
	heap->elemente = masivNou;

	heap->memorieAlocata = heap->memorieAlocata / 2;
}

// Insereaza un element în structura
void Insereaza(HeapStruct *heap, int element)
{
	// verificam faptul ca avem memorie disponibila
	if (heap->dimensiuneHeap == heap->memorieAlocata)
	{
		CresteMemoriaAlocata(heap);
	}

	// expandam heap-ul
	heap->dimensiuneHeap++;

	// adaugam elementul nou la sfarsitul heap-ului
	int index = heap->dimensiuneHeap - 1;
	heap->elemente[index] = element;

	int indexParinte = (index - 1) / 2;

	// si il urcam in arbore atat cat este cazul 
	// pentru a pastra proprietatea de heap
	while (indexParinte >= 0 && heap->elemente[index] > heap->elemente[indexParinte])
	{
		Interschimb(*heap, index, indexParinte);
		index = indexParinte;
	}
}

int ExtrageMaxim(HeapStruct heap)
{
	//mutam elementul in afara heap-ului si refacem struct de heap
	heap.dimensiuneHeap--;
	Interschimb(heap, 0, heap.dimensiuneHeap);
	
	Filtrare(heap, 0);

	return heap.elemente[heap.dimensiuneHeap];
}

void SorteazaHeap(HeapStruct heap, int* destinatie)
{
	// salvam numarul de elemente din heap
	int dimensiuneaInitiala = heap.dimensiuneHeap;

	// sortam vectorul in cadrul structurii
	for (int i = heap.dimensiuneHeap - 1; i > 0; i--)
	{
		Interschimb(heap, 0, i);

		heap.dimensiuneHeap--;
		Filtrare(heap, 0);
	}

	// copiem elementele sortate in vectorul destinatie
	for (int i = 0; i < dimensiuneaInitiala; i++)
	{
		destinatie[i] = heap.elemente[i];
	}
}

void Dezaloca(HeapStruct heap)
{
	delete [] heap.elemente;
}

void main()
{
	// 1. Construirea vectorului de sortat si a heap-ului asociat
	const int NumarElemente = 8;
	int elemente[] = {23, 32, 2, 6, 23, 8, 3, 6};

	HeapStruct heap;

	Aloca(&heap, elemente, NumarElemente);

	//cout << "Maximul: " << ExtrageMaxim(heap) << endl;

	Insereaza(&heap, 10);

	// 2. Obtinerea si afisarea vectorului sortat
	int* elementeSortate = new int[heap.dimensiuneHeap];		
	SorteazaHeap(heap, elementeSortate);

	for (int i = 0; i < heap.dimensiuneHeap; i++)
	{
		cout << elementeSortate[i] << " ";
	}

	getch();
}