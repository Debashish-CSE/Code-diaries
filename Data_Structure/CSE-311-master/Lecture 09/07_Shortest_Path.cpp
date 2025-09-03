#include <bits/stdc++.h>
using namespace std;

vector<int> V[(unsigned int)(1e5)];
bool isVisited[(unsigned int)(1e5)];
int Level[(unsigned int)(1e5)];
int parentTrack[(unsigned int)(1e5)];

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
                parentTrack[Child] = Parent;
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
    memset(parentTrack, -1, sizeof(parentTrack));
    BFS(0);
    int DES;
    cout << "Enter The Destination: ";
    cin >> DES;
    vector<int> Path;
    while (true)
    {
        if (DES == -1)
        {
            break;
        }
        Path.push_back(DES);
        DES = parentTrack[DES];
    }
    reverse(Path.begin(), Path.end());
    for (auto i : Path)
    {
        cout << i << " ";
    }

    return 0;
}