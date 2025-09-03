#include <bits/stdc++.h>
using namespace std;

/*
 * Kth Person Will Be Killed & (K-1)th Person Will Be Skipped
 */
vector<int> Person;
int Josephus(int K, int Index)
{
    if (Person.size() == 1)
    {
        return Person[0];
    }
    Index = (Index + K) % Person.size();
    Person.erase(Person.begin() + Index);
    Josephus(K, Index);
}

int main()
{
    int N, K;
    cout << "Enter The Number of Persons: ";
    cin >> N;
    cout << "Enter Kth Person To be Killed: ";
    cin >> K;
    for (int i = 1; i <= N; i++)
    {
        Person.push_back(i);
    }
    cout << Josephus(K - 1, 0) << endl;
    return 0;
}