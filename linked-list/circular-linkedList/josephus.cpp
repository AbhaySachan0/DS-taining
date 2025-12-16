#include<iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};
Node* GetNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}
void InsBeg(Node*& CSTART, int x) {
    Node* p = GetNode(x);
    if (CSTART == NULL) {
        p->next = p;
        CSTART = p;
    } else {
        p->next = CSTART->next;
        CSTART->next = p;
    }
}

void InsAft(Node* Q, int x) {
    if (Q == NULL) return;
    Node* p = GetNode(x);
    p->next = Q->next;
    Q->next = p;
}

void InsEnd(Node*& CSTART, int x) {
    Node* p = GetNode(x);
    if (CSTART == NULL) {
        p->next = p;
        CSTART = p;
    } else {
        p->next = CSTART->next;
        CSTART->next = p;
        CSTART = p;
    }
}
void DelBeg(Node*& CSTART) {
    if (CSTART == NULL) return;
    Node* p = CSTART->next;
    if (CSTART == p) {
        delete p;
        CSTART = NULL;
    } else {
        CSTART->next = p->next;
        delete p;
    }
}

void josephus(Node* head,int k){
    Node* prev = head;
    Node* temp = head;
    while(temp->next!=temp){
        for(int i=1;i<k;i++){
            prev = temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp=temp->next;
    }

    cout<<temp->info<<endl; 
}



int main(){
    Node* CSTART = NULL;

    InsBeg(CSTART, 10);
    InsBeg(CSTART, 20);
    InsBeg(CSTART, 30);
    InsBeg(CSTART, 40);

    josephus(CSTART,4);


    
}