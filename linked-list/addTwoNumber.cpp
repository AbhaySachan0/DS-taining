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

int main() {
	struct Node *START1;
	struct Node *START2;

	insAtEnd(&START1,1);
	insAtEnd(&START1,2);
	insAtEnd(&START1,3);
	insAtEnd(&START1,4);

    insAtEnd(&START2,1);
	insAtEnd(&START2,2);
	insAtEnd(&START2,3);
	insAtEnd(&START2,4);

    Traverse(START1);

}