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

int Partition(int Arr[], int start, int end)
{
    int Pivot = Arr[end];
    int P_index = start;
    for (int i = start; i < end - 1; i++)
    {
        if (Arr[i] <= Pivot)
        {
            swap(Arr[i], Arr[P_index]);
            P_index = P_index + 1;
        }
    }
    swap(Arr[P_index], Arr[end]);
    return P_index;
}

void Quicksort(int Arr[], int start, int end)
{
    if (start < end)
    {
        int P_index = Partition(Arr, start, end);
        Quicksort(Arr, start, P_index - 1);
        Quicksort(Arr, P_index + 1, end);
    }
}

int main()
{
    FASTIO();
    int N;
    cin >> N;
    int Arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    Quicksort(Arr, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << Arr[i] << " ";
    }
    return 0;
}