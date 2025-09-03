// https://vjudge.net/problem/Gym-324997D
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

vector<int> A;

vector<int> Merge(vector<int> &Left, vector<int> &Right)
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < Left.size() && j < Right.size())
    {
        if (Left[i] <= Right[j])
        {
            result.push_back(Left[i]);
            i++;
        }
        else
        {
            result.push_back(Right[j]);
            j++;
        }
    }
    while (i < Left.size())
    {
        result.push_back(Left[i]);
        i++;
    }
    while (j < Right.size())
    {
        result.push_back(Right[j]);
        j++;
    }
    return result;
}

vector<int> Merge_Sort(int L, int R)
{
    if (L == R)
    {
        return {A[L]};
    }
    if (L < R)
    {
        int Mid = (L + R) / 2;
        vector<int> Left = Merge_Sort(L, Mid);
        vector<int> Right = Merge_Sort(Mid + 1, R);
        return Merge(Left, Right);
    }
    return {};
}

int main()
{
    FASTIO();
    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    auto A = Merge_Sort(0, N - 1);
    for (auto i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}