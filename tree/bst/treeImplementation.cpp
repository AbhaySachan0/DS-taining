#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node* father;
};

Node* makeNode(int x){
    Node * p;
    p = (Node*)malloc(sizeof(Node));
    p->val = x;
    p->left=NULL;
    p->right=NULL;
    p->father = NULL;
    return p;
}

void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

Node* bstinset(Node* root,int x){
    Node* p = root;
    Node* q = NULL;
    while(p!=NULL){
        q=p;
        if(p->val>x) p=p->left;
        else p=p->right;
    }
    Node* temp = makeNode(x);
    if(q==NULL){
        root = temp;
    }else{
        p->father=q;
        if(q->val>x) q->left = temp;
        else q->right = temp;
    }
    return root;
}

Node* bstmin(Node* root){
    while(root->left!=NULL) root=root->left;
    return root;
}

Node* bstmax(Node* root){
    while(root->right!=NULL) root=root->right;
    return root;
}

Node* bstsuccessor(Node* p){
    if(p->right!=NULL) return bstmin(p->right);

    Node* q=p->father;
    while(q && q->right==p){
        p=q;
        p=q->father;
    }
    return q;
}

Node* bstpredessor(Node* p){
    if(p->left!=NULL) return bstmax(p->left);

    Node* q=p->father;
    while(q && q->left==p){
        p=q;
        p=q->father;
    }
    return q;
}

Node* binarysearch(Node* root,int x){
    while(root){
        if(root->val==x) return root;
        else if(root->val>x) root = root->left;
        else root = root->right;
    }
    return NULL;
}

int main(){
    Node* root = NULL;
    root = bstinset(root,100);
    root = bstinset(root,20);
    root = bstinset(root,50);
    root = bstinset(root,70);
    root = bstinset(root,150);
    root = bstinset(root,200);
    root = bstinset(root,40);

    inOrder(root);

    cout<<endl;

    Node* p = bstmin(root);
    Node* q = bstmax(root);

    cout<<"min is : "<<p->val<<endl;
    cout<<"max is : "<<q->val<<endl;


    p = binarysearch(root,40);
}