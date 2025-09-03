#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<tuple<int, int, int>> &edges, vector<vector<int>> &mstEdges)
    {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
             { return get<2>(a) < get<2>(b); });

        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        int sum = 0;
        mstEdges.clear();

        for (auto &edge : edges)
        {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int w = get<2>(edge);

            int rootU = find(u, parent);
            int rootV = find(v, parent);

            if (rootU != rootV)
            {
                sum += w;
                mstEdges.push_back({u, v, w});
                unionSet(rootU, rootV, parent, rank);
                if (mstEdges.size() == V - 1)
                    break;
            }
        }

        return sum;
    }

private:
    int find(int u, vector<int> &parent)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u], parent); // Path compression
        }
        return parent[u];
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int rootU = find(u, parent);
        int rootV = find(v, parent);

        if (rootU != rootV)
        {
            // Union by rank
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else
            {
                parent[rootU] = rootV;
                if (rank[rootU] == rank[rootV])
                {
                    rank[rootV]++;
                }
            }
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<tuple<int, int, int>> edges;
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    Solution obj;
    vector<vector<int>> mstEdges;
    int mstSum = obj.spanningTree(V, edges, mstEdges);

    cout << "\nSum of MST weights: " << mstSum << endl;
    cout << "Edges in MST:\n";
    int Total = 0;
    for (auto &edge : mstEdges)
    {
        // Display edges sorted by weight (input order for same weights)
        Total += edge[2];
        cout << edge[0] << " - " << edge[1] << " (weight: " << edge[2] << ")\n";
    }
    cout << "Total Weight: " << Total << endl;

    return 0;
}