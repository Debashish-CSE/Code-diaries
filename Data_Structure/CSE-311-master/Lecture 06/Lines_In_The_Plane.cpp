#include <bits/stdc++.h>
using namespace std;

int Func(int N)
{
    if (N == 0)
    {
        return 1;
    }
    int Count = Func(N - 1) + N;
    return Count;
}

int main()
{
    cout << "Enter The Number of Lines: ";
    int N;
    cin >> N;
    cout << "Divied Regoin: " << Func(N) << endl;
    return 0;
}