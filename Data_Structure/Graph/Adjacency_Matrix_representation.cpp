#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    // Constructor to initialize graph with n vertices
    Graph(int n) {
        numVertices = n;
        adjMatrix.resize(n, vector<int>(n, 0)); // Initialize matrix with 0s
    }

    // Add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // If undirected graph
    }

    // Print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
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

    cout << "Adjacency Matrix representation of the graph:" << endl;
    g.printGraph();

    return 0;
}
