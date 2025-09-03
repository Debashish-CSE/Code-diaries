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

Node *getParent(Node *Root, Node *node);

void swap(Node *A, Node *B)
{
    int Temp = A->Value;
    A->Value = B->Value;
    B->Value = Temp;
}

void heapifyUp(Node *Root, Node *node)
{
    while (node != Root)
    {
        Node *Parent = getParent(Root, node);
        if (Parent && (Parent->Value < node->Value))
        {
            swap(Parent, node);
            node = Parent;
        }
        else
        {
            break;
        }
    }
}

Node *getParent(Node *Root, Node *node)
{
    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty())
    {
        Node *Current = Q.front();
        Q.pop();

        if ((Current->Left == node || Current->Right == node))
        {
            return Current;
        }

        if (Current->Left)
        {
            Q.push(Current->Left);
        }
        if (Current->Right)
        {
            Q.push(Current->Right);
        }
    }
    return NULL;
}

void Insert(Node *&Root, int value)
{
    Node *newNode = new Node(value);
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
            heapifyUp(Root, newNode);
            return;
        }
        else
        {
            Q.push(Temp->Left);
        }

        if (Temp->Right == NULL)
        {
            Temp->Right = newNode;
            heapifyUp(Root, newNode);
            return;
        }
        else
        {
            Q.push(Temp->Right);
        }
    }
}

void printHeap(Node *Root)
{
    if (Root == NULL)
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty())
    {
        Node *Current = Q.front();
        Q.pop();

        cout << Current->Value << " ";

        if (Current->Left)
        {
            Q.push(Current->Left);
        }
        if (Current->Right)
        {
            Q.push(Current->Right);
        }
    }
    cout << endl;
}

void heapifyDown(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty())
    {
        Node *Current = Q.front();
        Q.pop();

        Node *Largest = Current;
        if (Current->Left && Current->Left->Value > Largest->Value)
        {
            Largest = Current->Left;
        }
        if (Current->Right && Current->Right->Value > Largest->Value)
        {
            Largest = Current->Right;
        }

        if (Largest != Current)
        {
            swap(Largest, Current);
            Q.push(Largest);
        }

        if (Current->Left)
        {
            Q.push(Current->Left);
        }
        if (Current->Right)
        {
            Q.push(Current->Right);
        }
    }
}

void deleteRoot(Node *&Root)
{
    if (Root == NULL)
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    if (Root->Left == NULL && Root->Right == NULL)
    {
        delete Root;
        Root = NULL;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);
    Node *LastNode = NULL;

    while (!Q.empty())
    {
        Node *Temp = Q.front();
        Q.pop();
        LastNode = Temp;

        if (Temp->Left)
        {
            Q.push(Temp->Left);
        }
        if (Temp->Right)
        {
            Q.push(Temp->Right);
        }
    }

    Root->Value = LastNode->Value;

    Node *Parent = NULL;
    Q.push(Root);

    while (!Q.empty())
    {
        Node *Temp = Q.front();
        Q.pop();

        if (Temp->Left == LastNode || Temp->Right == LastNode)
        {
            Parent = Temp;
            break;
        }

        if (Temp->Left)
        {
            Q.push(Temp->Left);
        }
        if (Temp->Right)
        {
            Q.push(Temp->Right);
        }
    }
    if (Parent)
    {
        if (Parent->Left == LastNode)
        {
            Parent->Left = NULL;
        }
        else
        {
            Parent->Right = NULL;
        }
    }

    delete LastNode;

    heapifyDown(Root);
}

int main()
{
    Node *Root = NULL;

    Insert(Root, 10);
    Insert(Root, 20);
    Insert(Root, 5);
    Insert(Root, 30);
    Insert(Root, 15);
    Insert(Root, 25);
    Insert(Root, 8);

    cout << "Max Heap (Level-order): ";
    printHeap(Root);

    deleteRoot(Root);

    cout << "Max Heap after deleting the root: ";
    printHeap(Root);

    return 0;
}
