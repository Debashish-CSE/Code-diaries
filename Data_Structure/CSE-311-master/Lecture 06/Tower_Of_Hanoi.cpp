#include <bits/stdc++.h>
using namespace std;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

long long towerOfHanoi(int N, int From, int To, int Auxiliary)
{
    if (N == 1)
    {
        cout << "Moved Disk " << N << " From Rod " << From << " To " << To << endl;
        return 1;
    }
    long long Count = towerOfHanoi(N - 1, From, Auxiliary, To);
    cout << "Moved Disk " << N << " From Rod " << From << " To " << To << endl;
    Count++;
    Count += towerOfHanoi(N - 1, Auxiliary, To, From);
    return Count;
}

int main()
{
    FASTIO();
    long long C = towerOfHanoi(3, 1, 2, 3);
    cout << "Number of Operations: " << C << endl;
    return 0;
}