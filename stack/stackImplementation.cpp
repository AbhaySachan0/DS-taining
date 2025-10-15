#include<iostream>
#define STACKSIZE 10
using namespace std;

struct stk{
    int item[STACKSIZE];
    int top;
};

void Initialize(stk &S){
    S.top = -1;
}

bool isEmpty(stk &S){
    return S.top == -1;
}

void push(stk &S, int x){
    if(S.top == STACKSIZE - 1) {
        cout << "Stack Overflows" << endl;
        return;
    }
    S.top++;
    S.item[S.top] = x;
}

int pop(stk &S){
    if(S.top == -1) {
        cout << "Stack Underflows" << endl;
        exit(1);
    }
    int x = S.item[S.top];
    S.top--;
    return x;
}

int stackTop(stk &S){
    if(S.top == -1) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    return S.item[S.top];
}

void BalancedBracket(char exp[]){
    stk S;
    Initialize(S);
    int i = 0,flag=0;
    while(exp[i] != '\0'){
        if(exp[i] == '(') {
            push(S, exp[i]);
        }
        else{
            if(!isEmpty(S)) pop(S);
            else{
                flag=1;
                break;
            }
        }
        i++;
    }
    if(isEmpty(S) && flag==0) cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
}
int main(){


    char exp[10];
    cout<<"Enter Expression : ";
    cin>>exp;
    BalancedBracket(exp);


    // push(100);
    // push(200);
    // push(300);
    // push(400);
    // push(500);
    // push(600);

    // cout<<"All Pushed..."<<endl;
    // cout<<"Top popped : "<<pop()<<endl;
    // cout<<"Stack top : "<<stackTop()<<endl; 

}