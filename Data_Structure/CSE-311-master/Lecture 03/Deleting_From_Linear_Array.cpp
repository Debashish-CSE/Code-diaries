/*
 * Q: Why the LA[J+1] gave no error despite not existing?
 */
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N, K, ITEM;
    cout << "Enter The Number of Elements in The Array: ";
    cin >> N;
    int LA[N];
    cout << "Enter The Deleting Position: ";
    cin >> K;
    cout << "Enter The Array Elements: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> LA[i];
    }
    cout << "Array Before Deletation: " << endl;
    printArray(LA, N);
    ITEM = LA[K];
    for (int J = K; J < N - 1; J++)
    {
        LA[J] = LA[J + 1];
    }
    N = N - 1;
    cout << "Array After Deletation: " << endl;
    printArray(LA, N);
    return 0;
}