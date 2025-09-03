#include <bits/stdc++.h>
using namespace std;

vector<int> V[1000];
bool Visited[1000];
bool Path[1000];
bool Cycle_Paisi = false;

void DFS(int P)
{
    Visited[P] = true;
    Path[P] = true;
    for (auto Child : V[P])
    {
        if (Path[Child])
        {
            Cycle_Paisi = true;
        }
        if (!Visited[Child])
        {
            DFS(Child);
        }
    }
    Path[P] = false;
}
int main()
{
    int N, E;
    cout << "Enter The Number of Nodes and Edges: ";
    cin >> N >> E;
    while (E--)
    {
        int A, B;
        cin >> A >> B;
        V[A].push_back(B);
    }
    memset(Visited, false, sizeof(Visited));
    for (int i = 0; i < N; i++)
    {
        if (!Visited[i])
        {
            DFS(i);
        }
    }
    if (Cycle_Paisi)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "Cycle Not Detected" << endl;
    }
    return 0;
}