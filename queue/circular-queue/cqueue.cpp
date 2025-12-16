#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAXQUEUE 10
struct CQueue{
    char item[MAXQUEUE];
    int FRONT;
    int REAR;
};

void initialise(CQueue *Q){
  Q->REAR=MAXQUEUE-1;
  Q->FRONT=MAXQUEUE-1;
}
bool IsEmpty(CQueue *Q){
   if(Q->FRONT==Q->REAR)
    return true;
   else
    return false;
}

void Enqueue(CQueue *Q, char x){
  if((Q->REAR+1)%MAXQUEUE==Q->FRONT){
    cout << "Circular Queue Overflows";
    exit(1);
  }
  else{
    Q->REAR=(Q->REAR+1)%MAXQUEUE;
    Q->item[Q->REAR]=x;
  }
}
char Dequeue(CQueue *Q){
    if(IsEmpty(Q)){
        cout << "Circular Queue underflows" ;
        exit(1);
    }
    else{
        Q->FRONT=(Q->FRONT+1)%MAXQUEUE;
        char x=Q->item[Q->FRONT];
        return x;
    }
}

void Traverse(CQueue *Q){
    if(IsEmpty(Q)){
        cout<<"Queue is empty\n";
        return;
    }
    int i=Q->FRONT;
    while(true){
        cout<<Q->item[i]<<" ";
        if(i==Q->REAR) break;
        i=(i+1)%MAXQUEUE;
    }
    cout<<endl;
}

int main(){
    CQueue Q;
    initialise(&Q);
    Enqueue(&Q, 'A');
    Enqueue(&Q, 'B');
    Enqueue(&Q, 'C');
    Enqueue(&Q, 'D');
    Enqueue(&Q, 'E');

    cout<<"CQueue elements are : " ;
    Traverse(&Q);
    char x=Dequeue(&Q);
    cout << "Deleted item: " << x << "\n";
   
}