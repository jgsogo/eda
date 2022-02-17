
#include "Stack.h"

Stack::Stack() {}

void Stack::push(const TipoDato& datos) {
    auto elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{datos});
    elem->next = front;
    front = elem;
}

void Stack::pop() {
    front = front->next;
}

TipoDato& Stack::top() const {
    return front->datos;
}

int Stack::size() const {
    auto iterator = front;
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}
