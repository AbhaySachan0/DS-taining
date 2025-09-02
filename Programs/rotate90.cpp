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
    vector<vector<int>> vec(3, vector<int>(3));
    int value = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vec[i][j] = value++;
        }
    }
// transpose 

    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            swap(vec[i][j],vec[j][i]);
        }
    }

    for(int i=0;i<3;i++){
        reverse(vec,i);
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}