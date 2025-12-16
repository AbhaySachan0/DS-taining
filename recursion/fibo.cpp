#include<iostream>
using namespace std;

int fibo(int n,int a,int b,int sum){
    cout<<a<<" ";
    if(n==1 || n==2){
        return b;
    }
    sum = a + b;
    a = b;
    b = sum;
    return fibo(n-1,a,b,sum);
}

int fibo(int n){
    if(n<=2) return n-1;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    // cout<<fibo(n,1,1,0)<<endl;
    cout<<fibo(n)<<endl;
    return 0;
    
}