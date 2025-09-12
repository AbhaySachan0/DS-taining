#include<iostream>
using namespace std;    
struct Height{
    int feet;
    int inch;
};

int inchain(){
    Height t1 = {100,10};
    Height t2 = {100,100};
    Height t3;

    t3.inch = t1.inch + t2.inch;
    t3.feet = t1.feet + t2.feet + t3.inch/12;
    t3.inch %= 12;

    cout<<"feet - "<<t3.feet << " "<<" inch - "<<t3.inch<<endl;
}