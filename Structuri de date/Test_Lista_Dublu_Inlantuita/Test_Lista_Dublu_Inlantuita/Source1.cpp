//#include <iostream>
//#include<stdlib.h>
//using namespace std;
//struct nod
//{
//	int valoare;
//	struct nod *left;
//	struct nod *right;
//};
//
//struct nod* getnode()
//{
//	return (struct nod *)malloc(sizeof(struct nod));
//};
//struct nod* top; int c = 0;
//struct nod* adauga(struct nod *);
//struct nod* sterge(struct nod *);
//void afiseaza(struct nod *);
//
//struct nod* adauga(struct nod *FIRST)
//{
//	struct nod *T;
//	if (FIRST == NULL)
//	{
//		FIRST = getnode();
//		T = top = FIRST;
//		T->left = NULL;
//	}
//	else
//	{
//		T = getnode();
//		top->right = T;   T->left = top;
//		top = T;
//	}
//	cout << "Introduceti o valoare" << endl; c++;
//	cin >> T->valoare;
//	T->right = NULL;
//	return FIRST;
//}
//struct nod* sterge(struct nod *FIRST)
//{
//	struct nod *T;
//	if ((FIRST == NULL) && (c<1))
//	{
//		cout << "Underflow - stiva este goala" << endl; return FIRST;
//	}
//	T = top;
//	cout << "Valoarea stearsa este : %d\n", T->valoare;
//	if (c != 1)
//	{
//		top = T->left;
//		T->left = NULL; top->right = NULL;
//	}
//	else if (c == 1)
//	{
//		FIRST = NULL;
//	}
//	c--;
//	return FIRST;
//}
//
//void afiseaza(struct nod *T)
//{
//	if (T == NULL)
//	{
//		cout << "Goala" << endl; return;
//	}
//	while (T != NULL)
//	{
//		printf("%d  ", T->valoare);
//		T = T->right;
//	}
//	printf("\n");
//}
//
//void main()
//{
//	struct nod *F;
//	int meniu;
//	F = NULL; top = F;
//	while (1)
//	{
//		cout << "1. Adauga un nou element in stiva" << endl;
//		cout << "2. Sterge element din stiva" << endl;
//		cout << "3. Afiseaza elementele din stiva" << endl;
//		cout << "4. Exit" << endl;
//		cin >> meniu;
//		if (meniu == 1)
//			F = adauga(F);
//		else if (meniu == 2)
//			F = sterge(F);
//		else if (meniu == 3)
//			afiseaza(F);
//		else if (meniu == 4)
//			return;
//	}
//	//return 0;
//}