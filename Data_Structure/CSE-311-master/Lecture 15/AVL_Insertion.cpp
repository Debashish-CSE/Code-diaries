#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int Value;
    Node *Left;
    Node *Right;
    int Height;
    Node(int Value)
    {
        this->Value = Value;
        this->Left = NULL;
        this->Right = NULL;
        this->Height = 1;
    }
};

int GetHeight(Node *Root)
{
    return Root ? Root->Height : 0;
}

void UpdateHeight(Node *Root)
{
    if (Root)
        Root->Height = max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;
}

int GetBalanceFactor(Node *Root)
{
    return Root ? GetHeight(Root->Left) - GetHeight(Root->Right) : 0;
}

Node *RightRotate(Node *Y)
{
    Node *X = Y->Left;
    Node *T2 = X->Right;

    X->Right = Y;
    Y->Left = T2;

    UpdateHeight(Y);
    UpdateHeight(X);

    return X;
}

Node *LeftRotate(Node *X)
{
    Node *Y = X->Right;
    Node *T2 = Y->Left;

    Y->Left = X;
    X->Right = T2;

    UpdateHeight(X);
    UpdateHeight(Y);

    return Y;
}

Node *AVL_Insert(Node *Root, int Value)
{
    if (!Root)
        return new Node(Value);

    if (Value < Root->Value)
        Root->Left = AVL_Insert(Root->Left, Value);
    else if (Value > Root->Value)
        Root->Right = AVL_Insert(Root->Right, Value);
    else
        return Root; // Duplicates not allowed

    UpdateHeight(Root);

    int Balance = GetBalanceFactor(Root);

    // Balancing
    if (Balance > 1 && Value < Root->Left->Value)
        return RightRotate(Root);
    if (Balance < -1 && Value > Root->Right->Value)
        return LeftRotate(Root);
    if (Balance > 1 && Value > Root->Left->Value)
    {
        Root->Left = LeftRotate(Root->Left);
        return RightRotate(Root);
    }
    if (Balance < -1 && Value < Root->Right->Value)
    {
        Root->Right = RightRotate(Root->Right);
        return LeftRotate(Root);
    }

    return Root;
}

void InOrder(Node *Root)
{
    if (!Root)
        return;
    InOrder(Root->Left);
    cout << Root->Value << " ";
    InOrder(Root->Right);
}

int main()
{
    Node *Root = NULL;

    vector<int> Values = {10, 20, 30, 40, 50, 25};

    for (int Value : Values)
    {
        Root = AVL_Insert(Root, Value);
    }

    cout << "Final AVL Tree (In-Order Traversal): ";
    InOrder(Root);
    cout << endl;

    return 0;
}
