#pragma once

#include <memory>
#include <array>
#include <vector>
#include <queue>

namespace {
    struct Edge {
        int origin, target;
        int weigth;

        bool operator<(const Edge& other) const {
            return weigth > other.weigth;
        }
    };
}

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

        std::vector<int> adjacents(int node) const {
            std::vector<int> ret;
            for (int i = 0; i < N; i++) {
                if(edges[node][i] != nullptr) {
                    ret.push_back(i);
                }
            }
            return ret;
        }

        std::array<bool, N> component(int node) const {
            std::array<bool, N> visited;
            for (int i=0; i<N; i++) { visited[i] = false; }

            // Use BFS with an auxliary queue
            std::queue<int> queue;
            queue.push(node);
            while (!queue.empty()) {
                int node = queue.front(); queue.pop();
                if (!visited[node]) {
                    visited[node] = true;
                    for (int i=0; i<N; i++) {
                        if (edges[node][i]) { // may exclude those already visited
                            queue.push(i);
                        }
                    }
                }
            }
            return visited;
        }

        bool are_connected(std::string city1, std::string city2) const {
            // Search the cities
            int node1 = -1, node2 = -1;
            for (int i=0; i<N; i++) {
                if (nodes[i] != nullptr) {
                    if (*nodes[i] == city1) {
                        node1 = i;
                    }
                    if (*nodes[i] == city2) {
                        node2 = i;
                    }
                }
            }

            if (node1 == -1 || node2 == -1) {
                return false;
            }

            // Check if the belong to the same component
            std::array<bool, N> cmp = component(node1);
            return cmp[node2]; // If it belongs to the same component, they are connected
        }

        int num_components() const {
            // How many nodes do we need to start with in order to visit all the nodes in the graph
            std::array<bool, N> visited;
            for (int i=0; i<N; i++) { visited[i] = false; }

            int beginnings = 0;
            while(!std::all_of(visited.begin(), visited.end(), [](bool item){return item;})) {
                auto it = std::find(visited.begin(), visited.end(), false);
                int idx = std::distance(visited.begin(), it);
                
                auto cmp = component(idx);
                for (int i=0; i<N; i++) {
                    visited[i] = visited[i] || cmp[i];
                }
                beginnings++;
            }
            return beginnings;
        }

        Graph<N> telephone() const {
            // Use Prim o Kruskal to compute the MST
            std::priority_queue<Edge> queue;
            for (int i=0; i<N; i++) {
                for (int j=i; j<N; j++) {
                    if (edges[i][j] != nullptr) {
                        queue.push(Edge{i, j, *edges[i][j]});
                    }
                }
            }

            // The forest
            std::array<int, N> forest_tree;
            for (int i=0; i<N; i++) {
                forest_tree[i] = i;
            }

            // Create the MST with the information
            Graph<N> ret;

            while (!queue.empty()) {
                auto edge = queue.top(); queue.pop();
                if (forest_tree[edge.origin] != forest_tree[edge.target]) {
                    std::cout << edge.origin << " -> " << edge.target << std::endl;
                    ret.add_node(edge.origin, *nodes[edge.origin]);
                    ret.add_node(edge.target, *nodes[edge.target]);
                    ret.add_edge(edge.origin, edge.target, edge.weigth);
                    int origin_tree = forest_tree[edge.origin];
                    int target_tree = forest_tree[edge.target];
                    for (int i=0; i<N; i++) {
                        if (forest_tree[i] == target_tree) {
                            forest_tree[i] = origin_tree;
                        }
                        //std::cout << i << ": " << forest_tree[i] << std::endl;
                    }
                }
            }
            return ret;
        }
        
        int sum_kilometers() const {
            // Sum of all the distances between all the nodes
            int kms = 0;
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    if (edges[i][j] != nullptr) {
                        kms += *edges[i][j];
                    }
                }
            }
            return kms;
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

