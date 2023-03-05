#include<iostream>
#include<stdio.h>

class collectorNode{
    public:
        int* memPtr;
        collectorNode* next;

        Node(){
            memPtr = 0;
            next = NULL;
        }
        Node(int data){
            this->memPtr = data;
            this->next = NULL;
        }
};