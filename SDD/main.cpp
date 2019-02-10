//
//  main.cpp
//  SDD-10-02-2019
//
//  Created by  on 10/02/2019.
//  Copyright © 2019 . All rights reserved.
//

//program dimensiune_tip;
#include <iostream>
#include <stdlib.h> // pentru malloc.h
using namespace std;

int main()
{
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n Reprezentarea datelor de tip întreg";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n char: "<< sizeof(char)<<" octet";
    cout<<"\n unsigned char: "<< sizeof(unsigned char)<<" octet";
    cout<<"\n int: "<< sizeof(int)<<" octeti";
    cout<<"\n unsigned int: "<< sizeof(unsigned int)<<" octet";
    cout<<"\n signed int: "<< sizeof(signed int)<<" octeti";
    cout<<"\n short int: "<<sizeof(short int)<<" octeti";
    cout<<"\n long int: "<< sizeof(long int)<<" octeti";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n Reprezentarea datelor de tip real";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n float: "<< sizeof(float)<<" octeti";
    cout<<"\n double: "<<sizeof(double)<<" octeti";
    cout<<"\n long double: "<<sizeof(long double)<<" octeti";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n Reprezentarea datelor de tip caracter";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n char: "<<sizeof(char)<<" octet";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n Reprezentarea datelor de tip logic";
    cout<<"\n - - - - - - - - - - - - - - - - - - - - - - -  - ";
    cout<<"\n boolean: "<< sizeof(bool)<<" octet" << endl;
}
