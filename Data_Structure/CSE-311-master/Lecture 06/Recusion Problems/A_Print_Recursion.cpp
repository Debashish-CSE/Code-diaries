// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/A
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

int N;

void printRecursion(int i)
{

    if (i == N)
    {
        return;
    }
    cout << "I love Recursion" << endl;
    printRecursion(i + 1);
}

int main()
{
    FASTIO();
    cin >> N;
    printRecursion(0);
    return 0;
}
