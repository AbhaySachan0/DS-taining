#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int info;
    node *prev,*next;
};

struct Deque{
    node *front,*rear;
}Queue;

node* GetNode(int x){
    node* p=(node*)malloc(sizeof(node));
    p->info=x;
    p->prev=p->next=NULL;
    return p;
}

void InsertLeft(int x){
    node* p=GetNode(x);
    if(Queue.front==NULL)
        Queue.front=Queue.rear=p;
    else{
        p->next=Queue.front;
        Queue.front->prev=p;
        Queue.front=p;
    }
}

void InsertRight(int x){
    node* p=GetNode(x);
    if(Queue.rear==NULL)
        Queue.front=Queue.rear=p;
    else{
        p->prev=Queue.rear;
        Queue.rear->next=p;
        Queue.rear=p;
    }
}

void DeleteLeft(){
    if(Queue.front==NULL){
        cout<<"Deque is empty\n";
        return;
    }
    node* temp=Queue.front;
    Queue.front=Queue.front->next;
    if(Queue.front!=NULL)
        Queue.front->prev=NULL;
    else
        Queue.rear=NULL;
    free(temp);
}

void DeleteRight(){
    if(Queue.rear==NULL){
        cout<<"Deque is empty\n";
        return;
    }
    node* temp=Queue.rear;
    Queue.rear=Queue.rear->prev;
    if(Queue.rear!=NULL)
        Queue.rear->next=NULL;
    else
        Queue.front=NULL;
    free(temp);
}

void Traverse(){
    node* temp=Queue.front;
    while(temp){
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Queue.front=NULL;
    Queue.rear=NULL;

    InsertLeft(10);
    InsertLeft(20);
    InsertRight(30);
    InsertRight(40);
    cout<<"elements after inserting on left and right : ";
    Traverse();

    DeleteLeft();
    DeleteRight();

    cout<<"elements after deleting from left and right : ";

    Traverse();
    return 0;
}
