#include<iostream>
#include<climits>
using namespace std;

int c[10];

void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            c[k] =arr[i];
            i++;
            k++;
        }else{
            c[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        c[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        c[k]=arr[j];
        j++;
        k++;
    }
    for(int m=low;m<=high;m++){
        arr[m] = c[m];
    }
}

void MergeSort(int arr[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[10] = {90,5,2,-1,7,1,3,5,2,0};
    
    MergeSort(arr,0,9);

    for(int i=0;i<=9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


