// https://cses.fi/problemset/task/1068/
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

void Func(ll N)
{
    if (N == 1)
    {
        return;
    }
    else if (N % 2 == 0)
    {
        cout << N << " ";
        N /= 2;
        Func(N);
    }
    else if (N % 2 == 1)
    {
        cout << N << " ";
        N = (N * 3) + 1;
        Func(N);
    }
}

int main()
{
    FASTIO();
    ll N;
    cin >> N;
    Func(N);
    cout << 1 << endl;
    return 0;
}