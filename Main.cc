#include<iostream>
#include<stdio.h>
#include "List.cc"
using namespace std;

int main(){
    List newList;
    CollectorList collector;

    newList.insert(5); 
    newList.printList();
    collector.printList();

    cout << "///////////////////////////////////////////////////////////////\n";
    cout << "se borra el 5:\n";

    newList.remove(5);
    newList.printList();
    collector.printList();   
}

