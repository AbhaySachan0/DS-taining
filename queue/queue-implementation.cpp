#include <iostream>
#include <stdlib.h>
#define MAXQUEUE 10
using namespace std;

struct Queue {
    int item[MAXQUEUE];
    int front;
    int rear;
};

void Initialize(Queue *Q) {
    Q->rear = -1;
    Q->front = 0;
}

bool isEmpty(Queue Q) {
    return (Q.rear - Q.front +1) ==0;
}

void enQueue(Queue *Q, int x) {
    if (Q->rear == MAXQUEUE - 1)
        cout << "Queue Overflow\n";
    else {
        Q->rear++;
        Q->item[Q->rear] = x;
    }
}

int deQueue(Queue *Q) {
    if(isEmpty(*Q)) {
        cout<<"Queue Underflow\n";
        return -1;
    }else{
        int x=Q->item[Q->front];
        Q->front++;
        return x;
    }
}

void Traverse(Queue *Q) {
    if (isEmpty(*Q)) {
        cout << "Queue is empty\n";
        return;
    }
    for(int i=Q->front;i<=Q->rear;i++){
        cout<<Q->item[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Queue q;
    Initialize(&q);

    enQueue(&q, 5);
    enQueue(&q, 10);
    enQueue(&q, 15);

    cout<<"Queue elements: ";
    Traverse(&q);

    cout<<"Dequeued: " << deQueue(&q) << endl;
    cout<<"After dequeue: ";
    Traverse(&q);

    return 0;
}
