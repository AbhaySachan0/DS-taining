#include<iostream>
using namespace std;  

struct Time{
    int hours;
    int min;
    int sec;
};

int main(){
    Time t1 = {1,5,10};
    Time t2 = {2,55,20};
    Time t3;

    t3.sec = t1.sec+t2.sec;
    t3.sec %= 60;
    t3.min = t1.min + t2.min + t3.sec/60;
    t3.min %= 60;

    t3.hours = t1.hours + t2.hours + t3.min/60;

    cout<<t3.hours<<" h "<<t3.min<<" m "<<t3.sec<<" s "<<endl;
    
}