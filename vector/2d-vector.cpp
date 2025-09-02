#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){ 
    vector<int> v1(3,1);    
    vector<int> v2(4,2);    
    vector<int> v3(5,3);    
    vector<vector<int>>vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    
    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++){
            cout<<vv[i][j];
        }
    }
}
