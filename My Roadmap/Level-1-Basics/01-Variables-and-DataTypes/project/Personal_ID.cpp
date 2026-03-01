

#include "Personal_ID.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main () {
string name = "Alice Johnson";
    int age = 20;
    float height = 1.65;
    double gpa = 3.85;
    char grade = 'A';
    bool isStudent = true;

    // output or  print

    cout << "=========================" << endl;
    cout << "     STUDENT ID CARD     " << endl;
    cout << "=========================" << endl;


    cout << left << setw(10) << "Name"<< ": " << name << endl;
    cout << left << setw(10) <<"Age"  <<": " <<age << endl;
    cout <<left << setw(10) <<"Height" <<": " <<height<<endl;
    cout <<left <<setw(10) <<"GPA" <<": " <<gpa<<endl;

    if (isStudent) {
        cout << left << setw(10) <<"Student" <<": true" <<endl;
    }






    return 0;
}