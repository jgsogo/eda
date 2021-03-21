#pragma once

#include <cstdlib>

class Client {
    public:
        Client() {
            time_to_pay = 0;
        }

        Client(int min_time, int max_time) {
            // Time it takes for the client to pay
            time_to_pay = min_time + (std::rand() % (max_time - min_time));
        }

    public:
        int time_to_pay;
};
