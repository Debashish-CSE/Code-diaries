#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int V, E; //v = number of vertices, E = number of edges

public:
    // Constructor to initialize graph with n vertices
    Graph(int n) {
        V = n;
        adjList.resize(n);
        E = 0;
    }

    // Add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // If undirected graph
        E++;
    }

    // Check if the graph is planar based on the condition E <= 3V - 6
    bool isPlanar() {
        if (E > 3*V - 6) {
            return false;
        }
        return true;
    }

    // Print the graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges (this creates a planar graph)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    // Check if the graph is planar
    if (g.isPlanar()) {
        cout << "The graph is planar" << endl;
    } else {
        cout << "The graph is not planar" << endl;
    }

    return 0;
}
