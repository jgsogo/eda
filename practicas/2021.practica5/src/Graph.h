#pragma once

#include <memory>
#include <array>


template <int N>
class Graph {
    public:
        Graph() {
            for (int i=0; i<N; i++) {
                nodes[i] = nullptr;
                for (int j=0; j<N; j++) {
                    edges[i][j] = nullptr;
                }
            }
        }

        void add_node(int node, const std::string& city) {
            nodes[node] = std::make_shared<std::string>(city);
        }

        bool add_edge(int origin, int target, int distance) {
            if (nodes[origin] == nullptr || nodes[target] == nullptr) {
                return false;
            }
            edges[origin][target] = std::make_shared<int>(distance);
            edges[target][origin] = std::make_shared<int>(distance);
            return true;
        }

        template <int SIZE>
        friend std::ostream& operator<<(std::ostream& os, const Graph<SIZE>& graph);

    protected:
        std::array<std::shared_ptr<std::string>, N> nodes;
        std::array<std::array<std::shared_ptr<int>, N>, N> edges;

};


/* Overload output stream operator */
template <int N>
std::ostream& operator<<(std::ostream& os, const Graph<N>& graph) {
    os << "      ";
    for (int i = 0; i < N; i++) {
        os << " " << std::right << std::setw(4) << i;
    }
    os << std::endl;

    for (int i = 0; i < N; i++) {
        os << std::right << std::setw(4) << i << " |";
        for (int j = 0; j < N; j++) {
            if (graph.edges[i][j] != nullptr) {
                os << " " << std::right << std::setw(4) << *graph.edges[i][j];
            }
            else {
                os << "     ";
            }
        }
        os << std::endl;
    }
    return os;
}

