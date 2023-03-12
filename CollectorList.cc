#include<iostream>
#include<stdio.h>
#include "CollectorNode.cc"
using namespace std;

//! class of collector list
class CollectorList{
    CollectorNode* head;
    int size;
    public:
        //! constructor method
        CollectorList(){
            head = NULL;
            size = 0;
        }
        //! method to insert a node at the beginnig of the list
        void insert(void* ptr){
            CollectorNode* newCollectorNode = (CollectorNode*) malloc(sizeof(CollectorNode*)); 
            newCollectorNode->setMemPtr(ptr);
            newCollectorNode -> setNext(head);
            head = newCollectorNode;
            size++;
        }   
        //! method used to use an available memory space
        void* useSpace(){
            CollectorNode* space = head;
            head = head->next;
            size--;
            return space->getMemPtr();
        }
        //! method to print the list elements
        void printList(){
            CollectorNode* temp = head;
            if(head == NULL){
                cout << "\n" << "Empty collector list";
                return;
            }
            cout << "\n";
            while(temp != NULL){
                cout << temp-> getMemPtr() << " -> ";
                temp = temp->next;
            }
            return;
        }
        //! method used to return the head of the list
        CollectorNode* getHead(){
            return head;
        }
        //! method used to check if the list is empty, if not the function return a boolean value to continue with the process
        bool checkList(){
            if(size == 0){
                return true;
            }
            return false;
        } 
};

