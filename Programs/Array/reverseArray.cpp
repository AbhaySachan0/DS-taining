#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>&v){
    int i=0;
    int j=v.size()-1;
    while(i<j){
        swap(v[i],v[j]);
        i++;
        j--;
    }
}

int main(){
    vector<int>v = {1,2,3,4,5,6,7,8,9};
    reverse(v);
    for(int ele : v){
        cout<<ele<<" ";
    }
    cout<<"\n";


}