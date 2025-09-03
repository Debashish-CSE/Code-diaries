#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cout << "Enter The Number of Elements: ";
    cin >> N;
    int DATA[N], ITEM, LOC;
    cout << "Enter The Array Elements: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> DATA[i];
    }

    cout << "Enter The Searching Item: ";
    cin >> ITEM;

    DATA[N + 1] = ITEM;
    LOC = 0;

    while (DATA[LOC] != ITEM)
    {
        LOC++;
    }

    if (LOC == N + 1)
    {
        LOC = -1;
    }

    if (LOC == -1)
    {
        cout << "ITEM Not Found" << endl;
    }
    else
    {
        cout << "Item Found At Index: " << LOC << endl;
    }

    return 0;
}