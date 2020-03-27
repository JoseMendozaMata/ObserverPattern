//
// Created by jose on 27/3/20.
//

#ifndef OBSERVERPATTERN_CLIENTNODE_H
#define OBSERVERPATTERN_CLIENTNODE_H

#include <string>
#include <iostream>

using namespace std;

//Clase que sera el nodo componente de la clase Cliente
class ClientNode {

private:
    string userName;
    string recentNotification;
    ClientNode *next;

public:

    ClientNode(string _value){
        userName = _value;
        next = NULL;
    };

    string getUserName(){     // Devuelvo el valor del nodo
        return userName;
    }

    string getRecentNotification(){
        return recentNotification;
    }

    void setRecentNotifiction(string notification){
        this->recentNotification = notification;
        cout << this->getUserName() << ":Nueva notificación: " << this->getRecentNotification() << endl;
    }

    ClientNode* getNext(){        //Devuelvo la direccion de memoria del nodo siguiente
        return next;
    }

    void setNext(ClientNode* _next){      // Le paso la direccion de memoria del nodo siguiente
        next = _next;
    }

};  // Ojo el punto y coma al final de la llave



#endif //OBSERVERPATTERN_CLIENTNODE_H
