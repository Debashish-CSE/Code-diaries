/*
 * O(D(N+R)) or O(D*N)
 * D -> Number of Digits
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int getMax()
{
    int maxVal = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > maxVal)
        {
            maxVal = A[i];
        }
    }
    return maxVal;
}

void countSort(int Position)
{
    int N = A.size();
    vector<int> Output(N);
    vector<int> Count(10, 0);
    for (int i = 0; i < N; i++)
    {
        int Digit = (A[i] / Position) % 10;
        Count[Digit]++;
    }
    for (int i = 1; i < 10; i++)
    {
        Count[i] += Count[i - 1];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        int Digit = (A[i] / Position) % 10;
        Output[--Count[Digit]] = A[i];
    }
    for (int i = 0; i < N; i++)
    {
        A[i] = Output[i];
    }
}

void radixSort()
{
    int Max = getMax();
    for (int Position = 1; Max / Position > 0; Position *= 10)
    {
        countSort(Position);
    }
}

int main()
{
    int N;
    cout << "Enter The Number of Elements: ";
    cin >> N;
    A.resize(N);
    cout << "Enter The Elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    radixSort();

    cout << "Sorted Vector: ";
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
