//
// Created by jose on 27/3/20.
//

#ifndef OBSERVERPATTERN_SUBSLINKEDLIST_H
#define OBSERVERPATTERN_SUBSLINKEDLIST_H


//
// Created by jose on 29/2/20.
//

//
// Created by jose on 28/2/20.}
//Clases en C++
//

#include <stdio.h>;
#include <iostream>
#include "../Client/ClientNode.h"

using namespace std;

class SubsLinkedList {

private:
    ClientNode *first;
    ClientNode *last;

public:
    SubsLinkedList(){
        first = NULL;
        last = NULL;
    }
    void Add(string valor){

        ClientNode *newNode = new ClientNode(valor);   // Asigno un puntero que me lleve al nuevo nodo

        if(first == nullptr){      // Si la cabeza es nula, asigno el nuevo nodo como cabeza

            first = newNode;
            last = newNode;

        } else {        // Sino, recoro los nodos hasta encontrar uno que sea nulo
            ClientNode *temp = first;

            while(temp->getNext()){     // OJO: El next no puede ser nulo

                temp = temp->getNext();     // Obtengo la dir de mem del siguiente nodo
            }

            temp->setNext(newNode);

            last = newNode;

        }
    }

    //Me encuentra la direccion de memoria de un sub por su userName

    ClientNode* findVertexByValue(string _value){

        ClientNode *temp = first;

        while(temp->getUserName() != _value){
            temp = temp->getNext();
        }

        return temp;
    }

    string getFirst(){

        return first->getUserName();

    }

    string getLast(){
        return last->getUserName();
    }

    // Notifica a los subscriptores con un link
    void notify(string notification){

        ClientNode *temp = first;

        while(temp != NULL){
            temp->setRecentNotifiction(notification);
            temp = temp->getNext();
        }

    }

};



#endif //OBSERVERPATTERN_SUBSLINKEDLIST_H
