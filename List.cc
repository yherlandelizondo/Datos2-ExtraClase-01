#include<iostream>
#include<stdio.h>
#include "Node.cc"
using namespace std;

class List{
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
        //print the list elements
        void printList(){
            Node* temp = head;
            //check if the list it's empty.
            if(head == NULL){
                cout << "Empty list" << "\n";
                return;
            }

            //if the list isn't empty, print all the possible elements.
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        };
        //return the value of the pointer
        Node* getHead(){
            return head;
        };
        //set the value of the pointer
        void setHead(Node* data){
            head = data;
        };


        
};