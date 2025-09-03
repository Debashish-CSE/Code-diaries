#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int Value;
    Node *Left, *Right;
    Node(int Value)
    {
        this->Value = Value;
        this->Left = this->Right = NULL;
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
        BST_Insert(Root->Left, Value);
    else
        BST_Insert(Root->Right, Value);
}

int GetHeight(Node *Root)
{
    if (Root == NULL)
        return 0;
    return max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;
}

int GetBalanceFactor(Node *Root)
{
    if (Root == NULL)
        return 0;
    return GetHeight(Root->Left) - GetHeight(Root->Right);
}

bool IsBST(Node *Root, int MinValue, int MaxValue)
{
    if (Root == NULL)
        return true;
    if (Root->Value <= MinValue || Root->Value >= MaxValue)
        return false;
    return IsBST(Root->Left, MinValue, Root->Value) && IsBST(Root->Right, Root->Value, MaxValue);
}

bool IsAVL(Node *Root)
{
    if (Root == NULL)
        return true;
    int Balance = GetBalanceFactor(Root);
    if (abs(Balance) > 1)
        return false;
    return IsAVL(Root->Left) && IsAVL(Root->Right);
}

void InOrder(Node *Root)
{
    if (Root == NULL)
        return;
    InOrder(Root->Left);
    cout << Root->Value << " ";
    InOrder(Root->Right);
}

void PrintLevelOrder(Node *Root)
{
    if (Root == NULL)
        return;
    queue<Node *> Q;
    Q.push(Root);
    while (!Q.empty())
    {
        Node *Temp = Q.front();
        Q.pop();
        cout << Temp->Value << " ";
        if (Temp->Left)
            Q.push(Temp->Left);
        if (Temp->Right)
            Q.push(Temp->Right);
    }
    cout << endl;
}

int main()
{
    Node *Root = NULL;
    vector<int> Values = {50, 30, 70, 20, 40, 60, 80};
    for (int V : Values)
        BST_Insert(Root, V);

    InOrder(Root);
    cout << endl;
    PrintLevelOrder(Root);

    cout << (IsBST(Root, INT_MIN, INT_MAX) && IsAVL(Root) ? "Tree is a valid AVL tree!" : "Tree is not AVL!") << endl;

    return 0;
}
