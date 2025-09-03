#include <bits/stdc++.h>
using namespace std;

vector<int> V[1000];
bool Visited[1000];
int ParentArray[1000];
bool Cycle_Paisi = false;

void DFS(int P)
{
    Visited[P] = true;
    for (auto Child : V[P])
    {
        if (Visited[Child] && ParentArray[P] != Child)
        {
            Cycle_Paisi = true;
        }
        if (!Visited[Child])
        {
            ParentArray[Child] = P;
            DFS(Child);
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
        int A, B;
        cin >> A >> B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    memset(Visited, false, sizeof(Visited));
    memset(ParentArray, -1, sizeof(ParentArray));
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