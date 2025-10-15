#include <iostream>
using namespace std;

void traverse(int arr[],int n){
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int deleteAt(int arr[],int &n,int pos){
    int x=arr[pos];
    for(int i=pos;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    n--;
    return x;
}
void insertAt(int arr[],int &n,int pos,int val){
    for(int i=n;i>pos;i--) {
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    n++;
}


int main(){
    int arr[100],n;
    cout<<"\nEnter size: ";cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    // cout<<"before : ";
    traverse(arr,n);

    // int x = deleteAt(arr,n,3);
    // insertAt(arr,n,2,4);

    // cout<<"\nAfter : ";
    // traverse(arr,n);
}


