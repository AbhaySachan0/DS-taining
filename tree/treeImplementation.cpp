#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* makeNode(int x){
    Node * p;
    p = (Node*)malloc(sizeof(Node));
    p->val = x;
    p->left=NULL;
    p->right=NULL;
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

void createNode(Node **t){
    cout<<(*t)->val<<"->left exists? (1/0) : ";
    int ch;
    cin>>ch;
    if(ch==1){
        int value;
        cout<<"value : ";
        cin>>value;
        (*t)->left = makeNode(value);
        createNode(&(*t)->left);
    }

    cout<<(*t)->val<<"->right exists? (1/0) : ";
    cin>>ch;
    if(ch==1){
        int value;
        cout<<"value : ";
        cin>>value;
        (*t)->right = makeNode(value);
        createNode(&(*t)->right);
    }

}

int countNode(Node* root){
    if(root==NULL) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

int height(Node* root){
    if(root==NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}

int nodesWithOneChildren(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    if(root->left != NULL && root->right !=NULL){
        return nodesWithOneChildren(root->left) + nodesWithOneChildren(root->right);
    }
    return 1 + nodesWithOneChildren(root->left) + nodesWithOneChildren(root->right);

}

int nodesWithTwoChildren(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    if(root->left != NULL && root->right !=NULL){
        return 1 + nodesWithTwoChildren(root->left) + nodesWithTwoChildren(root->right);
    }
    return nodesWithTwoChildren(root->left) + nodesWithTwoChildren(root->right);

}

int countLeaf(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

bool isStritctBinaryTree(Node* root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left !=NULL && root->right!=NULL){
        return isStritctBinaryTree(root->left) && isStritctBinaryTree(root->right);
    }
    return false;
}

bool isComplete(Node* root){
    if(root==NULL) return true;

    int l = height(root->left);
    int r = height(root->right);

    if(l!=r) return false;
    return isComplete(root->left) && isComplete(root->right);
}

int main(){
    // cout<<"root -> val? :";
    // int value;
    // cin>>value;
    // Node * t = makeNode(value);
    // createNode(&t);

    Node* root = makeNode(10);

    root->left = makeNode(11);
    root->right = makeNode(12);

    root->left->left = makeNode(13);
    root->left->right = makeNode(14);

    root->right->left = makeNode(15);
    root->right->right = makeNode(16);

    root->left->left->left = makeNode(17);
    root->left->left->right = makeNode(18);

    root->left->right->left = makeNode(19);
    root->left->right->right = makeNode(20);

    root->right->left->left = makeNode(21);
    root->right->left->right = makeNode(22);

    root->right->right->left = makeNode(23);
    root->right->right->right = makeNode(24);
    cout<<"Pre order : ";
    preOrder(root);
    cout<<endl;

    cout<<"In order : ";
    inOrder(root);
    cout<<endl;

    cout<<"Post order : ";
    postOrder(root);
    cout<<endl;

    cout<<"Count of Nodes : "<<countNode(root)<<endl;
    cout<<"height of Nodes : "<<height(root)<<endl;
    cout<<"No of nodes with one children is : "<<nodesWithOneChildren(root)<<endl;
    cout<<"No of nodes with two children is : "<<nodesWithTwoChildren(root)<<endl;
    cout<<"No of leaf Nodes : "<<countLeaf(root)<<endl;
    cout<<"Is stritcly binary tree : "<<isStritctBinaryTree(root)<<endl;
    cout<<"Is complete binary tree : "<<isComplete(root)<<endl;

}