#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, E;
    cout << "Enter Number of Nodes & Edges: ";
    cin >> N >> E;
    vector<int> Mat[N];
    cout << "Enter The Node Values: " << endl;
    while (E--)
    {
        int A, B;
        cin >> A >> B;
        Mat[A].push_back(B);
        Mat[B].push_back(A); // Undirected
    }
    cout << "Elements That Are Connected With One" << endl;
    for (int X : Mat[1])
    {
        cout << X << " ";
    }
    return 0;
}