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

void prinT(vector<int> V, int N)
{
    if (N < 0)
    {
        return;
    }
    if (N % 2 == 0)
    {
        cout << V[N] << " ";
    }
    prinT(V, N - 1);
}

int main()
{
    FASTIO();
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    prinT(V, N - 1);
    return 0;
}