#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "Junwen Long";
    int age = 19;
    string app = "Welcome.cpp";
    int version = 1;
    char grade = 'F';
    bool enrolled = true;

    cout << "---Welcome to my application!---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Name of application: " << app << endl;
    cout << "Lastest version of application: " << version << endl;
    cout << "Grade: " << grade << endl;
    cout << "Enrolled: " << boolalpha << enrolled << endl;

    return 0;

}