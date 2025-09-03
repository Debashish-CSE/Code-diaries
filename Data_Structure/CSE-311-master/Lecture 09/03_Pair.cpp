#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    string First;
    int Second;
    void Make_Pair(string A, int B)
    {
        First = A;
        Second = B;
    }
};

int main()
{
    Pair P;
    P.Make_Pair("Emon", 28);
    cout << P.First << endl;
    cout << P.Second << endl;
    return 0;
}