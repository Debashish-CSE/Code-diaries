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

Node *InOrder_Successor(Node *Root)
{
    while (Root->Left != NULL)
    {
        Root = Root->Left;
    }
    return Root;
}

Node *Delete(Node *Root, int value)
{
    if (Root == NULL)
    {
        return Root;
    }

    if (value < Root->Value)
    {
        Root->Left = Delete(Root->Left, value);
    }
    else if (value > Root->Value)
    {
        Root->Right = Delete(Root->Right, value);
    }
    else
    {
        // Case 1: No child
        if (Root->Left == NULL && Root->Right == NULL)
        {
            delete Root;
            return NULL;
        }

        // Case 2: One child
        if (Root->Left == NULL)
        {
            Node *Temp = Root->Right;
            delete Root;
            return Temp;
        }
        else if (Root->Right == NULL)
        {
            Node *Temp = Root->Left;
            delete Root;
            return Temp;
        }

        // Case 3: Two children
        Node *Temp = InOrder_Successor(Root->Right);
        Root->Value = Temp->Value;
        Root->Right = Delete(Root->Right, Temp->Value);
    }

    return Root;
}

int main()
{
    Node *Root = NULL;

    // Inserting values to form a Binary Search Tree
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

    cout << "Level-order traversal of the Binary Search Tree: ";
    printLevelOrder(Root);

    // Example of deleting a node
    Root = Delete(Root, 32);

    cout << "After deletion of 32:" << endl;
    cout << "Level-order traversal: ";
    printLevelOrder(Root);

    return 0;
}
