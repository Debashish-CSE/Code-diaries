#include <bits/stdc++.h>
using namespace std;

vector<int> V[(unsigned int)(1e5)];
bool isVisited[(unsigned int)(1e5)];
int Level[(unsigned int)(1e5)];

void BFS(int SRC)
{
    queue<int> Q;
    Q.push(SRC);
    isVisited[SRC] = true;
    Level[SRC] = 0;
    while (!Q.empty())
    {
        int Parent = Q.front();
        Q.pop();
        for (auto Child : V[Parent])
        {
            if (isVisited[Child] == false)
            {
                Q.push(Child);
                isVisited[Child] = true;
                Level[Child] = Level[Parent] + 1;
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
    int SRC;
    cout << "Enter The Source: ";
    cin >> SRC;
    memset(isVisited, false, sizeof(isVisited));
    memset(Level, -1, sizeof(Level));
    BFS(0);
    for (int i = 0; i < N; i++)
    {
        cout << i << " " << Level[i] << endl;
    }

    return 0;
}