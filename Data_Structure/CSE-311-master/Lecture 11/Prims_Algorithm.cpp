#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[], vector<vector<int>> &mstEdges)
{
    // Min-heap format: (edge_weight, current_node, parent_node)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<int> visited(V, 0);
    int sum = 0;

    pq.push(make_tuple(0, 0, -1)); // Start with node 0 (no parent)

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        int weight = get<0>(current);
        int node = get<1>(current);
        int parent = get<2>(current);

        if (visited[node])
            continue;

        visited[node] = 1;
        sum += weight;

        // Record the edge (skip root node)
        if (parent != -1)
        {
            mstEdges.push_back({parent, node, weight});
        }

        // Explore neighbors
        for (auto &edge : adj[node])
        {
            int adjNode = edge[0];
            int edW = edge[1];
            if (!visited[adjNode])
            {
                pq.push(make_tuple(edW, adjNode, node));
            }
        }
    }
    return sum;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }
    vector<vector<int>> mstEdges;
    int mstSum = spanningTree(V, adj, mstEdges);

    cout << "\nSum of MST weights: " << mstSum << endl;
    cout << "Edges in MST:\n";
    for (auto &edge : mstEdges)
    {
        cout << edge[0] << " - " << edge[1] << " (weight: " << edge[2] << ")\n";
    }

    return 0;
}