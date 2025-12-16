#include<iostream>
using namespace std;

int getMax(int a[],int n){
    int mx=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>mx)
            mx=a[i];
    return mx;
}

void countSort(int a[],int n,int exp){
    int output[n];
    int count[10]={0};

    for(int i=0;i<n;i++)
        count[(a[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--){
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
        a[i]=output[i];
}

void radixSort(int a[],int n){
    int m=getMax(a,n);
    for(int exp=1;m/exp>0;exp*=10)
        countSort(a,n,exp);
}

int main(){
    int arr[10]={90,5,2,1,7,1,3,5,2,0};
    int n = 10;

    radixSort(arr,n);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
