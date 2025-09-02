#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool cmp(int x,int y){
    if(x%2==0 && y%2==0) return x>y;
    if(x%2==0 && y%2!=0) return true;
    if(x%2!=0 && y%2==0) return false;
    return x<y;  // both odd
}
int main(){ 
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end(),cmp);
    cout<<"After sorting : ";
    for(auto ele : v) {
        cout<<ele<<" ";
    }

    cout<<endl;
 
}
