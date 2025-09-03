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
        cout << "Stack memory freed!" << endl;
    }
    void push(char x)
    {
        if (top + 1 == size)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        array[top] = x;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
        top--;
        return array[top];
    }
    char getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
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
    {
        Stack S(10);
        S.push('A');
        S.push('B');
        cout << S.getTop() << endl;
        S.pop();
        cout << S.getTop() << endl;
    }
    return 0;
}

/*
class Stack {
    int size;
    char* array;
    int top;

public:
    Stack(int capacity = 1e5) {
        top = -1;
        size = capacity;
        array = new char[size];
    }
    ~Stack() {
        delete[] array;
    }
    void push(char x) {
        if (top + 1 == size) {
            return;
        }
        top++;
        array[top] = x;
    }
    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        char temp = array[top];
        top--;
        return temp;
    }
    char getTop() {
        if (isEmpty()) {
            return '\0';
        }
        return array[top];
    }
    int getSize() { return top + 1; }
    bool isEmpty() { return top == -1; }

    friend bool operator==(const Stack& s1, const Stack& s2);
};

bool operator==(const Stack& s1, const Stack& s2) {
    if (s1.top != s2.top) {
        return false;
    }
    for (int i = 0; i <= s1.top; ++i) {
        if (s1.array[i] != s2.array[i]) {
            return false;
        }
    }
    return true;
}
*/