#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int Value, Height;
    Node *Left, *Right;
    Node(int Value) : Value(Value), Left(NULL), Right(NULL), Height(1) {}
};

int GetHeight(Node *Root) { return Root ? Root->Height : 0; }

int GetBalanceFactor(Node *Root) { return Root ? GetHeight(Root->Left) - GetHeight(Root->Right) : 0; }

void UpdateHeight(Node *Root)
{
    if (Root)
        Root->Height = max(GetHeight(Root->Left), GetHeight(Root->Right)) + 1;
}

Node *RightRotate(Node *Y)
{
    Node *X = Y->Left, *T2 = X->Right;
    X->Right = Y;
    Y->Left = T2;
    UpdateHeight(Y);
    UpdateHeight(X);
    return X;
}

Node *LeftRotate(Node *X)
{
    Node *Y = X->Right, *T2 = Y->Left;
    Y->Left = X;
    X->Right = T2;
    UpdateHeight(X);
    UpdateHeight(Y);
    return Y;
}

Node *FindMinValue(Node *Root)
{
    while (Root->Left)
        Root = Root->Left;
    return Root;
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
        return Root;

    UpdateHeight(Root);
    int Balance = GetBalanceFactor(Root);

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

Node *AVL_Delete(Node *Root, int Value)
{
    if (!Root)
        return Root;
    if (Value < Root->Value)
        Root->Left = AVL_Delete(Root->Left, Value);
    else if (Value > Root->Value)
        Root->Right = AVL_Delete(Root->Right, Value);
    else
    {
        if (!Root->Left)
        {
            Node *Temp = Root->Right;
            delete Root;
            return Temp;
        }
        if (!Root->Right)
        {
            Node *Temp = Root->Left;
            delete Root;
            return Temp;
        }
        Node *Temp = FindMinValue(Root->Right);
        Root->Value = Temp->Value;
        Root->Right = AVL_Delete(Root->Right, Temp->Value);
    }

    if (!Root)
        return Root;
    UpdateHeight(Root);
    int Balance = GetBalanceFactor(Root);

    if (Balance > 1 && GetBalanceFactor(Root->Left) >= 0)
        return RightRotate(Root);
    if (Balance > 1 && GetBalanceFactor(Root->Left) < 0)
    {
        Root->Left = LeftRotate(Root->Left);
        return RightRotate(Root);
    }
    if (Balance < -1 && GetBalanceFactor(Root->Right) <= 0)
        return LeftRotate(Root);
    if (Balance < -1 && GetBalanceFactor(Root->Right) > 0)
    {
        Root->Right = RightRotate(Root->Right);
        return LeftRotate(Root);
    }

    return Root;
}

bool SearchValue(Node *Root, int Value)
{
    if (!Root)
        return false;
    if (Value == Root->Value)
        return true;
    return Value < Root->Value ? SearchValue(Root->Left, Value) : SearchValue(Root->Right, Value);
}

void InOrder(Node *Root)
{
    if (!Root)
        return;
    InOrder(Root->Left);
    cout << Root->Value << " ";
    InOrder(Root->Right);
}

void PrintLevelOrder(Node *Root)
{
    if (!Root)
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
            Q.push(Temp->Left);
        if (Temp->Right)
            Q.push(Temp->Right);
    }
    cout << endl;
}

bool IsAVL(Node *Root)
{
    if (!Root)
        return true;
    int BalanceFactor = GetBalanceFactor(Root);
    return abs(BalanceFactor) <= 1 && IsAVL(Root->Left) && IsAVL(Root->Right);
}

int main()
{
    Node *Root = NULL;

    // Build initial AVL tree
    vector<int> InsertValues = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 35};
    for (int Value : InsertValues)
    {
        Root = AVL_Insert(Root, Value);
    }

    // Perform deletions
    vector<int> DeleteValues = {5, 30, 50, 25};
    for (int Value : DeleteValues)
    {
        if (SearchValue(Root, Value))
        {
            Root = AVL_Delete(Root, Value);
        }
    }

    // Final tree structure after deletions
    cout << "=== Final AVL Tree Structure ===" << endl;
    if (Root != NULL)
    {
        cout << "In-order traversal: ";
        InOrder(Root);
        cout << endl;

        cout << "Level-order traversal: ";
        PrintLevelOrder(Root);

        cout << "Tree structure:" << endl;

        cout << "Is AVL: " << (IsAVL(Root) ? "Yes" : "No") << endl;
        cout << "Tree Height: " << GetHeight(Root) << endl;
    }
    else
    {
        cout << "Tree is empty!" << endl;
    }

    return 0;
}
