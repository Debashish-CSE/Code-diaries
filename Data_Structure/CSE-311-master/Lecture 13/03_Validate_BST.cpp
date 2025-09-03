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

void BT_Insert(Node *&Root, int Value)
{
    if (Root == NULL)
    {
        Root = new Node(Value);
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
            Temp->Left = new Node(Value);
            return;
        }
        else
        {
            Q.push(Temp->Left);
        }

        if (Temp->Right == NULL)
        {
            Temp->Right = new Node(Value);
            return;
        }
        else
        {
            Q.push(Temp->Right);
        }
    }
}

void InOrder(Node *Root, vector<int> &result)
{
    if (Root == NULL)
    {
        return;
    }

    InOrder(Root->Left, result);
    result.push_back(Root->Value);
    InOrder(Root->Right, result);
}

bool ValidateBST(Node *Root)
{
    vector<int> result;
    InOrder(Root, result);
    return is_sorted(result.begin(), result.end());
}

int main()
{
    Node *Root = NULL;

    BT_Insert(Root, 50);
    BT_Insert(Root, 30);
    BT_Insert(Root, 70);
    BT_Insert(Root, 20);
    BT_Insert(Root, 40);
    BT_Insert(Root, 60);
    BT_Insert(Root, 65);

    if (ValidateBST(Root))
    {
        cout << "The tree is a valid BST." << endl;
    }
    else
    {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
