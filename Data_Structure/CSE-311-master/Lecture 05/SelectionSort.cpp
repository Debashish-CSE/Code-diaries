/*
 * O(N^2)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> A;
void selectionSort()
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        int MIN = i;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[MIN] > A[j])
            {
                MIN = j;
            }
        }
        int Temp = A[i];
        A[i] = A[MIN];
        A[MIN] = Temp;
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
    selectionSort();
    cout << "Sorted Vector: ";
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}