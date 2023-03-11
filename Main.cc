#include<iostream>
#include<stdio.h>
#include "List.cc"
using namespace std;

int main(){
    List newList;

    //cout << "State of if: " << collector.checkList() << "\n";
    
    newList.insert(5); 
    cout << "///////////////////////////////////\n";
    newList.printList();
    newList.getCollector().printList();
    cout << "\n";
    cout << "///////////////////////////////////\n";

    newList.insert(8);
    cout << "///////////////////////////////////\n";
    newList.printList();
    newList.getCollector().printList();
    cout << "\n";
    cout << "///////////////////////////////////\n";

    //hasta aqui el asunto esta bien.
    newList.remove(5);
    cout << "///////////////////////////////////\n";
    newList.printList();
    cout << "\n";
    newList.getCollector().printList();
    cout << "\n";
    cout << "///////////////////////////////////\n";

    newList.insert(9); 
    cout << "///////////////////////////////////\n";
    newList.printList();
    newList.getCollector().printList();
    cout << "\n";
    cout << "///////////////////////////////////\n";

    newList.remove(8);
    cout << "///////////////////////////////////\n";
    newList.printList();
    cout << "\n";
    newList.getCollector().printList();
    cout << "\n";
    cout << "///////////////////////////////////\n";


    return 0;
}

