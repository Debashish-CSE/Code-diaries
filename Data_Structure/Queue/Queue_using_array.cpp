#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr; // Clean up memory
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
        cout << x << " enqueued into queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << " dequeued from queue\n";
    cout << "Front element is " << q.peek() << endl;

    return 0;
}
