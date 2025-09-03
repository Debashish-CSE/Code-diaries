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

Node *Search(Node *Root, int Value)
{
    if (Root == NULL || Root->Value == Value)
    {
        return Root;
    }

    if (Value > Root->Value)
    {
        return Search(Root->Right, Value);
    }

    return Search(Root->Left, Value);
}

int main()
{
    Node *Root = NULL;

    BST_Insert(Root, 50);
    BST_Insert(Root, 70);
    BST_Insert(Root, 60);
    BST_Insert(Root, 20);
    BST_Insert(Root, 90);
    BST_Insert(Root, 10);
    BST_Insert(Root, 40);
    BST_Insert(Root, 100);

    int valueToSearch = 46;
    Node *result = Search(Root, valueToSearch);

    if (result != NULL)
    {
        cout << "Value " << valueToSearch << " found in the BST." << endl;
    }
    else
    {
        cout << "Value " << valueToSearch << " not found in the BST." << endl;
    }

    return 0;
}
