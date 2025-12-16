#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){

    for(int i=0;i<n-2;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            } 
        }
        swap(arr[i],arr[min]);
    }
}

int main(){
    int arr[10] = {90,5,2,-1,7,1,3,5,2,0};
    
    selectionSort(arr,10);

    for(int i=0;i<=9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}