/*
 * O(N^2)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> A;
void insertionSort()
{
    for (int i = 1; i < A.size(); i++)
    {
        int Temp = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > Temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = Temp;
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
    insertionSort();
    cout << "Sorted Vector: ";
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}