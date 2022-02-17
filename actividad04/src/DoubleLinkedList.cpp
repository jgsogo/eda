#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{

}
void DoubleLinkedList::for_each(std::function<void (TipoDato&)> action) const{
    // Iterate the list as usual
    std::shared_ptr<ElementoListaDoble> iterator = front;
    while (iterator != nullptr) {
        action(iterator->datos); // Call the action
        iterator = iterator->next;
    }
}

void DoubleLinkedList::for_each_reverse(std::function<void (TipoDato&)> action) const{
    std::shared_ptr<ElementoListaDoble> iterator = back;
    while (iterator != nullptr) {
        action(iterator->datos); // Call the action
        iterator = iterator->prev;
    }
}

int DoubleLinkedList::size() const{
    std::shared_ptr<ElementoListaDoble> iterator = front; // first element
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}
bool DoubleLinkedList::empty() const{
    return (front == nullptr && back == nullptr);
}

void DoubleLinkedList::push_back(const TipoDato& dato){
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (front == nullptr) {
        front = back = elem;
    }
    else {
        back->next = elem;
        elem->prev = back;
        back = elem;
    }
}

void DoubleLinkedList::push_front(const TipoDato& dato){
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (front == nullptr) {
        front = back = elem;
    }
    else {
        front->prev = elem;
        elem->next = front;
        front = elem;
    }
}

