#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define PB push_back
#define All(V) V.begin(), V.end()
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> arrayIntersect(vector<int> A, vector<int> B)
{
    sort(All(A));
    A.erase(unique(A.begin(), A.end()), A.end());
    sort(All(B));
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<int> Result;
    int Max = max(A.size(), B.size());
    if (Max == A.size())
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                if (A[i] == B[j])
                {
                    Result.push_back(A[i]);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < B.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                if (A[i] == B[j])
                {
                    Result.push_back(A[i]);
                }
            }
        }
    }
    return Result;
}
int main()
{
    FASTIO();
    int SZ1, SZ2;
    cin >> SZ1 >> SZ2;
    vector<int> V1(SZ1), V2(SZ2);
    for (int i = 0; i < SZ1; i++)
    {
        cin >> V1[i];
    }
    for (int i = 0; i < SZ2; i++)
    {
        cin >> V2[i];
    }
    auto V = arrayIntersect(V1, V2);
    for (auto i : V)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}