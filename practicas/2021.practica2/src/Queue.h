#pragma once

#include "ElementoListaDoble.h"

class Queue {
    public:
        Queue();

        int size() const;
        bool empty() const;

        Persona& front() const;
        Persona& back() const;

        void push(const Persona& dato);
        void pop();

        // This function adds the queue of 'friends' after the 'contact' (if found)
        void sneak_in(const Persona& contact, Queue& friends);

    protected:
        std::shared_ptr<ElementListaDoble> _front = nullptr;
        std::shared_ptr<ElementListaDoble> _back = nullptr;
};
