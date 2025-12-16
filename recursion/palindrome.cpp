#include<iostream>
using namespace std;

bool palindrome(string s,int i,int j){
    if(i>=j) return true;
    if(s[i]!=s[j]) return false;
    return palindrome(s,i+1,j-1);

}

int main(){
    string s="aba";
    int i=0;
    int j=s.size()-1;
    cout<<palindrome(s,i,j)<<endl;

}