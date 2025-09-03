#include <bits/stdc++.h>
using namespace std;
int main()
{
    string P, T;
    cout << "Enter The Main String: ";
    cin >> T;
    cout << "Enter The Pattern: ";
    cin >> P;
    int R = P.size();
    int S = T.size();
    int Max = S - R + 1;
    int K = 1;
    int INDEX;
    while (K <= Max)
    {
        bool Match = true;
        for (int L = 1; L <= R; L++)
        {
            if (P[L - 1] != T[K + L - 2])
            {
                Match = false;
                break;
            }
        }
        if (Match)
        {
            INDEX = K;
            break;
        }
        else
        {
            INDEX = 0;
        }
        K = K + 1;
    }
    if (INDEX != 0)
    {
        cout << "YES " << INDEX << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
