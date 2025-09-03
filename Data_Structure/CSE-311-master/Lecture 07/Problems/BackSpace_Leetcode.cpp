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
    }
    void push(char x)
    {
        if (top + 1 == size)
        {
            return;
        }
        top++;
        array[top] = x;
    }
    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        char temp = array[top];
        top--;
        return temp;
    }
    char getTop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        return array[top];
    }
    int getSize() { return top + 1; }
    bool isEmpty() { return top == -1; }

    friend bool operator==(const Stack &s1, const Stack &s2);
};

bool operator==(const Stack &s1, const Stack &s2)
{
    if (s1.top != s2.top)
    {
        return false;
    }
    for (int i = 0; i <= s1.top; ++i)
    {
        if (s1.array[i] != s2.array[i])
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        Stack S1;
        for (auto C : s)
        {
            if (C == '#')
            {
                if (!S1.isEmpty())
                {
                    S1.pop();
                }
            }
            else
            {
                S1.push(C);
            }
        }
        Stack S2;
        for (auto C : t)
        {
            if (C == '#')
            {
                if (!S2.isEmpty())
                {
                    S2.pop();
                }
            }
            else
            {
                S2.push(C);
            }
        }
        return S1 == S2;
    }
};