#include<iostream>
#include<stdio.h>

class CollectorNode{
    public:
        int* memPtr;
        CollectorNode* next;

        CollectorNode(){
            memPtr = 0;
            next = NULL;
        }
        CollectorNode(int* ptr){
            this->memPtr = ptr;
            this->next = NULL;
        }
};