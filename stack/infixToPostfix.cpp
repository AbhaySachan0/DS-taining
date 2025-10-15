#include<iostream>
#include<vector>
#include<math.h>
#define STACKSIZE 30
using namespace std;

struct stk{
    char item[STACKSIZE];
    int top=-1;
};
struct stk S;

// void Initialize(){
//     S.top = -1;
// }

bool isEmpty(){
    return S.top==-1;
}

void push(char x){

    if(S.top==STACKSIZE-1) {
        cout<<"Stack Overflows"<<endl;
        return;
    }
    S.top++;
    S.item[S.top] = x;
}

char pop(){
    if(S.top==-1) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }

    char x = S.item[S.top];
    S.top--;
    return x;
}

char stackTop(){
    return S.item[S.top];
}

bool pre(char op1,char op2){
    if(op1=='(' || op2=='(') return false;
    else if(op2==')') return true;
    else if(op1=='^'|| op1=='*' || op1=='/' ){
        if(op2=='^') return false;
        return true;
    } else{
        if(op2=='+' || op2=='-') return true;
        return false;
    }
}

void infixToPostfix(char exp[]){
    string postfix="";
    int i=0;
    while(exp[i]!='\0'){
        char symbol = exp[i];
        if(symbol>='a' && symbol<='z' || symbol>='A' && symbol<='Z'){
            postfix += symbol;
        } else if(symbol == '('){
            push(symbol);
        }
        else if(symbol == ')'){
            while(!isEmpty() && stackTop() != '('){
                postfix += pop();
            }
            if(!isEmpty()) pop();
        }
        else { 
            while(!isEmpty() && pre(symbol, stackTop())){
                postfix += pop();
            }
            push(symbol);
        }
        i++;
    }
    while(!isEmpty()){
        char x = pop();
        postfix.push_back(x);
    }

    cout<<postfix;
    cout<<endl;
}


int main(){
    char infix[30];
    cout<<"Infix Expression : ";
    cin>>infix;
    infixToPostfix(infix);    

}