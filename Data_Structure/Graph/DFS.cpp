#include <iostream>
#include <vector>
#include <stack>
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

    // Perform DFS starting from vertex s
    void dfs(int s) {
        vector<bool> visited(numVertices, false);
        stack<int> st;

        visited[s] = true;
        st.push(s);

        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            cout << vertex << " ";

            // Add unvisited neighbors to the stack
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.push(neighbor);
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

    cout << "DFS starting from vertex 0: ";
    g.dfs(0);  // Perform DFS starting from vertex 0
    cout << endl;

    return 0;
}
