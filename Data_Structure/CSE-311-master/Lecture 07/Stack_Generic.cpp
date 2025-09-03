#include <bits/stdc++.h>
using namespace std;

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
        cout << "Stack memory freed!" << endl;
    }
    void push(T x)
    {
        if (top + 1 == size)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        array[top] = x;
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
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
            cout << "Stack is empty!" << endl;
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
    {
        Stack<string> stringStack(10);
        stringStack.push("Hello");
        stringStack.push("World");
        cout << stringStack.getTop() << endl;
        stringStack.pop();
        cout << stringStack.getTop() << endl;
    }
    {
        Stack<char> charStack(10);
        charStack.push('X');
        charStack.push('Y');
        cout << charStack.getTop() << endl;
        charStack.pop();
        cout << charStack.getTop() << endl;
    }
    return 0;
}
