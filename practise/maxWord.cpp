#include<iostream>
#include<vector>
using namespace std;

int main(){
    string text = "Abhay Sachan Abhay Sachan";
    string brokenLetters = "z";
    
    int maxCount = 0;
    vector<int>check(26,0);
    int n = text.size();
    int m=brokenLetters.size();

    for(int i=0;i<m;i++){
        check[brokenLetters[i]-'a']++;
    }
    int i=0;
    while(i<text.size()){
        if(check[text[i]-'a']!=0){
            while(i<n && text[i]!=' ') i++;
        }
        else {
            if(text[i]==' ' || i==m-1) maxCount++;
        }
        i++;
    }
    cout<<maxCount<<endl;
    
}