//
//  main.cpp
//  study_basics
//
//  Created by CR on 13/02/2019.
//

#include <iostream>
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


}
