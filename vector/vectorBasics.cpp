#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // v.push_back(10);
    // v.push_back(10);
    // v.push_back(10);
    // cout<<v.size()<<endl;
    // for(auto ele : v){
        //     cout<<ele<<" ";
        // }
        // cout<<endl;
        // v.pop_back();
        // v.pop_back();
        // v.pop_back();
        // cout<<v.capacity()<<endl;
        
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // cout<<"Array elements are:";
    // for(auto ele : v) {
    //     cout<<ele<<" ";
    // }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    cout<<endl;
 
}
