#include<iostream>
#include<math.h>
#define STACKSIZE 10
using namespace std;

struct stk{
    int item[STACKSIZE];
    int top=-1;
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

int evaluate(int x, int y, char symbol) {
    switch(symbol) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '^': return pow(x, y);
        default: 
            cout << "Invalid operator" << endl;
            exit(1);
    }
}


void prefix(char exp[]){
    int i=0;
    while(exp[i]!='\0'){
        i++;
    }
    i -= 1;
    while(i>=0){
        char symbol = exp[i];
        if(symbol>='0' && symbol<='9') push(symbol-'0');
        else{
            int x=pop();
            int y=pop();
            int value=evaluate(x,y,symbol);
            push(value);

        }
        i--;
    }
    cout<<pop()<<endl;
}


void postfix(char exp[]){
    int i=0;
    while(exp[i]!='\0'){
        char symbol = exp[i];
        if(symbol>='0' && symbol<='9') push(symbol-'0');
        else{
            int y=pop();
            int x=pop();
            int value=evaluate(x,y,symbol);
            push(value);
        }
        i++;
    }
    cout<<pop()<<endl;
}



int main(){
    char expression[30];
    cin>>expression;
    // prefix(expression);
    postfix(expression);

}