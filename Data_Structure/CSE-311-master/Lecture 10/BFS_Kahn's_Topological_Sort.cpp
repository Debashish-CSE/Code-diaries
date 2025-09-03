#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &Adj, int V)
{
    vector<int> indegree(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        for (auto it : Adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto it : Adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (result.size() != V)
    {
        cout << "Graph contains cycle!" << endl;
        return {};
    }
    return result;
}

int main()
{
    int N, E;
    cin >> N >> E;
    vector<vector<int>> Adj(N + 1);

    while (E--)
    {
        int U, V;
        cin >> U >> V;
        Adj[U].push_back(V);
    }

    cout << "Topological sorting of the graph: ";
    vector<int> result = topologicalSort(Adj, N);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}