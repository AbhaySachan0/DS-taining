#include<iostream>
#include<cctype>
using namespace std;

struct Node{
    char data;
    Node *left,*right;
};

Node* newNode(char x){
    Node* p=new Node;
    p->data=x;
    p->left=p->right=NULL;
    return p;
}

int isOperator(char x){
    return (x=='+'||x=='-'||x=='*'||x=='/'||x=='^');
}

Node* buildExpressionTree(char postfix[]){
    Node* st[50];
    int top=-1;

    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];

        if(isalnum(ch)){
            st[++top]=newNode(ch);
        }
        else if(isOperator(ch)){
            Node* r=st[top--];
            Node* l=st[top--];

            Node* p=newNode(ch);
            p->left=l;
            p->right=r;

            st[++top]=p;
        }
    }
    return st[top];
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    char postfix[50];
    cout<<"Enter postfix expression: ";
    cin>>postfix;

    Node* root=buildExpressionTree(postfix);

    cout<<"Inorder traversal: ";
    inorder(root);
}
