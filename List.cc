#include<iostream>
#include<stdio.h>
#include "Node.cc"
#include "CollectorList.cc"
using namespace std;

CollectorList collector;

void* operator new(size_t size){//Overloading the new class
    if(collector.checkList()){ //check if the collector it's empty (if collector size equal 0 the function checkList return True)
        //create the node using malloc   
        cout << "Overloading the new operator \n";
        void* ptr = malloc(size);
        return ptr;
    }
    else{
        //use existing spacing

    }
}
void operator delete(void *ptr){ //Overloading delete class
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
            //check if the collector it's empty (if collector size equal 0 the function checkList return True)
            Node* newNode = new Node(data); //se crea el nodo en la lista, por eso se llama a la funcion nodo, el nodo que se creo se llama newNode
            newNode->next = head;//ahorita el nodo no esta conectado a nada, por eso uno lo que hace es decirle que lo que le sigue va a ser la cabeza de antes, por que ahi iniciaba la lista
            head = newNode; //ahora como el nuevo nodo va a ser la cabeza por eso le digo que head es newnode, por que ahora la lista parte de ahi
            cout << newNode->getData() << " cheking the data of newNode \n";
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
                cout << temp->data << " -> ";
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