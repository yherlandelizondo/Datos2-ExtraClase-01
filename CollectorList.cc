#include<iostream>
#include<stdio.h>
#include "CollectorNode.cc"
using namespace std;

class CollectorList{
    CollectorNode* head;
    int size;
    
    public:
        //constructor method
        CollectorList(){
            head = NULL;
            size = 0;
        };
        
        //insert a node at the beginnig of the list
        void insert(void* ptr){
            CollectorNode* newCollectorNode = new CollectorNode(ptr);//initialize the new node
            newCollectorNode->next = head;
            head = newCollectorNode;
            size++;
        };  
        //method used to use an available memory space
        void* useSpace(){
            CollectorNode* space = head;
            head = head->next;
            size--;
            return space->getMemPtr();
        }
        //print the list elements
        void printList(){
            CollectorNode* temp = head;

            //check if the list it's empty.
            if(head == NULL){
                cout << "\n";
                cout << "Empty collector list";
                return;
            }

            //if the list isn't empty, print all the possible elements.
            while(temp != NULL){
                cout << temp-> getMemPtr() << " -> ";
                temp = temp->next;
            }
            return;
        }
        //method used to return the head of the list
        CollectorNode* getHead(){
            return head;
        }

        //check if the list is empty, if not the function return a boolean value to continue with the process
        bool checkList(){
            if(size == 0){
                return true;
            }
            return false;
        } 
};

