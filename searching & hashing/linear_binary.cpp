#include<iostream>
using namespace std;

int linearSearch(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int lo,int hi,int key){
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) hi = mid-1;
        else lo = mid+1;
    }
    return -1;

}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 7;
    cout<<"Element found at index : "<<linearSearch(arr,key,n)<<endl;
    cout<<"Element found at index : "<<binarySearch(arr,0,n-1,key)<<endl;

}