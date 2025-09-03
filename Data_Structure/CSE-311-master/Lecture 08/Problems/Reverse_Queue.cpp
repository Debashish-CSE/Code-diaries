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
class Queue
{
    int size;
    T *array;
    int front, rear;

public:
    Queue(int capacity = 1e5)
    {
        size = capacity;
        array = new T[size];
        front = 0;
        rear = -1;
    }
    ~Queue()
    {
        delete[] array;
        // cout << "Queue memory freed!" << endl;
    }
    void enqueue(T x)
    {
        if (rear + 1 == size)
        {
            // cout << "Queue overflow!" << endl;
            return;
        }
        rear++;
        array[rear] = x;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            // cout << "Queue underflow!" << endl;
            return T();
        }
        T val = array[front];
        front++;
        return val;
    }
    T getFront()
    {
        if (isEmpty())
        {
            // cout << "Queue is empty!" << endl;
            return T();
        }
        return array[front];
    }
    int getSize()
    {
        return (rear - front + 1);
    }
    bool isEmpty()
    {
        return front > rear;
    }
};
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

int main()
{
    FASTIO();
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        Stack<int> S;
        Queue<int> Q;
        for (int i = 0; i < N; i++)
        {
            int X;
            cin >> X;
            Q.enqueue(X);
        }
        while (!Q.isEmpty())
        {
            S.push(Q.getFront());
            Q.dequeue();
        }
        while (!S.isEmpty())
        {
            Q.enqueue(S.getTop());
            S.pop();
        }
        while (!Q.isEmpty())
        {
            cout << Q.getFront() << " ";
            Q.dequeue();
        }
        cout << endl;
    }
    return 0;
}