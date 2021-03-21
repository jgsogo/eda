#pragma once

#include "Client.h"
#include "ElementoListaSimple.h"

class Lane {
    public:
        Lane();

        int size() const;
        bool empty() const;

        Client& front() const;
        Client& back() const;

        void push(const Client& dato);
        void pop();
    protected:
        std::shared_ptr<ElementoListaSimple> _front = nullptr;
        std::shared_ptr<ElementoListaSimple> _back = nullptr;
    };
