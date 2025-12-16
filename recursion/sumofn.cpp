#include<iostream>
using namespace std;

int sum(int n){
    if(n==0) return 0;
    return n+ sum(n-1);
}

int main(){
    int n;
    cout<<"Enter N : ";
    cin>>n;
    cout<<"sum : "<<sum(n)<<endl;
}