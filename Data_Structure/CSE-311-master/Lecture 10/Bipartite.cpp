#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, int col, vector<int> &color, vector<int> adj[])
{
    color[node] = col;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (DFS(it, !col, color, adj) == false)
            {
                return false;
            }
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (DFS(i, 0, color, adj) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N, E;
    cout << "Enter Number of Nodes & Edges: ";
    cin >> N >> E;

    vector<int> Mat[N];
    cout << "Enter The Node Values: " << endl;
    while (E--)
    {
        int A, B;
        cin >> A >> B;
        Mat[A].push_back(B);
        Mat[B].push_back(A); // Undirected
    }

    if (isBipartite(N, Mat))
    {
        cout << "Graph is Bipartite" << endl;
    }
    else
    {
        cout << "Graph is Not Bipartite" << endl;
    }

    return 0;
}
