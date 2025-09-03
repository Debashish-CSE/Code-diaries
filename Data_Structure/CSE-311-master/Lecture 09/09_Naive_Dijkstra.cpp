#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
vector<pair<int, int>> V[(unsigned int)(MX)];
int Distant[(unsigned int)(MX)];

void Dijkstra(int Src)
{
    queue<pair<int, int>> Q;
    Q.push({Src, 0});
    Distant[Src] = 0;
    while (!Q.empty())
    {
        auto Parent = Q.front();
        Q.pop();
        int Node = Parent.first;
        int Cost = Parent.second;
        for (auto Child : V[Node])
        {
            int ChildNode = Child.first;
            int ChildCost = Child.second;
            if (Cost + ChildCost < Distant[ChildNode])
            {
                Distant[ChildNode] = Cost + ChildCost;
                Q.push({ChildNode, Distant[ChildNode]});
            }
        }
    }
}

int main()
{
    int N, E;
    cout << "Enter The Number of Nodes and Edges: ";
    cin >> N >> E;
    while (E--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        V[A].push_back({B, C});
        V[B].push_back({A, C});
    }
    for (int i = 0; i < N; i++)
    {
        Distant[i] = INT_MAX;
    }
    int Src;
    cout << "Enter a Source: ";
    cin >> Src;
    Dijkstra(Src);
    for (int i = 0; i < N; i++)
    {
        cout << Src << " To " << i << " -> " << Distant[i] << endl;
    }

    return 0;
}