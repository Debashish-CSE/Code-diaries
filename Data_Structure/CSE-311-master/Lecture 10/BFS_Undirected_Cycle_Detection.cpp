#include <bits/stdc++.h>
using namespace std;

vector<int> V[1000];
bool Visited[1000];
int ParentArray[1000];
bool Cycle_Paisi = false;

void BFS(int i)
{
    queue<int> Q;
    Q.push(i);
    Visited[i] = true;
    while (!Q.empty())
    {
        int Parent = Q.front();
        Q.pop();
        for (int Child : V[Parent])
        {
            if (Visited[Child] && ParentArray[Parent] != Child)
            {
                Cycle_Paisi = true;
            }
            if (!Visited[Child])
            {
                Q.push(Child);
                Visited[Child] = true;
                ParentArray[Child] = Parent;
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
            BFS(i);
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