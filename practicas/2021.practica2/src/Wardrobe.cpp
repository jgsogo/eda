#include "Wardrobe.h"
#include <iostream>

WardrobeElement::WardrobeElement(const std::string& owner):owner{owner}
{
}

Wardrobe::Wardrobe()
{
}

int Wardrobe::size() const{
    auto iterator = front;
    int idx = 0;
    while (iterator != nullptr) {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}
bool Wardrobe::empty() const{
    return (front == nullptr);
}

void Wardrobe::push(const std::string& dato){
    auto elem = std::make_shared<WardrobeElement>(WardrobeElement{dato});
    if (front != nullptr) {
        elem->next = front;
        front = elem;
    }
    else {
        front = elem;
    }
}

void Wardrobe::pop(){
    if (front != nullptr) {
       front = front->next;
    }
}

std::string& Wardrobe::top() const{
     return front->owner;
}

void wardrobe(Queue& joy_slava, Wardrobe& men, Wardrobe& women){
    while(! joy_slava.empty()){
       if(joy_slava.front().get_gender() == 1){
           women.push(joy_slava.front().get_name());
       }else{
           men.push(joy_slava.front().get_name());
       }
       joy_slava.pop();
    }
}
