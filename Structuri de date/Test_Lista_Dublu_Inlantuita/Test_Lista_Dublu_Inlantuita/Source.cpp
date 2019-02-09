//#include <iostream>
//#include<stdlib.h>
//struct Parc {
//	char* numeParc;
//	int nr_vizitatori;
//	float suprafataParc;
//};
//
//Parc citesteParc() {
//	Parc parc;
//	char buffer[20];
//	printf("Nume Parc: \t");
//	scanf("%s", buffer);
//	parc.numeParc = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(parc.numeParc, buffer);
//	printf("Numar de vizitatori: \t");
//	scanf("%d", &parc.nr_vizitatori);
//	printf("Suprafata parcului: \t");
//	scanf("%f", &parc.suprafataParc);
//
//	return parc;
//}
//
//
//void afisareParc(Parc p) {
//	printf("Parcul %s are %d de vizitatori, iar suprafata lui este de %5.2f\n",
//		p.numeParc, p.nr_vizitatori, p.suprafataParc);
//}
//
//struct node {
//	node *next, *prev;
//	//nod*prev;
//	Parc info;
//};
//
///*
//struct nod
//{
//	int valoare;
//	struct nod *prev; //*left;
//	struct nod *next;//*right;
//};
//
//*/
////incapsularea adreselor primului si ultimului nod al listei duble
//struct ListaDubla {
//	node*first;
//	node*last;
//};
//
//ListaDubla inserareInceput(ListaDubla ld, Parc p) {
//	/*alocarea de memorie heap pentru un nod al listei duble*/
//	node* nou = (node*)malloc(sizeof(node));
//	nou->info.numeParc = (char*)malloc(sizeof(char)*(strlen(p.numeParc) + 1));
//	strcpy(nou->info.numeParc, p.numeParc);
//	nou->info.nr_vizitatori = p.nr_vizitatori;
//	nou->info.suprafataParc = p.suprafataParc;
//	nou->prev = NULL;
//	if (ld.first) {
//		nou->next = ld.first;
//		ld.first->prev = nou;
//		ld.first = nou;
//	}
//	else {
//		ld.first = ld.last = nou;
//		nou->next = NULL;
//	}
//	return ld;
//}
//
//void afisareOrdineListaDubla(ListaDubla ld) {
//	node*b = ld.first;
//	while (b)
//	{
//		afisareParc(b->info);
//		b = b->next;
//	}
//}
//
//
//
//struct node* getnode()
//{
//	return (struct node *)malloc(sizeof(struct node));
//};
//struct node* top; int c = 0;
//struct node* adauga(struct node *);
//struct node* filtrare(struct node *);
//void afiseaza(struct node *);
//
//
//
//struct node* adauga(struct node *FIRST)
//{
//	struct node *T;
//	if (FIRST == NULL)
//	{
//		FIRST = getnode();
//		T = top = FIRST;
//		T->prev = NULL;
//	}
//	else
//	{
//		T = getnode();
//		top->next = T;   T->prev = top;
//		top = T;
//	}
//	printf("Introduceti o valoare\n"); c++;
//	scanf("%d", &T->info);
//	T->next = NULL;
//	return FIRST;
//}
//
////Am ales stiva asa ca ultima valoare introdusa este cea filtrata.
//struct node* filtrare(struct node *FIRST)
//{
//	struct node *T;
//	if ((FIRST == NULL) && (c<1))
//	{
//		printf("Stiva este goala (underflow)\n"); return FIRST;
//	}
//	T = top;
//	printf("Valoarea filtrata este : %d\n", T->info);
//	if (c != 1)
//	{
//		top = T->prev;
//		T->prev = NULL; top->next = NULL;
//	}
//	else if (c == 1)
//	{
//		FIRST = NULL;
//	}
//	c--;
//	return FIRST;
//}
//
//void afiseaza(struct node *T)
//{
//	if (T == NULL)
//	{
//		printf("(underflow) => Stiva este goala, apasa 1 pentru a adauga elemente.\n"); return;
//	}
//	while (T != NULL)
//	{
//		printf("%d, ", T->info);
//		T = T->next;
//	}
//	printf("\n");
//}
//
//void main()
//{
//	ListaDubla ld;
//	ld.first = NULL;
//	
//ld.last = NULL;
//	struct node *F;
//	int meniu;
//	F = NULL; top = F;
//	while (1)
//	{
//		printf("\t\tMENIU\n");
//		printf("1. Adauga un nou element in stiva\n");
//		printf("2. Filtreaza element din stiva\n");
//		printf("3. Afiseaza elementele din stiva \n");
//		printf("4. Adauga elemente in Parc \n");
//		printf("5. Afisare elemente parc \n");
//		printf("6. Exit \n");
//		printf("\n");
//		scanf("%d", &meniu);
//		if (meniu == 1)
//			F = adauga(F);
//		else if (meniu == 2)
//			F = filtrare(F);
//		else if (meniu == 3)
//			afiseaza(F);
//		else if (meniu == 4)
//			citesteParc();
//		else if (meniu == 5)
//			citesteParc(); //de modificat in filtrare
//		else if (meniu == 6) 
//			return;
//	}
//
//	//dezalocare memorie
//	while (ld.first) {
//		free(ld.first->info.numeParc);
//		ld.first = ld.first->next;
//		if (ld.first) {
//			free(ld.first->prev); //dezalocare memorie heap
//		}
//		else {
//			//dezalocare memorie heap 
//			free(ld.last);
//		}
//	}
//	ld.first = ld.last = NULL;
//
//	
//	//return 0;
//}