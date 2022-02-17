#include "Wardrobe.h"

WardrobeElement::WardrobeElement(const std::string& owner) : owner{owner} {
}


Wardrobe::Wardrobe() {}

int Wardrobe::size() const {
    auto iterator = front;
    int idx = 0;
    while (iterator != nullptr) {
        idx++;
        iterator = iterator->next;
    }
    return idx;
}

bool Wardrobe::empty() const {
    return this->size() == 0;
}

void Wardrobe::push(const std::string& dato) {
    auto elem = std::make_shared<WardrobeElement>(WardrobeElement{dato});
    if (this->empty()) {
        front = elem;
    }
    else {
        elem->next = front;
        front = elem;
    }
}

void Wardrobe::pop() {
    front = front->next;
}

std::string& Wardrobe::top() const {
    return front->owner;
}


void wardrobe(Queue& joy_slava, Wardrobe& men, Wardrobe& women) {
    while (!joy_slava.empty()) {
        auto elem = joy_slava.front();
        joy_slava.pop();
        if (elem.get_gender() == 1) {
            women.push(elem.get_name());
        }
        else if (elem.get_gender() == 0) {
            men.push(elem.get_name());
        }
    }
}
