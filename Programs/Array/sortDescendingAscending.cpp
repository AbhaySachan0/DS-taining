#include<iostream>
using namespace std;

int main(){
    int n = 12;
    int arr[n];
    int i=0;
    int j=n-1;
    for(int k=1;k<=n;k++){
        if(k%2==0) {
            arr[j] = k;
            j--;
        } else {
            arr[i] = k;
            i++;
        }
    }

    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<"\n";

}