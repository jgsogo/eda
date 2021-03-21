
#include <iostream>
#include "src/Queue.h"

int main() {
    // Manuel is going today to Joy Slava, he is waiting for some friends
    Persona manuel{"Manuel", "dni-manuel", 0};

    // Create the queue for the disco
    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(manuel);
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    // ...

    // Create the queue with Manuel's friends
    Queue friends;
    friends.push(Persona{"Miguel", "dni-miguel", 0});
    friends.push(Persona{"Samuel", "dni-samuel", 0});
    friends.push(Persona{"Raquel", "dni-raquel", 1});

    // Sneak in
    joy_eslava.sneak_in(manuel, friends);

    // Check the queue is the expected one: print size and names
    std::cout << "Joy Slava, people waiting: " << joy_eslava.size() << std::endl;
    while (!joy_eslava.empty()) {
        auto person = joy_eslava.front();
        joy_eslava.pop();
        std::cout << person.get_name() << std::endl;
    }
}
