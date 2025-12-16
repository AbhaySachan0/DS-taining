#include<iostream>
#include<math.h>
using namespace std;

int digits(int n){
    int count=0;
    while(n>0){
        count++;
        n /=10;
    }
    return count;
}

int reverse(int num){

    int rev = 0;
    while(num>0){
        int rem = num%10;
        rev = rev*10 + rem;
        num /= 10;
    }
    return rev;
}

int reverseFolding(long long num,int digits,int size){
    int d = digits;
    int m = pow(10,d);
    int count=1;

    int sum=0;

    while(num>0){
        int rem = num%m;
        if(count%2==0) sum += reverse(rem);
        else sum += rem;
        count++;
        num /= m;
    }
    return sum%size;
}

int Folding(long long num,int digits,int size){
    int d = digits;
    int m = pow(10,d);
    int sum=0;

    while(num>0){
        int rem = num%m;
        sum += rem;
        num /= m;
    }
    return sum%num;
}

int main(){
    int n = 100;
    int d = digits(n-1);
    long long num = 2400320100749;
    cout<<reverseFolding(num,d,n)<<endl;
}