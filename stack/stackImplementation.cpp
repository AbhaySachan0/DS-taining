#include<iostream>
#define STACKSIZE 10
using namespace std;

struct stk{
    int item[STACKSIZE];
    int top = -1;
};
struct stk S;

// void Initialize(){
//     S.top = -1;
// }

bool isEmpty(){
    return S.top==-1;
}

void push(int x){

    if(S.top==STACKSIZE-1) {
        cout<<"Stack Overflows"<<endl;
        return;
    }
    S.top++;
    S.item[S.top] = x;
}

int pop(){
    if(S.top==-1) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }

    int x = S.item[S.top];
    S.top--;
    return x;
}

int stackTop(){
    return S.item[S.top];
}

int main(){

    push(100);
    push(200);
    push(300);
    // push(400);
    // push(500);
    // push(600);

    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;

}