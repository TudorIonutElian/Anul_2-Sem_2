#include <conio.h>
#include <iostream>
using namespace std;

//structura de date stocata in tabela de dispersie
struct Student
{
	int nr_matricol;
	char nume[20];
	char adresa[30];
	char localitate[20];
	char e_mail[20];
	char telefon[15];
};

void Afisare(Student s)
{
	cout<<"Nr_matricol: "<< s.nr_matricol <<endl;
	cout<<"Nume: "<< s.nume <<endl;
	cout<<"Adresa: "<< s.adresa<<endl;
	cout<<"Localitate: "<< s.localitate<<endl;
	cout<<"Email: "<< s.e_mail <<endl;
	cout<<"Telefon: "<< s.telefon <<endl;
}

//elementele tabelei de dispersie
//pentru simplificarea codului s-a utilizat o structura
struct NodDate
{
	NodDate *next;
	Student inf;
};

//Cheia este nr_matricol al studentului
struct HashStudent
{
	int size;
	NodDate ** elem;
};
	
//functie simpla de dispersie care utilizeaza operatorul modulo
//pentru a genera pozitia in tabela
int HashFunction(int cheie, HashStudent hs)
{
	return cheie%hs.size;
};

//aloca memorie pentru structura si initializeaza cu NULL valorile
HashStudent AlocaMemorie()
{
	HashStudent hs;
	hs.size=101;
	hs.elem = new NodDate*[hs.size];
	for (int i=0;i<hs.size;i++)
		hs.elem[i] = NULL;
	return hs;
}

//insereaza un element pe o pozitie generata de functia de dispersie
//pe baza valorii matricolei din structura 
int Insereaza(Student s, HashStudent hs)
{
	int index = -1;

	if (s.nr_matricol<0)
		return index;

	if (hs.elem!=NULL)
	{
		index = HashFunction(s.nr_matricol, hs);
		//prima inregistrare
		NodDate *nod_nou = new NodDate;
		nod_nou->next = NULL;
		nod_nou->inf = s;

		if (hs.elem[index]== NULL)
		{
			hs.elem[index] = nod_nou;	 
		}
		else //coliziune
		{
			NodDate *t = hs.elem[index];
			while(t->next!=NULL) t = t->next;
			t->next = nod_nou;
		}
	}
	return index;
}

//cauta un element dupa cheia nr_matricol
//in cazul in care nu este gasita nici o inregistrare este 
//returnata o structura Student cu nr_matricol -1
Student Cauta(int nr_matricol, HashStudent hs)
{
	//valoare de retur pentru cazurile in care nu este gasit elementul
	Student s_negasit;
	s_negasit.nr_matricol = -1;
	
	if (nr_matricol<0) return s_negasit;
	
	if (hs.elem!=NULL)
	{
		int index = HashFunction(nr_matricol, hs);
		if (hs.elem[index]==NULL)
		{
			return s_negasit;
		}
		else
		{
			if (hs.elem[index]->inf.nr_matricol ==nr_matricol)
				return hs.elem[index]->inf;
			else//coliziune
			{
			NodDate *t = hs.elem[index];
			while (t!= NULL && t->inf.nr_matricol!=nr_matricol)
					t = t->next;
				if (t==NULL)
					return s_negasit;
				else
					return t->inf;
			}
		}
	}
	//neinitializat sau nu exista inregistrarea
	return s_negasit;
}

//functie recursiva care elibereaza memoria ocupata de nodurile listei
void ElibereazaMemorieLista(NodDate *&inceput)
{
	if (inceput == NULL)
		return;
	else
	{
		ElibereazaMemorieLista(inceput->next);
		cout<<"Eliminat nodul cu codul: " <<inceput->inf.nr_matricol<<endl;
		delete inceput;
	}
}

//elibereaza memoria ocupata de tabela de dispesie
void dezalocHashStudent(HashStudent hs)
{
	if (hs.elem != NULL)
	{
		for (int i=0;i<hs.size;i++)
			ElibereazaMemorieLista(hs.elem[i]);
		delete [] hs.elem;
	}
}

