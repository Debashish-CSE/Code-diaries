#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int numVertices;

public:
    // Constructor to initialize graph with n vertices
    Graph(int n) {
        numVertices = n;
        adjList.resize(n);
    }

    // Add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // If undirected graph
    }

    // Perform BFS starting from vertex s
    void bfs(int s) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
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

    cout << "BFS starting from vertex 0: ";
    g.bfs(0);  // Perform BFS starting from vertex 0
    cout << endl;

    return 0;
}
