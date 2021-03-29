#include "NameCounter.h"
#include <iostream>

ElementListaSimple::ElementListaSimple(const NameCount& dato_) : dato{dato_}
{
}

NameCounter::NameCounter()
{
}

int NameCounter::size() const {
    std::shared_ptr<ElementListaSimple> iterator = front; // first element
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

NameCount& NameCounter::at(int pos) const{
    std::shared_ptr<ElementListaSimple> iterator = front;
    int idx = 0;
    while (iterator != nullptr) {
        if (idx == pos) {
            break;
        }
        iterator = iterator->next;
        idx++;
    }
    return iterator->dato;
}

void NameCounter::push_back(const NameCount& dato){
    std::shared_ptr<ElementListaSimple> elem = std::make_shared<ElementListaSimple>(ElementListaSimple{dato});
    if (front == nullptr) {
        front = elem;
    }
    else {
        std::shared_ptr<ElementListaSimple> iterator = front;
        while (iterator->next != nullptr) {
            iterator = iterator->next;
        }
        iterator->next = elem;
    }
}

void NameCounter::add_name(const std::string& name){
    bool found = false;
    std::shared_ptr<ElementListaSimple> iterator = front;
    while (iterator != nullptr) {
        if(iterator->dato.name == name){
            found = true;
            iterator->dato.repeats++;
        }
        iterator = iterator->next;
    }

    if(found == false){
        NameCount new_name;
        new_name.name = name;
        new_name.repeats = 1;

        push_back(new_name);
    }
}

void NameCounter::sort(){
    for (int i=0; i<this->size()-1; i++) {
      bool any_swap = false;
      for (int k=0; k<this->size()-1-i; k++) {
        if (this->at(k).repeats < this->at(k+1).repeats) {
          std::swap(this->at(k),this->at(k+1));
          any_swap = true;
        }
      }
      if (!any_swap) { break;}
    }
}

void NameCounter::for_each(std::function<void (const NameCount&)> action) const{
    std::shared_ptr<ElementListaSimple> iterator = front;
    while (iterator != nullptr) {
        action(iterator->dato);
        iterator = iterator->next;
    }
}

NameCounter count_names(Queue& joy_slava){
    Queue aux = joy_slava;
    NameCounter list;
    while(!aux.empty()){
        list.add_name(aux.front().get_name());
        aux.pop();
    }

    return list;
}
