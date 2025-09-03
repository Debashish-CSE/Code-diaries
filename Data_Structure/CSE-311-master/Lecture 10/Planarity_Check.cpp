#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj[MAX_N];
bool visited[MAX_N];

pair<bool, vector<int>> checkBipartiteAndComponent(int start)
{
    vector<int> component;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component.push_back(start);
    vector<int> color(MAX_N, -1);
    color[start] = 0;
    bool isBipartite = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                component.push_back(v);
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else if (color[v] == color[u])
            {
                isBipartite = false;
            }
        }
    }

    return {isBipartite, component};
}

int countEdges(const vector<int> &component)
{
    unordered_set<int> compSet(component.begin(), component.end());
    int edgeCount = 0;
    for (int u : component)
    {
        for (int v : adj[u])
        {
            if (compSet.count(v))
            {
                edgeCount++;
            }
        }
    }
    return edgeCount / 2;
}

int main()
{
    int N, E;
    cout << "Enter the number of nodes and edges: ";
    cin >> N >> E;

    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    memset(visited, false, sizeof(visited));
    bool isPlanar = true;

    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            auto result = checkBipartiteAndComponent(i);
            bool bipartite = result.first;
            vector<int> component = result.second;
            int V_i = component.size();
            int E_i = countEdges(component);

            if (V_i >= 3)
            {
                if (E_i > 3 * V_i - 6)
                {
                    isPlanar = false;
                    break;
                }
                if (bipartite && E_i > 2 * V_i - 4)
                {
                    isPlanar = false;
                    break;
                }
            }
        }
    }

    cout << "The graph is " << (isPlanar ? "planar." : "not planar.") << endl;

    return 0;
}