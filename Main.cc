#include<iostream>
#include<stdio.h>
#include "List.cc"
using namespace std;

int main(){
    List newList;
    int value = 0;

    while(value != -1){
        cout << "\n";
        cout << "Ingrese -1 para salir." << "\n";
        cout << "Favor ingrese el valor a instertar: ";
        cin >> value;
        newList.insert(value);
        cout << "\n" << "/////////////////////////////////////" << "\n" ;
        newList.printList();
        cout  << "\n" << "/////////////////////////////////////" << "\n";
    }
}

