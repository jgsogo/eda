#include <iostream>

#include "src/Queue.h"
#include "src/Wardrobe.h"

int main() {
    // Create the queue for the disco
    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(Persona{"Manuel", "dni-manuel", 0});
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    joy_eslava.push(Persona{"Miguel", "dni-miguel", 0});
    joy_eslava.push(Persona{"Samuel", "dni-samuel", 0});
    joy_eslava.push(Persona{"Raquel", "dni-raquel", 1});

    Wardrobe men;
    Wardrobe women;
    wardrobe(joy_eslava, men, women);

    std::cout << "Wardrobe men:" << std::endl;
    while (!men.empty()) {
        std::cout << men.top() << std::endl;
        men.pop();
    }

    std::cout << "Wardrobe women:" << std::endl;
    while (!women.empty()) {
        std::cout << women.top() << std::endl;
        women.pop();
    }
}
