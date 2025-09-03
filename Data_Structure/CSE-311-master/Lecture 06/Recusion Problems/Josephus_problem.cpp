// https://www.hackerearth.com/problem/algorithm/josephus-problem-a32f566f-05895169/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

/*
 * Kth Person Will Be Killed & (K-1)th Person Will Be Skipped
 */
vector<int> Person;
int Josephus(int K, int Index)
{
    if (Person.size() == 1)
    {
        return Person[0];
    }
    Index = (Index + K) % Person.size();
    Person.erase(Person.begin() + Index);
    return Josephus(K, Index);
}

int main()
{
    FASTIO();
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        Person.push_back(i + 1);
    }
    cout << Josephus(K - 1, 0) << '\n';
    return 0;
}