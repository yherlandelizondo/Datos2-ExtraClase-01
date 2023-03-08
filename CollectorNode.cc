#include<iostream>
#include<stdio.h>

class CollectorNode{
    public:
        void* memPtr;
        CollectorNode* next;

        CollectorNode(){
            memPtr = 0;
            next = NULL;
        }
        CollectorNode(void* ptr){
            this->memPtr = ptr;
            this->next = NULL;
        }
        void setMemPtr(void* value){
            memPtr = value;
        }
        void* getMemPtr(){
            return memPtr;
        }
        void setNext(CollectorNode* ptr){
            next = ptr;
        }
        CollectorNode* getNext(){
            return next;
        }
};