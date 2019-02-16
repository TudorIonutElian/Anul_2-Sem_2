#include <conio.h>
#include <iostream>
using namespace std;
//members of the <hash_map> and <hash_set> header files are not currently part of the ISO C++ standard
#include <hash_map>
//using stdext namespace
using namespace stdext;

void main()
{
  hash_map<int, char*> myHash1;

  myHash1[2215] = "POO";
  myHash1[2320] = "SDD";
  myHash1[2001] = "PAW";

  cout << "La sala 2215 se desfasoara " << myHash1[2215] <<endl;
  cout << "La sala 2320 se desfasoara " << myHash1[2320] <<endl;
  cout << "La sala 2001 se desfasoara " << myHash1[2001] <<endl;

  cout << "Tabela myHash1 contine " << myHash1.size() <<" elemente" <<endl;
  
  hash_map<int, char*> myHash2;
  
  myHash1.swap(myHash2);

  cout << "Tabela myHash2 contine " << myHash2.size() <<" elemente" <<endl;

  cout << "La sala 2215 se desfasoara " << myHash2[2215] <<endl;
  cout << "La sala 2320 se desfasoara " << myHash2[2320] <<endl;
  cout << "La sala 2001 se desfasoara " << myHash2[2001] <<endl;

  hash_map<char*, int> myHash3;
  myHash3["POO"] = 2215;
  
  cout << "POO se desfasoara la sala " << myHash3["POO"] <<endl;

  getch();
}