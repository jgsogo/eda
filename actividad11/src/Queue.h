#pragma once

#include "ElementoArbol.h"

using QueueTipoDato = std::shared_ptr<ElementoArbol>;


class ElementoListaSimple {
    public:
        QueueTipoDato dato;
        std::shared_ptr<ElementoListaSimple> next = nullptr;

    public:
        ElementoListaSimple(const QueueTipoDato& dato) : dato(dato) {};
};


class Queue {
    public:
        Queue();

        int size() const;
        bool empty() const;

        QueueTipoDato& front() const;
        QueueTipoDato& back() const;

        void push(const QueueTipoDato& dato);
        void pop();
    protected:
        std::shared_ptr<ElementoListaSimple> _front = nullptr;
        std::shared_ptr<ElementoListaSimple> _back = nullptr;
    };
