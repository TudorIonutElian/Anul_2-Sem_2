#include <conio.h>
#include <iostream>
using namespace std;

class Heap
{
public:
	// Construire heap nou (cu dimensiunea specificata)
	Heap(int capacitateInitiala = DimensiuneMinima);

	// Construire heap pe baza unor elemente date
	Heap(int elemente[], int numarElemente);

	// Constructor de copiere
	Heap(Heap& heap);
	
	~Heap() { delete [] this->elemente; }
	
	// --- Metode coada prioritate  --- //

	// Insereaza un element în structura
	void Insereaza(int element);

	// Intoarce elementul maxim si il elimina din structura
	int ExtrageMaxim();

	// Intoarce elementul maxim dar nu il elimina din structura
	int CitesteMaxim();

	void SorteazaHeap(int* destinatie);

	// --- Acces la elemente --- //
	int GetNumarElemente() { return this->dimensiuneHeap; }
	
	int operator[] (int index) { return this->elemente[index]; }

private:
	// --- Datele structurii --- //
	int* elemente;	  // pointer la vectorul de elemente

	// Invariant: dimensiuneHeap <= memorieAlocata
	int memorieAlocata; // dimensiunea mem alocate (ca nr de elem)
	int dimensiuneHeap; // nr de elemente existente în heap

	static const int DimensiuneMinima = 10;

	// --- Functia de reordonare a elementelor --- //
	void Filtrare(int index);

	// --- Calculare pozitie elemente --- //
	inline int Parinte(int i) 
	{ 
		// <=> i / 2 cu indici pe 1..n
		return (i - 1) / 2; 
	}			
	inline int Stanga(int i) 
	{
		// <=> i * 2 cu indici pe 1..n
		return 2 * i + 1; 
	}
	inline int Dreapta(int i) 
	{
		// <=> i * 2 + 1 cu indici pe 1..n
		return 2 * i + 2; 
	}
	inline void Interschimb(int index1, int index2)
	{
		int temp = this->elemente[index1];
		this->elemente[index1] = this->elemente[index2];
		this->elemente[index2] = temp;
	}

	//--- Metode folosite pt realocarea dinamica a structurii --//
	void CresteMemoriaAlocata();
	void ScadeMemoriaAlocata();

	// Nu permitem operatii de atribuire intre obiecte de tip Heap
	Heap operator= (const Heap&);
};

void Heap::CresteMemoriaAlocata()
{
	// alocam un vector nou de dimensiune dubla si copiem elementele
	int* masivNou = new int[this->memorieAlocata * 2];
	for (int i = 0; i < this->memorieAlocata; i++)
	{
		masivNou[i] = this->elemente[i];
	}

	// inlocuim vectorul existent cu cel nou si actualizam dimensiunea
	delete []  this->elemente;	
	this->elemente = masivNou;

	this->memorieAlocata = this->memorieAlocata * 2;
}

void Heap::ScadeMemoriaAlocata()
{
	// alocam un vector nou mai mic si copiem elementele
	int* masivNou = new int[this->memorieAlocata / 2];
	for (int i = 0; i < this->memorieAlocata / 2; i++)
	{
		masivNou[i] = this->elemente[i];
	}

	// inlocuim vectorul existent cu cel nou si actualizam dimensiunea
	delete [] this->elemente;	
	this->elemente = masivNou;

	this->memorieAlocata = this->memorieAlocata / 2;
}

void Heap::Filtrare(int index)
{
	// 1. Determinam maximul dintre elemente[index], 
	// elemente[Stanga(index)] si elemente[Dreapta(index)]
	int indexMax = index;
	int indexStanga = this->Stanga(index);
	int indexDreapta = this->Dreapta(index);

	if (indexStanga < this->dimensiuneHeap && this->elemente[indexStanga] > this->elemente[indexMax])
	{
		indexMax = indexStanga;
	}

	if (indexDreapta < this->dimensiuneHeap && this->elemente[indexDreapta] > this->elemente[indexMax])
	{
		indexMax = indexDreapta;
	}

	// 2. Daca varful actual nu respecta proprietatea de ordonare atunci 
	// coboram nodul in arbore si reapelam recursiv procedura
	if (index != indexMax)
	{
		this->Interschimb(index, indexMax);
		this->Filtrare(indexMax);
	}
}

