
#include <array>
#include <fstream>
#include <iostream>

#include "src/Lane.h"

void add_new_client(std::array<Lane, 4>& lanes, int min_time_to_pay, int max_time_to_pay) {
    // Creates a new client and add it to the shortest queue
    Client client{min_time_to_pay, max_time_to_pay};
    int shortest_idx = 0;
    for (int i=0; i<lanes.size(); i++) {
        if (lanes[i].size() < lanes[shortest_idx].size()) {
            shortest_idx = i;
        }
    }
    // Push client to the shortest queue
    lanes[shortest_idx].push(client);
}

int main() {
    std::ofstream data;
    data.open("output.txt");

    // Parameters
    int min_time_to_pay = 40;
    int max_time_to_pay = 200;
    int time_between_clients = 25;
    std::array<Lane, 4> lanes;

    int seconds = 0;
    int total_clients = 0;
    while (seconds < 10000) {
        // Add a new client every 'time_between_clients' seconds
        if (seconds % time_between_clients == 0) {
            add_new_client(lanes, min_time_to_pay, max_time_to_pay);
            total_clients++;
        }

        // Simulate clients paying at the lanes
        for (auto& lane: lanes) {  // Note the '&'
            if (!lane.empty()) {
                auto& front_client = lane.front(); // Note the '&'
                front_client.time_to_pay--;
                if (front_client.time_to_pay <= 0) {
                    lane.pop();
                }
            }
        }

        // Save to file
        int total = 0;
        data << seconds << ",";
        for (auto lane: lanes) {
            data << lane.size() << ",";
            total += lane.size();
        }
        data << total << "\n";

        seconds += 1; // next timestep
    }
    data.close();
    std::cout << "Total clients: " << total_clients << std::endl;
    return 0;
}
