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
        void insert(int* data){
            //star the new node
            CollectorNode* newCollectorNode = new CollectorNode(data);
            newCollectorNode->next = head;
            head = newCollectorNode;
            size++;
        };  
        //check if the list is empty, if not the function return a boolean value to start the process
        bool checkList(){
            if(size == 0){
                return true;
            }
        } 
};