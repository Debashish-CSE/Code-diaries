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
    cout << "Enter The Element To Insert: ";
    cin >> ITEM;
    cout << "Enter The Inserting Position: ";
    cin >> K;
    cout << "Enter The Array Elements: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> LA[i];
    }
    int J = N;
    cout << "Array Before Insertion: ";
    printArray(LA, N);

    while (J >= K)
    {
        LA[J + 1] = LA[J];
        J--;
    }
    LA[K] = ITEM;
    N = N + 1;

    cout << "Array After Insertion: ";
    printArray(LA, N);
    return 0;
}