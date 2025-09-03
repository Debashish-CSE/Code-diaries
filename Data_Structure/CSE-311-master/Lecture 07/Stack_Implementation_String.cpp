#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    string *array;
    int top;

public:
    Stack(int capacity = 1e5)
    {
        top = -1;
        size = capacity;
        array = new string[size];
    }
    ~Stack()
    {
        delete[] array;
        cout << "Stack memory freed!" << endl;
    }
    void push(string x)
    {
        if (top + 1 == size)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        array[top] = x;
    }
    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return "";
        }
        top--;
        return array[top];
    }
    string getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return "";
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
        S.push("Hello");
        S.push("World");
        cout << S.getTop() << endl;
        S.pop();
        cout << S.getTop() << endl;
    }
    return 0;
}