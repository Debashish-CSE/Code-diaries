#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int Value;
    Node *Left;
    Node *Right;
    Node(int Value)
    {
        this->Value = Value;
        this->Left = NULL;
        this->Right = NULL;
    }
};

bool isComplete(Node *Root)
{
    if (!Root)
    {
        return true;
    }

    queue<Node *> Q;
    Q.push(Root);
    bool Flag = false;

    while (!Q.empty())
    {
        Node *Temp = Q.front();
        Q.pop();

        if (Temp == NULL)
        {
            Flag = true;
        }
        else
        {
            if (Flag)
            {
                return false;
            }

            Q.push(Temp->Left);
            Q.push(Temp->Right);
        }
    }

    return true;
}

int main()
{
    Node *Root = new Node(1);
    Node *N2 = new Node(2);
    Node *N3 = new Node(3);
    Node *N4 = new Node(4);
    Node *N5 = new Node(5);
    Node *N6 = new Node(6);
    Node *N7 = new Node(7);

    Root->Left = N2;
    Root->Right = N3;
    N2->Left = N4;
    // N2->Right = N5;
    N3->Left = N6;
    N3->Right = N7;

    if (isComplete(Root))
    {
        cout << "The tree is a complete binary tree." << endl;
    }
    else
    {
        cout << "The tree is not a complete binary tree." << endl;
    }

    return 0;
}
