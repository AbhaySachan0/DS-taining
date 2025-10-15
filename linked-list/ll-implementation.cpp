#include <iostream>
#include <stdlib.h>
#include"mylistheader.h"

using namespace std;

void Traverse(Node *START) {
    Node *p;
	p=START;
	while(p!=NULL) {
		cout << p->info<<" ";
		p=p->Next;
	}
    cout<<endl;
}

void Reverse(Node **START){
	Node *curr=*START,*n,*prev=NULL;
	while(curr){
		n = curr->Next;
		curr->Next = prev;
		prev = curr;
		curr = n;
	}
	*START=prev;
	cout<<"Reversed : ";
}

int size(Node *START){
    int count=0;
    Node *q=START;
    while(q){
        count++;
        q=q->Next;
    }
    return count;
}

int MiddleElement1(Node *START){
	int s = size(START);
	int i=1;
	Node *p=START;
	while(i<s/2){
		p=p->Next;
		i++;
	}
	return s%2==0?p->info:p->Next->info;
}

void MiddleElement2(Node *START){
	Node *t=START,*r=START->Next;
	while(r && r->Next){
		t=t->Next;
		r=r->Next->Next;
	}
	cout<<"Middle Element is : "<<t->info<<endl;
}

void orderedInsertion(Node **START,int x){
	Node *q=NULL,*p=*START;
	while(p && x>=p->info){
		q=p;
		p=p->Next;
	}
	if(q){
		insAft(&q,x);
	} else {
		insBeg(&(*START),x);
	}
}
bool search(Node *START, int key) {
	Node *p = START;
	while (p){
		if(p->info == key)
			return true;
		p = p->Next;
	}
	return false;
}

int main() {
	struct Node *START;

	insBeg(&START,6);
	insBeg(&START,3);
	insBeg(&START,2);
	insBeg(&START,1);

	int x = size(START);
	cout<<"No of nodes are : "<< x<<endl;
	Traverse(START);

	Reverse(&START);
	
	Traverse(START);


	// cout<<"Traverse : ";
	// Traverse(START);
	// cout<<"\nAfter insertion at end : ";
	// insAtEnd(&START,4);
	// Traverse(START);
	// cout<<"\nAfter insertion at beginning : ";
	// insBeg(&START,5);
	// Traverse(START);

	// cout<<"\nAfter insertion : ";
	// insAft(&START, 6);
	
	// cout<<"\nAfter deletion from end : ";
	// delEnd(&START);
	// Traverse(START);
	// cout<<"\nAfter deletion from beginning : ";
	// delBeg(&START);
	// Traverse(START);

	// cout<<"\nAfter deletion after : ";
	// delAft(&START);



	// orderedInsertion(&START,1);
	// orderedInsertion(&START,2);
	// orderedInsertion(&START,3);
	// orderedInsertion(&START,4);
	// orderedInsertion(&START,5);

	// Traverse(START);

	// int x;
	// cout<<"Enter x to check : ";
	// cin>>x;
	// bool check = search(START,x);
	// if(check) cout<<"\nfound"<<endl;
	// else cout<<"\nNot Found"<<endl;
}