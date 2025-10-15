#include<iostream>
#include"mylistheader.h"
using namespace std;
void initialize(Node* front,Node* rear){
    front = NULL;
    rear = NULL;
}

void EnQueue(Node*front,Node*rear,int x){
    Node* p = GetNode();
    p->info = x;
    p->Next = NULL;
    if(rear!=NULL) rear->Next = p;
    else front=p;
    rear = p;
}

int DeQueue(Node*front,Node*rear){
    if(front){
        cout<<"Queue Underflows"<<endl;
        return -1;
    }else{
        Node* p = front;
        front = front->Next;
        if(front) rear = NULL;
        int x=p->info;
        FreeNode(p);
        return x;
    }
}

void Traverse(Node *START) {
    Node *p;
	p=START;
	while(p!=NULL) {
		cout << p->info<<" ";
		p=p->Next;
	}
    cout<<endl;
}

int main(){
    Node *front;
    Node* rear;
    initialize(front,rear);
    EnQueue(front,rear,5);
    EnQueue(front,rear,6);
    EnQueue(front,rear,7);
    Traverse(front);

}