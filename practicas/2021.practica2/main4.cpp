#include <iostream>

#include "src/Queue.h"
#include "src/NameCounter.h"

int main() {
    // Create the queue for the disco
    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(Persona{"Manuel", "dni-manuel", 0});
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    joy_eslava.push(Persona{"Leticia", "dni-leticia2", 1});
    joy_eslava.push(Persona{"Samuel", "dni-samuel", 0});
    joy_eslava.push(Persona{"Raquel", "dni-raquel", 1});

    auto name_counter = count_names(joy_eslava);
    name_counter.for_each([](const NameCount& name_count) {
        std::cout << name_count.repeats << ": " << name_count.name << std::endl;
    });

}
