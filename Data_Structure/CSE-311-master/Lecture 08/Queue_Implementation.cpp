#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int size;
    int *array;
    int front, rear;

public:
    Queue(int capacity = 1e5)
    {
        size = capacity;
        array = new int[size];
        front = 0;
        rear = -1;
    }
    ~Queue()
    {
        delete[] array;
        cout << "Queue memory freed!" << endl;
    }
    void enqueue(int x)
    {
        if (rear + 1 == size)
        {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear++;
        array[rear] = x;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }
        int val = array[front];
        front++;
        return val;
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
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
        Queue Q(10);
        Q.enqueue(0);
        Q.enqueue(1);
        cout << Q.getFront() << endl;
        Q.dequeue();
        cout << Q.getFront() << endl;
    }
    return 0;
}