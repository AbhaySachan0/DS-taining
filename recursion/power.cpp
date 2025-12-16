#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==0) return 1;
    if(a==0) return 0;
    if(b==1) return a;
    int x = power(a,b/2);
    if(b%2==0){
        return x*x;
    }else{
        return x*x*a;
    }
}

int main(){
    int a,b;
    cout<<"Enter base : ";
    cin>>a;
    cout<<"Enter power : ";
    cin>>b;

    cout<<a<<" raise to "<<b<<" is "<<power(a,b)<<endl;
    return 0;
}