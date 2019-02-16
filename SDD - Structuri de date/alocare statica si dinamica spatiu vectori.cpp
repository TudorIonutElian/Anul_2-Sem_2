//
//  main.cpp
//  study_basics
//
//  Created by CR on 13/02/2019.
//

#include <iostream>
#include <vector> // pentru vector c++

using namespace std;



int main() {
    
//    for (int i = 0; i < 5; i++){
//        cout << "Hello world!" << endl;
//    }
    
//    int i = 0;
//    while (i < 5){
//        cout << "Hello" << endl;
//        i++;
//    }
    
//    string sir;
//    cout << "String: "; cin >> sir;
//    cout << sir << endl;
//
//    char caractere[20];
//    cout << "Caractere: "; cin >> caractere;
//    cout << caractere << endl;
    
    
    //------alocare spatiu cu "new" vs "malloc"------//
    
    //---------------NEW / DELETE---------------//
    
    // alocarea dinamica a unui sir de caractere
    // 1. alocam spatiu in mod dinamic (in HEAP)
    char * pSir;
    // 1.1 ii dau lui pSir dimensiunea lui "Tutorial" + 1 pentru caracterul "sfarsit de caractere"
    pSir = new char [strlen("Tutorial - NEW")+1];
    // 1.2 copiez
    strcpy(pSir, "Tutorial - NEW");
    // 1.3 afisare
    cout << pSir << endl;
    // 2. dezaloc spatiul alocat
    delete[] pSir;
    
    //---------------MALLOC / FREE---------------//
    char * mallocSir;
    /*  sizeof - determin cat ocupa un element din sirul nostru de caractere
        il inmultesc cu numarul de elemente din vectorul nostru
        malloc nu stie la ce trebuie sa aloce => tipul returnat e void*
        solutie => fac un cast explicit la (char*)
     */
    mallocSir = (char*) malloc((sizeof(char) * (strlen("Tutorial - MALLOC") + 1)));
    // copiez
    strcpy(mallocSir, "Tutorial - MALLOC");
    // afisez
    cout << mallocSir << endl;
    // sterg spatiul alocat
    free(mallocSir);
    
    //------END alocare spatiu cu "new" vs "malloc"------//
    
    //----------------------------------------------------------//
    //------5. Vector cu elemente de tip int alocat static------//
    
    //---C++--- - aici e cu STL//
    vector <int> vec;
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(2);
    // parcurgere vector
    // size returneaza dimensiunea acelui vector (cate elemente are)
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    
    
    //---C--- - in C nu exista STL//
    
    //1. declaram vectorul
    // 1.1 tip elemente: int
    // 1.2 nume vector: v
    // 1.3 il alocam static in stack [10] - 10 nr maxim de elemente din vector
    int v[10];
    //2. cate elemente am in vector efectiv?
    int dimensiuneVector = 0;
    // vec.push_back[6];
    v[dimensiuneVector] = 6; // il pune pe 6 pe pozitia 0
    dimensiuneVector++;
    v[dimensiuneVector] = 4; // il pune pe 4 pe pozitia 1
    dimensiuneVector++;
    // il adaugam si pe ultimul, dar de la tastatura
    cout << "Introduceti ultima valoare a vectorului: ";
    cin >> v[dimensiuneVector];
    dimensiuneVector++;
    // afisare
    for (int i = 0; i < dimensiuneVector; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    //--------------------------------------------------------------//
    //------5. END Vector cu elemente de tip int alocat static------//
    
    
    
    
    //-----------------------------------------------------------//
    //------6. Vector cu elemente de tip int alocat dinamic------//
    // alocam spatiu pentru exact cate elemente avem nevoie
    
                    //1. declaram un pointer la int
    int * pVector;  // ne-am declarat o zona in care putem sa punem o adresa de memorie
                    // la aceasta adresa putem sa alocam spatiu (2 metode:  cu new sau cu malloc)
    int dimensiune = 4;
//    pVector = new int [dimensiune]; // alocare cu new
    pVector=(int*)malloc(sizeof(int) * dimensiune);
    // citim elementele de la tastatura
    cout << " Introduceti elementele: ";
    for (int i = 0; i < dimensiune; i++){
        cin >> pVector[i];
    }
    cout << "Elementele sunt: ";
    for (int i = 0; i < dimensiune;  i++){
        cout << pVector[i] << " ";
    }
    
    // dezaloc spatiul alocat cu free sau delete (in functie de ce s-a folosit pentru alocare)
    free(pVector);
    // delete[] pVector;
}
