#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<vector<int>>& v,int start){
    int j = 0;
    int end = v[start].size()-1;

    while(j<end){
        swap(v[start][j],v[start][end]);
        j++;
        end--;
    }
}
int main(){
    vector<vector<int>> vec(4, vector<int>(4));
    int value = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            vec[i][j] = value++;
        }
    }
    
    for(int i=0;i<4;i++){
        reverse(vec,i);
    }

    // transpose 
    
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            swap(vec[i][j],vec[j][i]);
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}