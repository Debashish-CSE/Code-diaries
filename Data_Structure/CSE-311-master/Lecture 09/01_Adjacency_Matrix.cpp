#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, E;
    cout << "Enter Number of Nodes & Edges: ";
    cin >> N >> E;
    int Mat[N][N];
    memset(Mat, 0, sizeof(Mat));
    cout << "Enter The Node Values: " << endl;
    while (E--)
    {
        int A, B;
        cin >> A >> B;
        Mat[A][B] = 1;
        Mat[B][A] = 1; // Undirected Graph
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }
    if (Mat[2][1] == 1)
    {
        cout << "Achi re vai achi" << endl;
    }
    else
    {
        cout << "Nai :(" << endl;
    }

    return 0;
}