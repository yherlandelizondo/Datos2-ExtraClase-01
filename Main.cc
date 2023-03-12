#include<iostream>
#include<stdio.h>
#include "List.cc"
using namespace std;


//! Main class, used to initialize everything
int main(){
    List newList;
    int aux = 0;
    while (aux != -1){
        cout << "\n\n";
        cout << "----Press -1 to close the program----\n";
        cout << "Insert -2 to add or -3 to delete: ";
        cin >> aux;
        if(aux == -1){
            cout << "\n" << "Grabriela Q.S - Yherland E.C" << "\n";
            break;
        }else if(aux == -2){
            cout << "Type the value to insert: ";
            cin >> aux;
            cout << "\n";
            newList.insert(aux);
            cout << "///////////////////////////////////\n";
            newList.printList();
            newList.getCollector().printList();
            cout << "\n";
            cout << "///////////////////////////////////\n";
        }else if(aux == -3){
            cout << "Type the value to remove: ";
            cin >> aux;
            cout << "\n";
            newList.remove(aux);
            cout << "///////////////////////////////////\n";
            newList.printList();
            newList.getCollector().printList();
            cout << "\n";
            cout << "///////////////////////////////////\n";
        }else{
            cout << "Invalid value.\n";
            break;
        }
   }
    return 0;
}

