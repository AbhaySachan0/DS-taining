#include<iostream>
using namespace std;

int gcd(int a, int b){
   if(b!=0) return gcd( b, a%b);
    return a;
}
 int main(){
   int a,b;
   cout<<"Enter a :";
   cin>>a;
   cout<<"Enter b :";
   cin>>b;
   cout<<"gcd is : "<<gcd(a,b)<<endl;
 }