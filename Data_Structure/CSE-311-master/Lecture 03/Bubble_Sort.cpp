#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int DATA[N];
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> DATA[i];
    }

    int K = 0;
    for (int K = 0; K < N - 1; K++)
    {
        int PTR = 0;
        while (PTR <= (N - K - 2))
        {
            int Temp;
            if (DATA[PTR] > DATA[PTR + 1])
            {
                Temp = DATA[PTR];
                DATA[PTR] = DATA[PTR + 1];
                DATA[PTR + 1] = Temp;
            }
            PTR++;
        }
    }

    for (int K = 0; K < N; K++)
    {
        cout << DATA[K] << " ";
    }

    return 0;
}
