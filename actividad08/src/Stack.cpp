#include "Stack.h"

Stack::Stack()
{

}

void Stack::push(const TipoDato &dato){
    auto elem = make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front != nullptr){elem->next = front;  front = elem;}
    else{front = elem;}
}

void Stack::pop(){
    if(front != nullptr){front = front -> next;}
}

TipoDato &Stack::top() const{return front -> datos;}

int Stack::size() const{
    auto iterator = front;  int idx = 0;
    while(iterator != nullptr){iterator = iterator->next;  idx++;}
    return idx;
}
