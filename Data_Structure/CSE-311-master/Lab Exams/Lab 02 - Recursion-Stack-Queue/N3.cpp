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

char X, Y;
string S;

void Function(string &S, int i)
{
    if (i == S.size())
    {
        return;
    }
    if (S[i] == X)
    {
        S[i] = Y;
    }
    Function(S, i + 1);
}

int main()
{
    FASTIO();
    cin >> S;
    cin >> X >> Y;

    Function(S, 0);
    cout << S << endl;

    return 0;
}