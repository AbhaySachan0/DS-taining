#include <iostream>
using namespace std;

void insertAt(int arr[],int &n,int pos,int val){
    for(int i=n;i>pos;i--) {
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    n++;
}

int deleteBeg(int arr[],int &n){
    int x=arr[0];
    for(int i=0;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    n--;
    return x;
}

void EnqueueAsc(int arr[], int &n, int x){
    int i=0;
    while(i<n && arr[i]<=x) i++;
    insertAt(arr,n,i,x);
}

int DequeueAsc(int arr[], int &n){
    return deleteBeg(arr,n);
}

int deleteAt(int arr[],int &n,int pos){
    int x=arr[pos];
    for(int i=pos;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    n--;
    return x;
}

//for descending

void EnqueueDec(int arr[], int &n, int x){
    int i=0;
    while(i<n && arr[i]>x) i++;
    insertAt(arr,n,i,x);
}

int DequeueDec(int arr[], int &n){
    return deleteAt(arr,n,n);
}


int main(){
    int capacity = 100, arr[100], n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter element to insert: ";
    cin >> k;
    EnqueueAsc(arr,n,k);


    cout << "queue elements are : ";
    for(int i = 0; i < n; i++) cout << arr[i]<<" ";
    return 0;
}
