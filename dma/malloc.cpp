#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    int *ptr;
    int x=10;
    int n;
    cin>>n;
    ptr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        *(ptr+i)=x;
        x += 10;
    }
    for(int i=0;i<n;i++){
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
}