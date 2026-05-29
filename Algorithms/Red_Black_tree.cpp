#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

struct Node{
    int key; Color color;
    Node *left,*right,*parent;
    Node(int k):key(k),color(RED),left(nullptr),right(nullptr),parent(nullptr){}
};

struct RBTree{
    Node* root=nullptr;

    void rotateLeft(Node* x){
        Node* y=x->right;
        x->right=y->left;
        if(y->left) y->left->parent=x;
        y->parent=x->parent;
        if(!x->parent) root=y;
        else if(x==x->parent->left) x->parent->left=y; 
        else x->parent->right=y;
        y->left=x; x->parent=y;
    }
    void rotateRight(Node* y){
        Node* x=y->left;
        y->left=x->right;

        if(x->right) x->right->parent=y;
        x->parent=y->parent;

        if(!y->parent) root=x;
        else if(y==y->parent->left) y->parent->left=x; 
        else y->parent->right=x;

        x->right=y; y->parent=x;
    }

    void insert(int key){
        Node* z=new Node(key);
        Node* y=nullptr; Node* x=root;
        while(x){
            y=x;
            x = (z->key < x->key) ? x->left : x->right;
        }
        z->parent=y;
        if(!y) root=z;
        else if(z->key < y->key) y->left=z;
        else y->right=z;
        insertFix(z);
    }

    void insertFix(Node* z){
        while(z->parent && z->parent->color==RED){
            Node* p=z->parent;
            Node* g=p->parent;
            if(p==g->left){
                Node* y=g->right; // uncle
                if(y && y->color==RED){ // Case 1
                    p->color=BLACK; y->color=BLACK; g->color=RED; z=g;
                }
                else{
                    if(z==p->right){ // Case 2
                        z=p; rotateLeft(z);
                    }
                    // Case 3
                    z->parent->color=BLACK;
                    g->color=RED;
                    rotateRight(g);
                }
            }
            else{
                Node* y=g->left;
                if(y && y->color==RED){
                    p->color=BLACK; y->color=BLACK; g->color=RED; z=g;
                }
                else{
                    if(z==p->left){
                        z=p; rotateRight(z);
                    }
                    z->parent->color=BLACK;
                    g->color=RED;
                    rotateLeft(g);
                }
            }
        }
        root->color=BLACK;
    }

    bool find(int key){
        Node* x=root;
        while(x){
            if(key==x->key) return true;
            x = (key < x->key)? x->left : x->right;
        }
        return false;
    }

    void inorder(Node* x){ if(!x) return; inorder(x->left); cout<<x->key<<"("<<(x->color==RED?'R':'B')<<") "; inorder(x->right); }

    ~RBTree(){ cleanup(root); }
    void cleanup(Node* x){ if(!x) return; cleanup(x->left); cleanup(x->right); delete x; }
};

int main(){
    RBTree t;
    for(int x: {7,3,18,10,22,8,11,26}) t.insert(x);
    t.inorder(t.root); cout<<"\n";
    cout<<"Find 10? "<<t.find(10)<<"\n";
}
