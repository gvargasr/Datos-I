#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

typedef pair<string, int> psi;  // Pair representing (vertex, weight)

class Graph {
public:
    unordered_map<string, vector<psi>> adjList;  // Adjacency list

    void addEdge(const string& u, const string& v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));  // Assuming an undirected graph
    }

    void dijkstra(const string& start, const string& filename) {
        priority_queue<psi, vector<psi>, greater<psi>> pq;  // Min heap
        unordered_map<string, int> distance;

        for (const auto& pair : adjList) {
            distance[pair.first] = INT_MAX;
        }

        pq.push(make_pair(start, 0));
        distance[start] = 0;

        ofstream outFile(filename);

        while (!pq.empty()) {
            string u = pq.top().first;
            int distU = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjList[u]) {
                string v = neighbor.first;
                int weight = neighbor.second;

                if (distU + weight < distance[v]) {
                    distance[v] = distU + weight;
                    pq.push(make_pair(v, distance[v]));

                    // Store the information in the file
                    outFile << u << " " << v << " " << weight << " " << distance[v] << endl;
                }
            }
        }

        outFile.close();
    }
};

int main() {
    Graph graph;

    // Add edges with string, string, int format
    graph.addEdge("A", "B", 2);
    graph.addEdge("A", "C", 4);
    graph.addEdge("B", "C", 1);
    graph.addEdge("B", "D", 7);
    graph.addEdge("C", "E", 3);
    graph.addEdge("D", "F", 1);
    graph.addEdge("E", "D", 2);
    graph.addEdge("E", "F", 5);

    string startNode = "A";  // Change the starting node as needed
    string filename = "dijkstra_table.txt";

    graph.dijkstra(startNode, filename);

    cout << "Dijkstra's algorithm completed. Table stored in " << filename << endl;

    return 0;
}

