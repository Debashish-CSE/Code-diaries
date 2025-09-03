#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int Value;
    Node *Left;
    Node *Right;
    Node(int Value){
        this->Value = Value;
        this->Left = NULL;
        this->Right = NULL;
    }
};

class BST{
private:
    Node *Root;

    Node* insert(Node *root, int val){
        if(root == NULL){
            return new Node(val);
        }
        if(val < root->Value){
            root->Left = insert(root->Left, val);
        }
        else if(val > root->Value){
            root->Right = insert(root->Right, val);
        }
        return root;
    }

    bool search(Node *root, int val){
        if(root == NULL) return false;
        if(root->Value == val) return true;
        if(val < root->Value) return search(root->Left, val);
        else return search(root->Right, val);
    }

    void inorder(Node *root, vector<int> &order){
        if(root == NULL) return;
        inorder(root->Left, order);
        order.push_back(root->Value);
        inorder(root->Right, order);
    }

    bool validate(Node *root){
        vector<int> order;
        inorder(Root, order);
        return is_sorted(order.begin(), order.end());
    }
public:
    BST(){
        Root = NULL;
    }
    void insert(int val){
        Root = insert(Root, val);
    }
    bool search(int val){
        return search(Root, val);
    }
    void inorder(vector<int> &order){
        inorder(Root, order);
    }

    bool validate(){
        return validate(Root);
    }
};

int main(){

    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    vector<int> order;

    cout << "Inorder traversal: ";
    tree.inorder(order);
    for(int val: order){
        cout << val << " ";
    }
    cout << endl;

    if (tree.validate())
        cout << "This is a valid BST.\n";
    else
        cout << "This is NOT a valid BST.\n";

    return 0;
}