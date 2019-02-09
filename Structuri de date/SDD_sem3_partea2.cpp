#include <iostream>

struct Carte {
	char* titlu;
	int nrPagini;
};
//nod pt lista secundara
struct nodDublu {
	nodDublu* next;
	nodDublu* prev;
	Carte info;
};

struct HashTable {
	int dim;
	nodDublu** vector;
};

Carte citesteCarte() {
	Carte carte; //creare carte
	char buffer[20];
	printf("Titlu:");
	scanf("%s", buffer);
	carte.titlu = (char*)malloc(sizeof(char)*strlen(buffer));//(strlen(buffer) + 1));
	strcpy(carte.titlu, buffer);

	printf("Nr pagini:");
	scanf("%d", &carte.nrPagini);

	return carte;
}

Carte cautareInLista(int nrPagini, nodDublu* first) {
	if (first) {
		while (first) {
			if (first->info.nrPagini == nrPagini) {
				Carte result;
				result.titlu = (char*)malloc(sizeof(char)*(strlen(first->info.titlu) + 1));
					strcpy(result.titlu, first->info.titlu);
				result.nrPagini = first->info.nrPagini;
				return result; //shallow copy
			}
			else
			{
				first = first->next;
			}
		}
	}
}

Carte cautareCarte(int nrPagini, HashTable tabela) {
	if (tabela.vector) {
		int pozitie = hashCode(nrPagini, tabela);
		return cautareInLista(nrPagini, tabela.vector[pozitie]);
		tabela.vector[pozitie];
	}
	else {
		Carte c;
		c.titlu = NULL;
		c.nrPagini = -1;
		return c;
	}
}

nodDublu* inserareListaDubla(nodDublu* first, Carte info) 
{
	//principiul de lucru cu coada, metoda de inserare la inceput coada 
	//stiva LIFO toate prelucrarile la acelasi capat ori inceput, ori sfarsit
	if (first) 
	{ //in primul rand verficam daca avem lista
		nodDublu* p = first;
		while (p->next) {//cat timp exista p next ne deplasam
			p = p->next;
		}
		nodDublu* nou = (nodDublu*)malloc(sizeof(nodDublu));
		nou->info.nrPagini = info.nrPagini;//facem shallow copy tb sa aloc spatiul
		nou->info.titlu = (char*)malloc(sizeof(char)*(strlen(info.titlu) + 1));
		strcpy(nou->info.titlu, info.titlu);
		nou->next = NULL;
		nou->prev = p;
		p->next = nou;
		return first;//iterare la sfarsit
	}
	else 
	{
		nodDublu* nou = (nodDublu*)malloc(sizeof(nodDublu));
		nou->info.nrPagini = info.nrPagini;//facem shallow copy tb sa aloc spatiul
		nou->info.titlu = (char*)malloc(sizeof(char)*(strlen(info.titlu) + 1));
		strcpy(nou->info.titlu, info.titlu);
		nou->next = NULL;
		nou->prev = NULL;
		return nou;
	}

}

HashTable initializare(int dim) 
{
	HashTable tabela;
	tabela.dim = dim;
	tabela.vector = (nodDublu**)malloc(sizeof(nodDublu*)*dim);
	for (int i = 0;9 < dim;i++)
	{
		tabela.vector[i] = NULL;
	}
	return tabela;
}

int hashCode(Carte carte, HashTable tabela) 
{
	return carte.nrPagini%tabela.dim; //%modulo
}

int inserareInTabela(HashTable tabela, Carte carte) 
{
	//verific daca a initializat tabbela 
	int pozitie = -1;
	if (tabela.vector) 
	{
		pozitie = hashCode(carte, tabela);
		if (tabela.vector[pozitie]) 
		{
			//coliziune
			tabela.vector[pozitie] = inserareListaDubla(tabela.vector[pozitie], carte);
		}
		else
		{
			//aici nu avem coliziune 
			tabela.vector[pozitie] = inserareListaDubla(tabela.vector[pozitie], carte);
		}
	}
	return pozitie;
}

void afisareCarte(Carte carte) 
{
	printf("Cartea %s are %d pagini\n", carte.titlu, carte.nrPagini);
}

void afisareListaDublu(nodDublu* first) 
{
	while (first) {
		afisareCarte(first->info);
		first = first->next;
	}
}

void afisareTabela(HashTable  tabela) 
{
	for (int i = 0; i < tabela.dim; i++) 
	{
		afisareListaDublu(tabela.vector[i]);
		printf("\n");
	}
}

nodDublu* stergereListaDubla(nodDublu* first) 
{
	while (first) 
	{
		free(first->info.titlu);
		nodDublu*temp = first;
		first = first->next;
		free(temp);
	}
	return NULL;
}

HashTable stergereTabela(HashTable tabela) 
{
	for (int i = 0; i < tabela.dim; i++) 
	{
		tabela.vector[i]=stergereListaDubla(tabela.vector[i]);
	}
	free(tabela.vector);
	tabela.vector = NULL;
	return tabela;
}

Carte cautareCarte(int nrPagini, HashTable tabela) 
{
	int pozitie=hashCode()
}

void main() {
	
	//trebuie sa am o metoda care sa imi initializeze (stabili harcodat)
	HashTable tabela = initializare(5);
	inserareInTabela(tabela, citesteCarte());
	inserareInTabela(tabela, citesteCarte());
	inserareInTabela(tabela, citesteCarte());

	afisareTabela(tabela);

	Carte c = cautareCarte(400, tabela);
	printf("Carte gasita: ");
	afisareCarte(c);
	tabela=stergereTabela(tabela);

	free(c.titlu);
}