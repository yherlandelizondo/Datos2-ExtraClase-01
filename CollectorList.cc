#include<iostream>
#include<stdio.h>
#include "CollectorNode.cc"
using namespace std;

//inclomplete
class CollectorList{
    CollectorNode* head;
    int size;
    
    public:
        CollectorList(){
            head = NULL;
            size = 0;
        };
        
        //insert at the beginnig of the list
        void insert(void* ptr){
            //star the new node
            CollectorNode* newCollectorNode = new CollectorNode(ptr);
            newCollectorNode->next = head;
            head = newCollectorNode;
            size++;
        };  
        void* useSpace(){
            CollectorNode* space = head;
            head = head->next;
            size--;
            return space->getMemPtr();
        }
        void printList(){
            CollectorNode* temp = head;
            //check if the list it's empty.
            if(head == NULL){
                cout << "\n";
                cout << "Empty list" << "\n";
                return;
            }

            //if the list isn't empty, print all the possible elements.
            while(temp != NULL){
                cout << temp-> getMemPtr() << " -> ";
                temp = temp->next;
            }
        }
        //check if the list is empty, if not the function return a boolean value to start the process
        bool checkList(){
            if(size == 0){
                return true;
            }
            return false;
        } 
};

