#include <bits/stdc++.h>
using namespace std;

bool canColor(int pos, vector<int> &sorted_nodes, vector<int> &color, int k, vector<vector<int>> &adj)
{
    if (pos == sorted_nodes.size())
    {
        return true;
    }

    int node = sorted_nodes[pos];

    for (int c = 1; c <= k; ++c)
    {
        bool valid = true;
        for (int neighbor : adj[node])
        {
            if (color[neighbor] == c)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            color[node] = c;
            if (canColor(pos + 1, sorted_nodes, color, k, adj))
            {
                return true;
            }
            color[node] = 0; // backtrack
        }
    }

    return false;
}

int main()
{
    int N, E;
    cout << "Enter the number of nodes and edges: ";
    cin >> N >> E;

    vector<vector<int>> adj(N);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    // Compute maximum degree
    int max_degree = 0;
    for (auto &vec : adj)
    {
        if (vec.size() > max_degree)
        {
            max_degree = vec.size();
        }
    }

    // Determine upper bound for k
    int upper_k = max_degree + 1;
    upper_k = min(upper_k, N);

    // Sort nodes by degree in descending order
    vector<int> sorted_nodes(N);
    iota(sorted_nodes.begin(), sorted_nodes.end(), 0);
    sort(sorted_nodes.begin(), sorted_nodes.end(), [&adj](int a, int b)
         { return adj[a].size() > adj[b].size(); });

    // Find chromatic number
    int chromatic = 0;
    for (int k = 1; k <= upper_k; ++k)
    {
        vector<int> color(N, 0);
        if (canColor(0, sorted_nodes, color, k, adj))
        {
            chromatic = k;
            break;
        }
    }

    cout << "The chromatic number is: " << chromatic << endl;

    return 0;
}