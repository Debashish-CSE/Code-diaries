// https://cses.fi/problemset/task/2165/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define PB push_back
#define All(V) V.begin(), V.end()
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void towerOfHanoi(int N, int Left, int Right, int Middle)
{
    if (N == 1)
    {
        cout << Left << " " << Right << endl;
        return;
    }
    towerOfHanoi(N - 1, Left, Middle, Right);
    cout << Left << " " << Right << endl;
    towerOfHanoi(N - 1, Middle, Right, Left);
    return;
}

int main()
{
    FASTIO();
    int N;
    cin >> N;
    cout << pow(2, N) - 1 << endl;
    towerOfHanoi(N, 1, 3, 2);
    return 0;
}