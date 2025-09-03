#include <bits/stdc++.h>
using namespace std;

vector<float> A;

void insertionSortBucket(vector<float> &Bucket)
{
    for (int i = 1; i < Bucket.size(); i++)
    {
        float temp = Bucket[i];
        int j = i - 1;
        while (j >= 0 && Bucket[j] > temp)
        {
            Bucket[j + 1] = Bucket[j];
            j--;
        }
        Bucket[j + 1] = temp;
    }
}
void bucketSort()
{
    int N = A.size();
    vector<vector<float>> Buckets(N);

    for (int i = 0; i < N; i++)
    {
        int Bucket_Index = N * A[i];
        Buckets[Bucket_Index].push_back(A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (!Buckets[i].empty())
        {
            insertionSortBucket(Buckets[i]);
        }
    }

    int Index = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Buckets[i].size(); j++)
        {
            A[Index++] = Buckets[i][j];
        }
    }
}

int main()
{
    int N;
    cout << "Enter The Number of Elements: ";
    cin >> N;
    A.resize(N);
    cout << "Enter The Elements (each in the range [0, 1)): ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    bucketSort();

    cout << "Sorted Vector: ";
    for (float Num : A)
    {
        cout << Num << " ";
    }
    cout << endl;
    return 0;
}
