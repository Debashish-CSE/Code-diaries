#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int *array;
    int top;

public:
    Stack(int capacity = 1e5)
    {
        top = -1;
        size = capacity;
        array = new int[size];
    }
    ~Stack()
    {
        delete[] array;
        cout << "Stack memory freed!" << endl;
    }
    void push(int x)
    {
        if (top + 1 == size)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        array[top] = x;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        top--;
        return array[top];
    }
    int getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
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
    {
        Stack S(10);
        S.push(0);
        S.push(1);
        cout << S.getTop() << endl;
        S.pop();
        cout << S.getTop() << endl;
    }

    return 0;
}
