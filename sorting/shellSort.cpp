#include<iostream>
using namespace std;

void shellSort(int a[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i;
            while(j>=gap && a[j-gap]>temp){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=temp;
        }
    }
}

int main(){
    int arr[10]={90,5,2,-1,7,1,3,5,2,0};
    int n = 10;

    shellSort(arr,n);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
