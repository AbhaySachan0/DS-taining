#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>v = {7,1,2,3,1,2,3,1,2,4,5,5,4,1};

    vector<int>check(10,0);
    for(int i=0;i<v.size();i++){
        check[v[i]] += 1;
    }

    for(int i=0;i<check.size();i++){
        if(check[i]%2 != 0 ) cout<<i<<" ";
    }

    cout<<"\n";
}