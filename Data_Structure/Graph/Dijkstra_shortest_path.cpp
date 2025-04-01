#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;  // Adjacency list to store (neighbor, weight) pairs
    int numVertices;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(n);
    }

    // Add an edge from vertex u to vertex v with weight w
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});  // Add v with weight w to u's list
        adjList[v].push_back({u, w});  // If the graph is undirected
    }

    
    // Dijkstra's Algorithm to find the shortest path from source s
    void dijkstra(int source) {
        vector<int> dist(numVertices, INT_MAX);  // Distance vector initialized to infinity
        dist[source] = 0;  // Distance from source to itself is 0

        // Min-heap priority queue to get the vertex with the smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Push the source vertex with distance 0
        pq.push({0, source});

        while (!pq.empty()) {
            // Get the vertex with the minimum distance
            int u = pq.top().second;
            int uDist = pq.top().first;
            pq.pop();

            // If the current distance is greater than the known shortest distance, skip it
            if (uDist > dist[u]) continue;

            // Explore all neighbors of the current vertex
            for (auto neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relax the edge
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});  // Push the updated distance and vertex into the priority queue
                }
            }
        }

        // Print the shortest distances from the source
        cout << "Shortest distances from vertex " << source << " are:\n";
        for (int i = 0; i < numVertices; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Vertex " << i << " is unreachable\n";
            } else {
                cout << "Vertex " << i << ": " << dist[i] << endl;
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Adding edges (u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);
    g.addEdge(3, 5, 7);

    // Find the shortest paths from vertex 0
    g.dijkstra(0);

    return 0;
}
