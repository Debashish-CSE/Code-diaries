// https://www.geeksforgeeks.org/problems/reverse-a-string-using-stack/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include <bits/stdc++.h>
using namespace std;
char *reverse(char *str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        for (int i = 0; i < len; i++)
        {
            cout << ch[i];
        }
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends

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
        top--;
        return array[top];
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

// return the address of the string
char *reverse(char *S, int len)
{
    Stack ST;
    for (int i = 0; i < len; i++)
    {
        ST.push(S[i]);
    }
    for (int i = 0; i < len; i++)
    {
        S[i] = ST.getTop();
        ST.pop();
    }
    return S;
}