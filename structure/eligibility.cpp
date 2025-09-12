#include <iostream>
#include <vector>
#include<string>

using namespace std;

struct student {
    string name;
    int roll;
    int marks[6];
};

int main() {
    student s;

    cout << "student name: ";
    getline(cin, s.name);

    cout << "Enter roll number: ";
    cin >> s.roll;


   cout << "Enter marks in 6 subjects :\n";
   for (int i = 0; i < 6; ++i) {
      cout << " Subject " << i + 1 << ": ";
      cin>> s.marks[i];
   }

   sort(s.marks.begin(), s.marks.end());
   
}