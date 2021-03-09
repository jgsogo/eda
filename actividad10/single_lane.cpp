
#include <array>
#include <fstream>
#include <iostream>

#include "src/Lane.h"

int main() {
    std::ofstream data;
    data.open("output.txt");

    // Parameters
    int min_time_to_pay = 40;
    int max_time_to_pay = 200;
    int time_between_clients = 25;
    std::array<Client, 4> lanes;

    Lane clients;
    int seconds = 0;
    int total_clients = 0;
    while (seconds < 10000) {
        // Add a new client every 'time_between_clients' seconds
        if (seconds % time_between_clients == 0) {
            clients.push(Client{min_time_to_pay, max_time_to_pay});
            total_clients++;
        }

        // Simulate clients paying at the lanes
        for (int i=0; i<lanes.size(); i++) {
            lanes[i].time_to_pay--;
            if (lanes[i].time_to_pay <= 0) {
                // Take next client from the queue
                if (!clients.empty()) {
                    auto front_client = clients.front();
                    clients.pop();
                    lanes[i] = front_client;
                }
            }
        }

        // Save to file
        data << seconds << "," << clients.size() << "\n";

        seconds += 1; // next timestep
    }
    data.close();
    std::cout << "Total clients: " << total_clients << std::endl;
    return 0;
}
