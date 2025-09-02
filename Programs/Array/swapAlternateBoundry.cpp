#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i=0;
    int j=n-1;

    while(i<j){
        // swap(arr[i],arr[j]);
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j -= 2;
        i += 2;
    }

    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<"\n";

}