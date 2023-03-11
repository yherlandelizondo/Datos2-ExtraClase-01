#include<iostream>
#include<stdio.h>
#include "Node.cc"
#include "CollectorList.cc"
using namespace std;

CollectorList collector;

void* operator new(size_t size){//Overloading the new class
    if(collector.checkList()){ //check if the collector it's empty (if collector size equal 0 the function checkList return True)
        //create the node using malloc   
        cout << "\n";
        cout << "collector empty.\n";
        void* ptr = malloc(size);
        return ptr;
    }
    else{
        //use existing space
        void* ptr = collector.useSpace();
        return ptr;
    }
}
void operator delete(void* ptr){ //Overloading delete class
    collector.insert(ptr);
    free(ptr);
    
    
}
            
class List{
    Node* head;
    public:
        List(){
            head = NULL;
        }

        //insert at the beginnig of the list
        void insert(int data){
            Node* newNode = new Node(data); 
            newNode->next = head;
            head = newNode;
            cout << "Inserted node: " << newNode->getData()<<"\n";
        }
        Node* removeAux(Node* node){
            cout << "deleted node: " << node->getData()<<"\n";
            Node* temp = head;
            delete node;

            cout << "hola";
            /*
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
                */
                return 0;
        }
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
                cout << "Empty list" << "\n";
                return;
            }

            //if the list isn't empty, print all the possible elements.
            while(temp1 != NULL){
                cout << temp1->getData() << " -> ";
                temp1 = temp1->next;
            }
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