Heap::Heap(int capacitateInitiala)
{
	// ne asiguram ca dimensiunea initiala a structurii este
	// cel putin dimensiunea minima
	capacitateInitiala = max(capacitateInitiala, DimensiuneMinima);

	// alocam memoria pentru elemente si initializam campurile
	this->elemente = new int[capacitateInitiala];
	this->memorieAlocata = capacitateInitiala;
	this->dimensiuneHeap = 0;	
}

Heap::Heap(int elemente[], int numarElemente)
{
	// initializam campurile
	this->memorieAlocata = max(numarElemente, DimensiuneMinima);	
	this->dimensiuneHeap = numarElemente;

	// copiem elementele din vector in structura
	this->elemente = new int[this->memorieAlocata];			
	for (int i = 0; i < numarElemente; i++)
	{
		this->elemente[i] = elemente[i];
	}

	// Rearanjam elem a.i. sa satisfaca prop de ordonare folosind
	// metoda Filtrare pt coborarea elem in arbore (elementele din 
	// a doua jumatate a masivului respecta implicit proprietatea
	// de heap deoarece reprezinta subarbori cu maxim un element)
	for (int i = (numarElemente - 1) / 2; i >= 0; i--)
	{
		this->Filtrare(i);
	}
}

Heap::Heap(Heap& heap)
{
	this->memorieAlocata = heap.memorieAlocata;
	this->dimensiuneHeap = heap.dimensiuneHeap;

	this->elemente = new int[this->memorieAlocata];
	for (int i = 0; i < this->dimensiuneHeap; i++)
	{
		this->elemente[i] = heap.elemente[i];
	}
}

void Heap::Insereaza(int element)
{
	// verificam faptul ca avem memorie disponibila
	if (this->dimensiuneHeap == this->memorieAlocata)
	{
		this->CresteMemoriaAlocata();
	}

	// expandam heap-ul
	this->dimensiuneHeap++;

	// adaugam elementul nou la sfarsitul heap-ului
	int index = this->dimensiuneHeap - 1;
	this->elemente[index] = element;

	// si il urcam in arbore atat cat este cazul 
	// pentru a pastra proprietatea de heap
	while (this->Parinte(index) >= 0 && 
		this->elemente[index] > this->elemente[Parinte(index)])
	{
		this->Interschimb(index, this->Parinte(index));
		index = this->Parinte(index);
	}
}

int Heap::ExtrageMaxim()
{
	// scadem memoria alocata daca este cazul
	if (this->memorieAlocata > DimensiuneMinima * 2 && 
		this->dimensiuneHeap < this->memorieAlocata / 3)
	{
		this->ScadeMemoriaAlocata();
	}

	//mutam elementul in afara heap-ului si refacem struct de heap
	this->dimensiuneHeap--;
	Interschimb(0, this->dimensiuneHeap);
	
	this->Filtrare(0);

	return this->elemente[this->dimensiuneHeap];
}

int Heap::CitesteMaxim()
{
	// ne asiguram ca avem cel putin un element in heap
	if(this->dimensiuneHeap > 0)
	// si intoarcem maximul
	return this->elemente[0];
}

void Heap::SorteazaHeap(int* destinatie)
{
	// salvam numarul de elemente din heap
	int dimensiuneaInitiala = this->dimensiuneHeap;

	// sortam vectorul in cadrul structurii
	for (int i = this->dimensiuneHeap - 1; i > 0; i--)
	{
		this->Interschimb(0, i);

		this->dimensiuneHeap--;
		this->Filtrare(0);
	}

	// copiem elementele sortate in vectorul destinatie
	for (int i = 0; i < dimensiuneaInitiala; i++)
	{
		destinatie[i] = this->elemente[i];
	}
}

void main()
{
	// 1. Construirea vectorului de sortat si a heap-ului asociat
	const int NumarElemente = 8;
	int elemente[] = {23, 32, 2, 6, 23, 8, 3, 6};
	Heap heap(elemente, NumarElemente);

	// 2. Obtinerea si afisarea vectorului sortat
	int* elementeSortate = new int[NumarElemente];		
	heap.SorteazaHeap(elementeSortate);

	for (int i = 0; i < NumarElemente; i++)
	{
		cout << elementeSortate[i] << " ";
	}
	cout << endl;

	getch();
}