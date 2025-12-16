#include<iostream>
using namespace std;

int sum(int n){
    if(n<=0) return n;
    return n%10 + sum(n/10);
}

int main(){
    int n;
    cout<<"Enter N : ";
    cin>>n;
    cout<<"Sum : "<<sum(n)<<endl;
}