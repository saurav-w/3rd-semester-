#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    int height;
};

int height(Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}

Node* createNode(int data){
    Node* node=new Node();
    node->data=data;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}

/* Right Rotation (LL) */
Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

/* Left Rotation (RR) */
Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

int getBalance(Node* n){
    if(n==NULL)
        return 0;
    return height(n->left)-height(n->right);
}

Node* insert(Node* node,int key){

    if(node==NULL)
        return createNode(key);

    if(key < node->data)
        node->left=insert(node->left,key);
    else if(key > node->data)
        node->right=insert(node->right,key);
    else
        return node;

    node->height=1+max(height(node->left),height(node->right));

    int balance=getBalance(node);

    /* LL Rotation */
    if(balance>1 && key < node->left->data)
        return rightRotate(node);

    /* RR Rotation */
    if(balance<-1 && key > node->right->data)
        return leftRotate(node);

    /* LR Rotation */
    if(balance>1 && key > node->left->data){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    /* RL Rotation */
    if(balance<-1 && key < node->right->data){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    Node* root=NULL;
    int n,val;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter values:\n";
    for(int i=0;i<n;i++){
        cin>>val;
        root=insert(root,val);
    }

    cout<<"Inorder traversal of AVL Tree:\n";
    inorder(root);

    return 0;
}
