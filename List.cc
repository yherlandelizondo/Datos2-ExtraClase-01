#include<iostream>
#include<stdio.h>
#include "Node.cc"
#include "CollectorList.cc"
using namespace std;

CollectorList collector;

void* operator new(size_t size){//Overloading operator new
    if(collector.checkList()){ //check if the collector it's empty (if collector size equal 0 the function checkList return True) 
        void* ptr = malloc(size);//create the node using malloc  
        return ptr; //return the pointer
    }
    else{
        void* ptr = collector.useSpace(); //use existing space
        return ptr;
    }
}
void operator delete(void* ptr){ //Overloading operator delete
    collector.insert(ptr);
}
            
class List{
    Node* head;
    public:
        //constructor method
        List(){
            head = NULL;
        }

        //insert at the beginnig of the list
        void insert(int data){
            Node* newNode = new Node(data); 
            newNode->next = head;
            head = newNode;
            cout << "\n";
            cout << "INSERTED NODE: " << newNode->getData()<<"\n";
        }
        //Auxiliar function to remove a node from the list and recycle his memory
        Node* removeAux(Node* node){
            cout << "\n";
            cout << "DELETED NODE: " << node->getData()<<"\n";
            Node* temp = head;
            delete node;
            
            //cycle used to remove the node from the main list
            while(temp != NULL){
                if(temp->getData() == node->getData()){
                    temp = temp -> next;
                }
                else if(temp->next->getData() == node->getData()){
                        temp->next = temp->next->next;
                    }
                else{
                        temp = temp->next;
                    }
                    return temp;
                }
                return 0;
        }
        //funtion to check if the inserted value exist in the list, if true, call the auxiliar funtion
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
        //print the list elements
        void printList(){
            Node* temp1 = head;
            //check if the list it's empty.
            if(head == NULL){
                cout << "Empty principal list" << "\n";
                return;
            }

            //if the list isn't empty, print all the possible elements.
            while(temp1 != NULL){
                cout << temp1->getData() << " -> ";
                temp1 = temp1->next;
            }
            return;
        }
        //return the collector object
        CollectorList getCollector(){
            return collector;
        }
        //return the value of the pointer
        Node* getHead(){
            return head;
        }
        //set the value of the pointer
        void setHead(Node* data){
            head = data;
        }
     
};