//Sterge elementul al carui nr_matricol coincide cu nr_matricol trimisa ca parametru
//returneaza pozitia din tabela de unde a fost eliminat elementul
//sau -1 in cazul in care nu exista elementul cu cheia data
int Sterge(int nr_matricol, HashStudent hs)
{
	if (nr_matricol<0)
		return nr_matricol;

	if (hs.elem!=NULL)
	{
		int index = HashFunction(nr_matricol, hs);
		if (hs.elem[index]==NULL)
		{
			return -1;
		}
		else
		{
			//este primul
			if (hs.elem[index]->inf.nr_matricol ==nr_matricol)
			{
				if(hs.elem[index]->next == NULL)
				{
					delete hs.elem[index];
					hs.elem[index]=NULL;
				}
				else//mai sunt si alte elemente in lista
				{
					NodDate *t = hs.elem[index];
					hs.elem[index] = t->next;
					delete t;
				}
			}
			else//coliziune, nu este primul, il cautam
			{
				NodDate *t = hs.elem[index];
				while (t->next!= NULL && t->next->inf.nr_matricol!=nr_matricol)
					t = t->next;
				if (t->next==NULL)
					return -1;
				else//t->next->inf.nr_matricol == nr_matricol
				{
					NodDate *p = t->next;
					if (p->next ==NULL)
					{
						t->next = NULL;
						delete p;
					}
					else
					{
						t->next = p->next;
						delete p;
					}
				}
			}
			return index;
		}
		return -1;
	}
}

//Afiseaza continutul tabelei de dispersie
void Afiseaza(HashStudent hs)
{
	if (hs.elem!=NULL)
	{
		for (int i=0;i<hs.size;i++)
		{
			if (hs.elem[i]!= NULL)
			{
				NodDate *t = hs.elem[i];
				while (t!=NULL)
				{
					cout<<"S-a inserat in pozitia: " << i << " cheia: "<<t->inf.nr_matricol<<endl;
					t = t->next;
				}
			}
		}
	}
}

void main()
{
	Student grupa[] ={
		{1000,"Ion Vlad", "Str. Norilor 20","Bucuresti","ion@server.ro", "0101010101"},
		{204,"Mihai Vlad", "Str. Norilor 20","Bucuresti","mihai@server.ro", "0101010101"},
		{406,"Dan Vlad", "Str. Norilor 20","Bucuresti","dan@server.ro", "0101010101"},
		{305,"Lili Vlad", "Str. Norilor 20","Bucuresti","lili@server.ro", "0101010101"},
		{1022,"Silviu Vlad", "Str. Norilor 20","Bucuresti","silviu@server.ro", "0101010101"},
		{1021,"Alina Vlad", "Str. Norilor 20","Bucuresti","alina@server.ro", "0101010101"},
		{1030,"Sorin Vlad", "Str. Norilor 20","Bucuresti","sorin@server.ro", "0101010101"},
		{1032,"Titi Vlad", "Str. Norilor 20","Bucuresti","titi@server.ro", "0101010101"},
		{1200,"Gigel Vlad", "Str. Norilor 20","Bucuresti","gigel@server.ro", "0101010101"},
		{2021,"Anca Vlad", "Str. Norilor 20","Bucuresti","ioanca@server.ro", "0101010101"},
		{1230,"Maria Vlad", "Str. Norilor 20","Bucuresti","maria@server.ro", "0101010101"},
		{1008,"Elena Vlad", "Str. Norilor 20","Bucuresti","elena@server.ro", "0101010101"}
	};

	HashStudent hs;

	hs=AlocaMemorie();

	for (int i=0;i<sizeof(grupa)/sizeof(Student);i++)
	{
		Insereaza(grupa[i], hs);
	}
	Afiseaza(hs);
	int m;
	cout<<"Nr_matricol: ";
	cin>>m;

	while (m!=-1)
	{

		Student rez = Cauta(m, hs);
		if (rez.nr_matricol != -1) Afisare(rez);
		cout<<"Nr_matricol: ";
		cin>>m;
	}
	Sterge(1008, hs);
	Sterge(406, hs);
	Sterge(305, hs);
	Afiseaza(hs);
	dezalocHashStudent(hs);

	getch();
}