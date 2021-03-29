#include "Queue.h"
#include "iostream"

Queue::Queue()
{
}

int Queue::size() const{
    auto iterator = _front;
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool Queue::empty() const{
    return this->size() == 0;
}

Persona& Queue::front() const{
    return _front->dato;
}

Persona& Queue::back() const{
    return _back->dato;
}

//añado por el final
void Queue::push(const Persona& dato){
    auto elem = std::make_shared<ElementListaDoble>(ElementListaDoble{dato});
    if (_front == nullptr) {
        _front = _back = elem;
    }
    else {
        _back->next = elem;
        elem->prev = _back;
        _back = elem;
    }
}

//elimino por el principio
void Queue::pop(){
    _front = _front->next;
    if (_front == nullptr) {
        _back = nullptr;
    }else{
        _front->prev = nullptr;
    }
}

// This function adds the queue of 'friends' after the 'contact' (if found)
void Queue::sneak_in(const Persona& contact, Queue& friends){
    if(!this->empty()){
        bool found = false;
        std::shared_ptr<ElementListaDoble> contacto = _front;
        while(contacto != nullptr && found == false){
            if(contacto->dato.operator==(contact)){
                found = true;
                auto aux = contacto->next;
                contacto->next = friends._front;
                friends._front->prev = contacto;
                if(aux != nullptr){
                    friends._back->next = aux;
                    aux->prev = friends._back;
                }else{
                    _back = friends._back;
                }
            }
            contacto = contacto->next;
        }
    }
}


