#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    vector<list<int>> adjList;
    int numVertices;

public:
    // Constructor to initialize graph with n vertices
    Graph(int n) {
        numVertices = n;
        adjList.resize(n);  // Create an array of lists
    }

    // Add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // If undirected graph
    }

    // Print the adjacency list
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (auto v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    cout << "Adjacency List representation of the graph:" << endl;
    g.printGraph();

    return 0;
}
