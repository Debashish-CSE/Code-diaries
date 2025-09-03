#include <bits/stdc++.h>
using namespace std;

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
        cout << "Queue memory freed!" << endl;
    }
    void enqueue(T x)
    {
        if (rear + 1 == size)
        {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear++;
        array[rear] = x;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
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
            cout << "Queue is empty!" << endl;
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
    {
        Queue<int> intQueue(10);
        intQueue.enqueue(0);
        intQueue.enqueue(1);
        cout << intQueue.getFront() << endl;
        intQueue.dequeue();
        cout << intQueue.getFront() << endl;
    }
    {
        Queue<string> stringQueue(10);
        stringQueue.enqueue("Hello");
        stringQueue.enqueue("World");
        cout << stringQueue.getFront() << endl;
        stringQueue.dequeue();
        cout << stringQueue.getFront() << endl;
    }
    {
        Queue<char> charQueue(10);
        charQueue.enqueue('A');
        charQueue.enqueue('B');
        cout << charQueue.getFront() << endl;
        charQueue.dequeue();
        cout << charQueue.getFront() << endl;
    }
    return 0;
}
