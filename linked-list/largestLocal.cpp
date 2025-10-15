#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>grid={{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};


    for(int i=0;i<grid.size()-2;i++){
        
        for(int j=1;j<4;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

