#include<iostream>
using namespace std;
void tower(int n,char s,char m,char d){
    if(n==1) cout<<s<<"->"<<d;
    else{

        tower(n-1,'S','D','M');
        cout<<s<<"->"<<d<<endl;
        tower(n-1,'M','S','D');
    }
    
}

int main(){
    tower(4,'S','M','D');
}