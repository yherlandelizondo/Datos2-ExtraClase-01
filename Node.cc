#include<iostream>
#include<stdio.h>

//! Node class, used to create Node objects
class Node{
    public:
        int data;
        Node* next;
        //! constructor method
        Node(){
            data = 0;
            next = NULL;
        }
        //! constructor method
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        //! method used to set the data value
        void setData(int value){
            data = value;
        }
        //! method used to get the data value
        int getData(){
            return data;
        }
        //! method used to set the next value
        void setNext(Node* ptr){
            next = ptr;
        }
        //! method used to get the next value
        Node* getNext(){
            return next;
        }
};
