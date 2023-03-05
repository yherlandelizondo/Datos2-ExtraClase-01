#include<iostream>
#include<stdio.h>
#include "Node.cc"
using namespace std;

//inclomplete
class collectorList{
    Node* head;
    public:
        List(){
            head = NULL;
        };

        //insert at the beginnig of the list
        void insert(int data){
            //star the new node
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        };      
};