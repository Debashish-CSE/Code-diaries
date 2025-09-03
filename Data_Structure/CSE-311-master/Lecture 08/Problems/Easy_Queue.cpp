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
    Queue(int capacity = 1e7)
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

int main()
{
    FASTIO();
    {
        Queue<ll> Q;
        int T;
        cin >> T;
        while (T--)
        {
            ll A;
            cin >> A;
            if (A == 1)
            {
                ll N;
                cin >> N;
                Q.enqueue(N);
            }
            else if (A == 2)
            {
                if (!Q.isEmpty())
                {
                    Q.dequeue();
                }
            }
            else if (A == 3)
            {
                if (!Q.isEmpty())
                {
                    cout << Q.getFront() << endl;
                }
                else
                {
                    cout << "Empty!" << endl;
                }
            }
        }
    }
    return 0;
}