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

void BST_Insert(Node *&Root, int Value)
{
    if (Root == NULL)
    {
        Root = new Node(Value);
        return;
    }

    if (Value < Root->Value)
    {
        BST_Insert(Root->Left, Value);
    }
    else
    {
        BST_Insert(Root->Right, Value);
    }
}

void InOrder(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }

    InOrder(Root->Left);
    cout << Root->Value << " ";
    InOrder(Root->Right);
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

    BST_Insert(Root, 50);
    BST_Insert(Root, 76);
    BST_Insert(Root, 21);
    BST_Insert(Root, 4);
    BST_Insert(Root, 32);
    BST_Insert(Root, 64);
    BST_Insert(Root, 15);
    BST_Insert(Root, 52);
    BST_Insert(Root, 14);
    BST_Insert(Root, 100);
    BST_Insert(Root, 83);
    BST_Insert(Root, 2);
    BST_Insert(Root, 3);
    BST_Insert(Root, 70);
    BST_Insert(Root, 87);
    BST_Insert(Root, 80);

    cout << "In-order traversal of the Binary Search Tree: ";
    InOrder(Root);
    cout << endl;

    cout << "Level-order traversal of the Binary Search Tree: ";
    printLevelOrder(Root);

    return 0;
}
