#include "Queue.h"

Queue::Queue() {}

int Queue::size() const {
    auto iterator = _front;
    int idx = 0;
    while (iterator != nullptr) {
        idx++;
        iterator = iterator->next;
    }
    return idx;
}

bool Queue::empty() const {
    return this->size() == 0;
}

Persona& Queue::front() const {
    return _front->dato;
}

Persona& Queue::back() const {
    return _back->dato;
}

void Queue::push(const Persona& dato) {
    auto elem = std::make_shared<ElementListaDoble>(ElementListaDoble{dato});
    if (this->empty()) {
        _front = _back = elem;
    }
    else {
        _back->next = elem;
        _back = elem;
    }
}

void Queue::pop() {
    _front = _front->next;
    if (_front == nullptr) {
        _back = _front;
    }
}

// This function adds the queue of 'friends' after the 'contact' (if found)
void Queue::sneak_in(const Persona& contact, Queue& friends) {
    auto iterator = _front;
    while (iterator != nullptr) {
        if (iterator->dato == contact) {
            auto sneaker = iterator;
            auto next_elem = sneaker->next;
            while (!friends.empty()) {
                auto next_friend = friends.front();
                friends.pop();
                sneaker->next = std::make_shared<ElementListaDoble>(ElementListaDoble{next_friend});
                sneaker = sneaker->next;
            }
            sneaker->next = next_elem;
            break;
        }
        iterator = iterator->next;
    }
    
}