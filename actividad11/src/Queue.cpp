
#include "Queue.h"

Queue::Queue() {}

int Queue::size() const {
    auto iterator = _front;
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool Queue::empty() const {
    return this->size() == 0;
}

QueueTipoDato& Queue::front() const {
    return _front->dato;
}

QueueTipoDato& Queue::back() const {
    return _back->dato;
}

void Queue::push(const QueueTipoDato& dato) {
    auto elem = std::make_shared<ElementoListaSimple>(QueueTipoDato{dato});
    if (_front == nullptr) {
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
        _back = nullptr;
    }
}
