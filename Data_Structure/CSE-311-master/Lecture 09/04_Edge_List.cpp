#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, E;
    cout << "Enter The Number of Nodes and Edges: ";
    cin >> N >> E;
    cout << "Enter The Edges: ";
    vector<pair<int, int>> V;
    while (E--)
    {
        int A, B;
        cin >> A >> B;
        V.push_back({A, B});
    }
    cout << "Edge List Are: " << endl;
    for (auto Edge : V)
    {
        cout << Edge.first << " " << Edge.second << endl;
    }
    return 0;
}