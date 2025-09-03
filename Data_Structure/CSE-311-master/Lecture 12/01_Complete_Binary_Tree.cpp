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

void Insert(Node *&Root, int Value)
{
    Node *newNode = new Node(Value);
    if (Root == NULL)
    {
        Root = newNode;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty())
    {
        Node *Temp = Q.front();
        Q.pop();

        if (Temp->Left == NULL)
        {
            Temp->Left = newNode;
            return;
        }
        else
        {
            Q.push(Temp->Left);
        }

        if (Temp->Right == NULL)
        {
            Temp->Right = newNode;
            return;
        }
        else
        {
            Q.push(Temp->Right);
        }
    }
}

void printLevelOrder(Node *Root)
{
    if (Root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty())
    {
        Node *Temp = Q.front();
        Q.pop();

        cout << Temp->Value << " ";

        if (Temp->Left)
        {
            Q.push(Temp->Left);
        }
        if (Temp->Right)
        {
            Q.push(Temp->Right);
        }
    }
    cout << endl;
}

int main()
{
    Node *Root = NULL;

    Insert(Root, 1);
    Insert(Root, 2);
    Insert(Root, 3);
    Insert(Root, 4);
    Insert(Root, 5);
    Insert(Root, 6);
    Insert(Root, 7);

    cout << "Level-order traversal of the complete binary Tree: ";
    printLevelOrder(Root);

    return 0;
}
