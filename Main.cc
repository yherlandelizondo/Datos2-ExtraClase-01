#include<iostream>
#include<stdio.h>
#include "List.cc"
using namespace std;

int main(){
    List newList;
    CollectorList collector;

    //cout << "State of if: " << collector.checkList() << "\n";
    
    newList.insert(5); 
    cout << "///////////////////////////////////\n";
    newList.printList();
    collector.printList();
    cout << "///////////////////////////////////\n";

    newList.insert(8);
    cout << "///////////////////////////////////\n";
    newList.printList();
    collector.printList();
    cout << "///////////////////////////////////\n";
    //hasta aqui el asunto esta bien.
    newList.remove(5);
    cout << "///////////////////////////////////\n";
    collector.printList();
    collector.printList();
    cout << "///////////////////////////////////\n";
 


    return 0;
}

