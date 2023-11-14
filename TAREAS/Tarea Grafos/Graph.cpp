#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adjacency_list;

    void add_edge(string source, string destination, int cost) {
        // Adding the edge from source to destination with the given cost
        adjacency_list[source].push_back(std::make_pair(destination, cost));

        // Adding the edge from destination to source with the same cost (assuming undirected graph)
        adjacency_list[destination].push_back(make_pair(source, cost));
    }

    void display() {
        for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
            std::cout << it->first << ": ";
            for (auto edge = it->second.begin(); edge != it->second.end(); ++edge) {
                std::cout << "(" << edge->first << ", " << edge->second << ") ";
            }
            std::cout << std::endl;
        }
    }
    
};

int main() {
    Graph graph;

    graph.add_edge("A", "B", 5);
    graph.add_edge("B", "C", 3);
    graph.add_edge("C", "D", 7);
    graph.add_edge("D", "A", 2);

    graph.display();

    return 0;
}

