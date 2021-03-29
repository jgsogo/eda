#include "Police.h"

Queue police_raid(Queue joy_slava, const std::vector<std::string>& dnis){
    Queue new_joy_slava;
    bool found;

    while (!joy_slava.empty()) {
        found = false;
        for(unsigned int i = 0; i < dnis.size(); i++){
            if(joy_slava.front().get_dni() == dnis.at(i)){
               found = true;
            }
        }
        if(found == false){
            new_joy_slava.push(joy_slava.front());
        }
        joy_slava.pop();
    }

    return new_joy_slava;
}

