#include<iostream>
#include<stdio.h>

class Node{
    public:
        int data;
        Node* next;

        Node(){
            data = 0;
            next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        void setData(int value){
            data = value;
        }
        int getData(){
            return data;
        }
        void setNext(Node* ptr){
            next = ptr;
        }
        Node* getNext(){
            return next;
        }
};
