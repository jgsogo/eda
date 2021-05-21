#include <iostream>
#include <fstream>
#include "src/Graph.h"

int main() {
    // Path to the files with the information
    std::string cities{"../Ciudades.txt"};
    std::string distances{"../Distancias.txt"};
    std::string distances2{"../Distancias++.txt"};

    // Build the graph using the information from the files
    Graph<23> graph;

    // - read cities
    std::string line;
    std::ifstream citiesFile{cities};
    if (!citiesFile.is_open()) {
        return -1;
    }
    while (std::getline(citiesFile, line)) {
        int found = line.find(' ');
        int node = std::stoi(line.substr(0, found));
        std::string city = line.substr(found+1);
        graph.add_node(node, city);
    }

    // - read distances
    std::ifstream distancesFile{distances};
    if (!distancesFile.is_open()) {
        return -1;
    }
    while (std::getline(distancesFile, line)) {
        int found1 = line.find(' ');
        int found2 = line.find(' ', found1 + 1);
        int origin = std::stoi(line.substr(0, found1));
        int target = std::stoi(line.substr(found1 + 1, found2));
        int distance = std::stoi(line.substr(found2 + 1));
        graph.add_edge(origin, target, distance);
    }

    // Override operator<< for your class
    std::cout << graph << std::endl;

    // Check if connected
    std::cout << "Cádiz - Ceuta: " << graph.are_connected("Cádiz", "Ceuta") << std::endl;
    std::cout << "Madrid - Valencia: " << graph.are_connected("Madrid", "Valencia") << std::endl;

    // Num components
    std::cout << "N. components: " << graph.num_components() << std::endl;

    // Read extra connections
    std::ifstream distancesFile2{distances2};
    if (!distancesFile2.is_open()) {
        return -1;
    }
    while (std::getline(distancesFile2, line)) {
        int found1 = line.find(' ');
        int found2 = line.find(' ', found1 + 1);
        int origin = std::stoi(line.substr(0, found1));
        int target = std::stoi(line.substr(found1 + 1, found2));
        int distance = std::stoi(line.substr(found2 + 1));
        graph.add_edge(origin, target, distance);
    }

    // Num components
    std::cout << "N. components: " << graph.num_components() << std::endl;

    // Telephone
    auto telephone = graph.telephone();
    std::cout << "Total length: " << graph.sum_kilometers() << std::endl;
    std::cout << "MST length: " << telephone.sum_kilometers() << std::endl;
    std::cout << telephone << std::endl;
}
