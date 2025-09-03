#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> Adj;
vector<bool> Visited;
vector<int> Ans;

void DFS(int v)
{
    Visited[v] = true;
    for (int u : Adj[v])
    {
        if (!Visited[u])
        {
            DFS(u);
        }
    }
    Ans.push_back(v);
}

void Topological_Sort()
{
    Visited.assign(N + 1, false);
    Ans.clear();
    for (int i = 1; i <= N; i++)
    {
        if (!Visited[i])
        {
            DFS(i);
        }
    }
    reverse(Ans.begin(), Ans.end());
}

int main()
{
    cout << "Enter The Number of Nodes and Edges: ";
    cin >> N >> M;

    Adj.resize(N + 1);

    while (M--)
    {
        int U, V;
        cin >> U >> V;
        Adj[U].push_back(V);
    }

    Topological_Sort();

    for (auto i : Ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
