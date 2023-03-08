#include<iostream>
#include<stdio.h>
#include "Node.cc"
#include "CollectorList.cc"
using namespace std;

CollectorList collector;

void* operator new(size_t size){//Overloading the new class
    cout << "State of if: " << collector.checkList() << "\n";
    if(collector.checkList()){ //check if the collector it's empty (if collector size equal 0 the function checkList return True)
        //create the node using malloc   
        cout << "Entro al caso de la lista vacia\n";
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
    cout << "valor de ptr: " << ptr <<"\n";
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
            cout << newNode->getData() << " cheking the data of newNode \n";
        }
        Node* removeAux(Node* node){
            Node* temp = head;
            void* nodePtr = &node;
            delete nodePtr;
            
            while(temp != NULL){
                if(temp->next->getData() == node->getData()){
                    if(temp == head){
                        head = head->next;
                    }else{
                        temp->next = temp->next->next;
                    }
                    return temp;
                }else{
                    temp = temp->next;
                }
            }
        }
        void remove(int value){
            Node* temp = head;

            while(temp != NULL){
                if(temp->getData() == value){
                    removeAux(temp);
                    break;
                }else{
                    temp = temp->next;
                }
            }
            cout<< "Valor no enocontrado.\n";
        }
        //print the list elements
        void printList(){
            Node* temp = head;
            //check if the list it's empty.
            if(head == NULL){
                cout << "Empty list" << "\n";
                return;
            }

            //if the list isn't empty, print all the possible elements.
            while(temp != NULL){
                cout << temp->getData() << " -> ";
                temp = temp->next;
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