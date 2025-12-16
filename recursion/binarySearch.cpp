#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int>&arr,int st,int end,int target){
    if(st>end) return false;
    int mid=st+(end-st)/2;
    if(mid==target) return true;
    else if(target>mid){
        return binarySearch(arr,st+mid,end,target);
    }else{
        return binarySearch(arr,st,end-mid,target);
    }
}

int main(){
    vector<int>arr={1,2,3,4,5};
    
    cout<<binarySearch(arr,0,arr.size()-1,10)<<endl;
}