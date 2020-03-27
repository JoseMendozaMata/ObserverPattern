//
// Created by jose on 27/3/20.
//

#ifndef OBSERVERPATTERN_SUBSERVICE_H
#define OBSERVERPATTERN_SUBSERVICE_H

#include <string>
#include "../DataStructures/SubsLinkedList.h"

using namespace std;

//Subservice actúa como el artista, que tiene una lista de subscriptores y sube un link para acceder al contenido
class SubService {

    private:
        SubsLinkedList subscribers;
        string state;       //link de notificación

    public:

        string getstate(){
            return state;
        }

        void setState(string state){
            this->state = state;
            notifySubscribers();
        }

        void addSubscriber(string sub){
            subscribers.Add(sub);
        }

        void notifySubscribers(){
            subscribers.notify(this->state);
            cout << "=====================================================================================" << endl;
        }

};


#endif //OBSERVERPATTERN_SUBSERVICE_H
