#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int main(){
    int mx = INT_MIN;
    vector<int>v = {7,1,2,3,1,2,3,1,2,4,5,5,4,1};

    for(int i=0;i<v.size();i++){
        if(v[i]>mx){
            mx = v[i];
        }
    }

    cout<<mx<<endl;
}