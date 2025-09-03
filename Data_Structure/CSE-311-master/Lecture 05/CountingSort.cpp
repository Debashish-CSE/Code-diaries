#include <bits/stdc++.h>
using namespace std;

/*
 * O(N+R)
 * Just Print The Result Vector.
 */
vector<int> A;
vector<int> Result;
vector<int> Count;

void countingSort()
{
    for (int i = 0; i < A.size(); i++)
    {
        Count[A[i]]++;
    }
    for (int i = 1; i < A.size(); i++)
    {
        Count[i] += Count[i - 1];
    }
    for (int i = A.size() - 1; i >= 0; i--)
    {
        int Final_IDX = --Count[A[i]];
        Result[Final_IDX] = A[i];
    }
}

int main()
{
    int N;
    cout << "Enter The Number of Elements: ";
    cin >> N;
    A.resize(N);
    Result.resize(N);
    cout << "Enter The Elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int Range = *max_element(A.begin(), A.end());
    Count.resize(Range + 1);
    countingSort();
    cout << "Sorted Vector: ";
    for (int i : Result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}