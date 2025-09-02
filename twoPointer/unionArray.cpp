#include<iostream>
#include<vector>
using namespace std;

void Traverse(vector<int>&c){
    for(auto ele : c){
        cout<<ele<<" ";
    }
    cout<<"\n";
}

void Union(vector<int>&a,vector<int>&b){
    int m = a.size();
    int n = b.size();
    vector<int>c;
    // c.reserve(m+n);
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<b[j]){
            c.push_back(a[i]);
            i++;
        } else if(a[i]>b[i]){
            c.push_back(b[j]);
            j++;
        } else {
            c.push_back(a[i]);
            i++;j++;
        }

    }
    while(i<m){
        c.push_back(a[i]);
        i++;
    }
    while(j<n){
        c.push_back(b[j]);
        j++;
    }

    Traverse(c);
}

int main(){
    
    int m,n;
    cout<<"Enter Size of First array: ";
    cin>>m;
    vector<int>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }

    cout<<"Enter Size of Second array: ";
    cin>>n;
    vector<int>b(n);

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    Union(a,b);
    

}