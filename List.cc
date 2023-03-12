#include<iostream>
#include<stdio.h>
#include "Node.cc"
#include "CollectorList.cc"
using namespace std;

CollectorList collector;

//! Overloading operator new
void* operator new(size_t size){
    if(collector.checkList()){ 
        void* ptr = malloc(size);
        return ptr;
    }
    else{
        void* ptr = collector.useSpace();
        return ptr;
    }
}
//! Overloading operator delete
void operator delete(void* ptr){ 
    collector.insert(ptr);
}
//! Class of the principal list         
class List{
    Node* head;
    public:
        //! constructor method
        List(){
            head = NULL;
        }
        //! insert at the beginnig of the list
        void insert(int data){
            Node* newNode = new Node(data); 
            newNode->next = head;
            head = newNode;
            cout << "\n";
            cout << "INSERTED NODE: " << newNode->getData()<<"\n";
        }
        //! Auxiliar function to remove a node from the list and recycle his memory
        Node* removeAux(Node* node){
            cout << "\n";
            cout << "DELETED NODE: " << node->getData()<<"\n";
            Node* temp = head;
            delete node;
            while(temp != NULL){
                if(temp->getData() == node->getData()){
                    head = head -> next;
                    return temp;
                }
                else if(temp->next->getData() == node->getData()){
                    temp->next = temp->next->next;
                    return temp;
                    }
                else{
                    temp = temp->next;
                }
                }
                return 0;
        }
        //! funtion to check if the inserted value exist in the list, if true, call the auxiliar funtion
        int remove(int value){
            Node* temp = head;
            while(temp != NULL){
                if(temp->getData() == value){
                    removeAux(temp);
                    return 0;
                }else{
                    temp = temp->next;
                }
            }
            cout<< "Value not found.\n";
            return 0;
        }
        //! print the list elements
        int printList(){
            Node* temp1 = head;
            if(head == NULL){
                cout << "Empty principal list" << "\n";
            }else{
                while(temp1 != NULL){
                cout << temp1->getData() << " -> ";
                temp1 = temp1->next;
                }
            }
            return 0;
        }
        //! return the value of the pointer
        Node* getHead(){
            return head;
        }
        //! set the value of the pointer
        void setHead(Node* data){
            head = data;
        }
        //! function used to return the actual collector
        CollectorList getCollector(){
            return collector;
        }
};