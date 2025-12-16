#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    bool flag = true;
    for(int i=0;i<n-2 && flag==true;i++){
        flag = false;
        for(int j=0;j<n-i-2;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            } 
        }
    }
}

int main(){
    int arr[10] = {90,5,2,-1,7,1,3,5,2,0};
    
    bubbleSort(arr,10);

    for(int i=0;i<=9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}