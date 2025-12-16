#include<iostream>
using namespace std;

int reverse(int n,int reversed=0){
    if(n==0) return reversed;
    return reverse(n/10,reversed=(reversed)*10+n%10);
}

int main(){
    int n;
    cout<<"Enter N : ";
    cin>>n;

    cout<<"reversed : "<<reverse(n)<<endl;
}