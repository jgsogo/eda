#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {}

// Iterate forward
void DoubleLinkedList::for_each(std::function<void (TipoDato&)> action) const {
    auto iterator = front;
    while (iterator != nullptr) {
        action(iterator->datos);
        iterator = iterator->next;
    }
}

// Iterate backward
void DoubleLinkedList::for_each_reverse(std::function<void (TipoDato&)> action) const {
    auto iterator = back;
    while (iterator != nullptr) {
        action(iterator->datos);
        iterator = iterator->prev;
    }
}

// Size-related methods
int DoubleLinkedList::size() const {
    auto iterator = front;
    int idx = 0;
    while (iterator != nullptr) {
        idx++;
        iterator = iterator->next;
    }
    return idx;
}

bool DoubleLinkedList::empty() const {
    return this->size() == 0;
}

// Insertion
void DoubleLinkedList::push_back(const TipoDato& dato) {
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (this->empty()) {
        back = front = elem;
    }
    else {
        back->next = elem;
        elem->prev = back;
        back = elem;
    }
}

void DoubleLinkedList::push_front(const TipoDato& dato) {
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (this->empty()) {
        back = front = elem;
    }
    else {
        elem->next = front;
        front->prev = elem;
        front = elem;
    }
}