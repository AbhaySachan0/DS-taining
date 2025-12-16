#include <iostream>
using namespace std;
void insertionSort(int arr[]){
    for(int i=0; i<13; i++){
        int k=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }

}
int main(){
    int arr[13]={15, 9, 12, 8, 1, 6, 5, -2, 7, 10, 4, 20, 2};
    insertionSort(arr);
    for(int i=0; i<13; i++){
        cout << arr[i] << " ";
    }
}