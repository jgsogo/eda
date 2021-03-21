#include <iostream>

#include "src/Queue.h"
#include "src/Police.h"

int main() {
    // Create the queue for the disco
    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(Persona{"Manuel", "dni-manuel", 0});
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    joy_eslava.push(Persona{"Miguel", "dni-miguel", 0});
    joy_eslava.push(Persona{"Samuel", "dni-samuel", 0});
    joy_eslava.push(Persona{"Raquel", "dni-raquel", 1});

    std::vector<std::string> dnis{"dni-manuel", "dni-raquel", "dni-isabel"};
    auto filtered = police_raid(joy_eslava, dnis);

    std::cout << "Joy Slava, people waiting: " << filtered.size() << std::endl;
    while (!filtered.empty()) {
        auto person = filtered.front();
        filtered.pop();
        std::cout << person.get_name() << std::endl;
    }
}
