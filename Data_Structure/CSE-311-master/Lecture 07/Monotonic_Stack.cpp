#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    char *array;
    int top;

public:
    Stack(int capacity = 1e5)
    {
        top = -1;
        size = capacity;
        array = new char[size];
    }
    ~Stack()
    {
        delete[] array;
        // cout << "Stack memory freed!" << endl;
    }
    void push(char x)
    {
        if (top + 1 == size)
        {
            // cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        array[top] = x;
    }
    char pop()
    {
        if (isEmpty())
        {
            // cout << "Stack underflow!" << endl;
            return '\0';
        }
        char popped = array[top];
        top--;
        return popped;
    }
    char getTop()
    {
        if (isEmpty())
        {
            // cout << "Stack is empty!" << endl;
            return '\0';
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
    Stack ST;
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        while (!ST.isEmpty() && ST.getTop() > S[i])
        {
            ST.pop();
        }
        ST.push(S[i]);
    }

    string result = "";
    while (!ST.isEmpty())
    {
        result = ST.pop() + result;
    }
    cout << result;
    return 0;
}