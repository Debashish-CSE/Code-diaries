// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/R
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

vector<int> V;
vector<int> Result;
void Func(int i)
{
    if (i == V.size())
    {
        return;
    }
    Func(i + 1);
    Result.push_back(V[i]);
}

int main()
{
    FASTIO();
    int N;
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    Func(0);
    if (Result == V)
    {
        YES;
    }
    else
    {
        NO;
    }

    return 0;
}