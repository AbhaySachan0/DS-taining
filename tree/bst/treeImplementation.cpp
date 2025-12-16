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
    Node* p=(Node*)malloc(sizeof(Node));
    p->val=x;
    p->left=p->right=p->father=NULL;
    return p;
}

void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

Node* bstinsert(Node* root,int x){
    Node* p=root;
    Node* q=NULL;

    while(p!=NULL){
        q=p;
        if(x<p->val) p=p->left;
        else p=p->right;
    }

    Node* temp=makeNode(x);

    if(q==NULL){
        root=temp;
    }else{
        temp->father=q;
        if(x<q->val) q->left=temp;
        else q->right=temp;
    }
    return root;
}

Node* bstmin(Node* root){
    while(root && root->left)
        root=root->left;
    return root;
}

Node* bstmax(Node* root){
    while(root && root->right)
        root=root->right;
    return root;
}

Node* bstsuccessor(Node* p){
    if(p->right)
        return bstmin(p->right);

    Node* q=p->father;
    while(q && p==q->right){
        p=q;
        q=q->father;
    }
    return q;
}

Node* bstpredecessor(Node* p){
    if(p->left)
        return bstmax(p->left);

    Node* q=p->father;
    while(q && p==q->left){
        p=q;
        q=q->father;
    }
    return q;
}

Node* binarysearch(Node* root,int x){
    while(root){
        if(root->val==x) return root;
        else if(x<root->val) root=root->left;
        else root=root->right;
    }
    return NULL;
}

Node* bstdelete(Node* root,int x){
    Node* p=binarysearch(root,x);
    if(p==NULL) return root;

    Node* y;
    Node* z;

    if(p->left==NULL || p->right==NULL)
        y=p;
    else
        y=bstsuccessor(p);

    if(y->left!=NULL)
        z=y->left;
    else
        z=y->right;

    if(z!=NULL)
        z->father=y->father;

    if(y->father==NULL)
        root=z;
    else if(y==y->father->left)
        y->father->left=z;
    else
        y->father->right=z;

    if(y!=p)
        p->val=y->val;

    free(y);
    return root;
}


int main(){
    Node* root=NULL;

    root=bstinsert(root,100);
    root=bstinsert(root,20);
    root=bstinsert(root,50);
    root=bstinsert(root,70);
    root=bstinsert(root,150);
    root=bstinsert(root,200);
    root=bstinsert(root,40);

    inOrder(root);
    cout<<endl;

    Node* mn=bstmin(root);
    Node* mx=bstmax(root);

    cout<<"min is : "<<mn->val<<endl;
    cout<<"max is : "<<mx->val<<endl;

    // Node* p=binarysearch(root,40);
    // if(p){
    //     Node* s=bstsuccessor(p);
    //     Node* pr=bstpredecessor(p);
    //     if(s) cout<<"successor of 40 : "<<s->val<<endl;
    //     if(pr) cout<<"predecessor of 40 : "<<pr->val<<endl;
    // }

    root=bstdelete(root,50);
    cout<<"after deletion";
    inOrder(root);
}
