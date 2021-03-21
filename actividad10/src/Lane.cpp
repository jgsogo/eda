
#include "Lane.h"

Lane::Lane() {}

int Lane::size() const {
    auto iterator = _front;
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool Lane::empty() const {
    return this->size() == 0;
}

Client& Lane::front() const {
    return _front->client;
}

Client& Lane::back() const {
    return _back->client;
}

void Lane::push(const Client& dato) {
    auto elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if (_front == nullptr) {
        _front = _back = elem;
    }
    else {
        _back->next = elem;
        _back = elem;
    }
}

void Lane::pop() {
    _front = _front->next;
    if (_front == nullptr) {
        _back = nullptr;
    }
}
