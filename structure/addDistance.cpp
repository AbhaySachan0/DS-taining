#include<iostream>
using namespace std;    
struct Distance{
    int km;
    int m;
};

int main(){
    Distance d1 = {100,10};
    Distance d2 = {100,100};
    Distance d3;

    d3.m = d1.m + d2.m;
    d3.km = d1.km + d2.km + d3.m/1000;
    d3.m %= 1000;

    cout<<"Km - "<<d3.km << " "<<" m - "<<d3.m<<endl;
}