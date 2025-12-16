#include<iostream>
#include<climits>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high+1;
    do{
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i<j) swap(arr[i],arr[j]);
    }while(i<j);
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int j = partition(arr,low,high);
        QuickSort(arr,low,j-1);
        QuickSort(arr,j+1,high);
    }
}

int main(){
    int arr[10] = {90,5,2,-1,7,1,3,5,2};
    arr[9] = INT_MAX;
    
    QuickSort(arr,0,8);

    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
