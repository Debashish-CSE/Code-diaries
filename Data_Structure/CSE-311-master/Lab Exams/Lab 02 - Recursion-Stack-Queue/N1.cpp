#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define PB push_back
#define All(V) V.begin(), V.end()
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename T>
class Stack
{
    int size;
    T *array;
    int top;

public:
    Stack(int capacity = 1e5)
    {
        top = -1;
        size = capacity;
        array = new T[size];
    }
    ~Stack()
    {
        delete[] array;
        // cout << "Stack memory freed!" << endl;
    }
    void push(T x)
    {
        if (top + 1 == size)
        {
            // cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        array[top] = x;
    }
    T pop()
    {
        if (isEmpty())
        {
            // cout << "Stack underflow!" << endl;
            return T();
        }
        T val = array[top];
        top--;
        return val;
    }
    T getTop()
    {
        if (isEmpty())
        {
            // cout << "Stack is empty!" << endl;
            return T();
        }
        return array[top];
    }
    int getSize()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

Stack<int> Function(Stack<int> S, int Item)
{

    Stack<int> Q;
    while (!S.isEmpty())
    {
        if (S.getTop() == Item)
        {
            S.pop();
        }
        else
        {
            Q.push(S.getTop());
            S.pop();
        }
    }
    return Q;
}

int main()
{
    FASTIO();
    Stack<int> S;
    int ITEM, N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int X;
        cin >> X;
        S.push(X);
    }
    cin >> ITEM;
    auto Q = Function(S, ITEM);
    while (!Q.isEmpty())
    {
        cout << Q.getTop() << " ";
        Q.pop();
    }
    cout << endl;

    return 0;
}