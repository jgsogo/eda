#include "NameCounter.h"

ElementListaSimple::ElementListaSimple(const NameCount& dato_) : dato{dato_} {

}


NameCounter::NameCounter() {}

void NameCounter::add_name(const std::string& name) {
    auto iterator = front;
    while (iterator != nullptr) {
        if (iterator->dato.name == name) {
            iterator->dato.repeats = iterator->dato.repeats + 1;
            return;
        }
        iterator = iterator->next;
    }

    // First time this name, insert
    auto elem = std::make_shared<ElementListaSimple>(ElementListaSimple{NameCount{1, name}});
    if (front == nullptr) {
        front = elem;
    }
    else {
        elem->next = front;
        front = elem;
    }
}

void NameCounter::sort() {

}

void NameCounter::for_each(std::function<void (const NameCount&)> action) const {
    auto iterator = front;
    while (iterator != nullptr) {
        action(iterator->dato);
        iterator = iterator->next;
    }
}


NameCounter count_names(Queue& joy_slava) {
    NameCounter name_counter;
    while (!joy_slava.empty()) {
        auto person = joy_slava.front();
        joy_slava.pop();
        name_counter.add_name(person.get_name());
    }
    return name_counter;
}
