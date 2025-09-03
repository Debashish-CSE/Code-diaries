#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
const int INF = INT_MAX;

vector<int> Dijkstra(int src, vector<pair<int, int>> adj[], int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<int> Distant(N + 1, INF);
    Distant[src] = 0;
    PQ.push({0, src});

    while (!PQ.empty())
    {
        int Cost = PQ.top().first;
        int Node = PQ.top().second;
        PQ.pop();

        if (Cost > Distant[Node])
        {
            continue;
        }

        for (auto Child : adj[Node])
        {
            int ChildNode = Child.first;
            int ChildCost = Child.second;

            if (Distant[Node] + ChildCost < Distant[ChildNode])
            {
                Distant[ChildNode] = Distant[Node] + ChildCost;
                PQ.push({Distant[ChildNode], ChildNode});
            }
        }
    }
    return Distant;
}

int main()
{
    int N, E;
    cout << "Enter The Number of Nodes and Edges: ";
    cin >> N >> E;

    vector<pair<int, int>> adj[MX];

    cout << "Enter edges (u v weight): " << endl;
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }

    int src;
    cout << "Enter Source: ";
    cin >> src;

    vector<int> Distant = Dijkstra(src, adj, N);

    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 1; i <= N; i++)
    {
        if (Distant[i] == INF)
        {
            cout << src << " To " << i << " -> " << "Not reachable" << endl;
        }
        else
        {
            cout << src << " To " << i << " -> " << Distant[i] << endl;
        }
    }

    return 0;
}