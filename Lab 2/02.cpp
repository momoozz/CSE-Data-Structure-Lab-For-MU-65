#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    int zipCode;
};

struct Student {
    int id;
    string name;
    Address studentAddress;
};

int main() {
    Student s1;
    s1.id = 102;
    s1.name = "Rahim";
    s1.studentAddress.city = "Sylhet";
    s1.studentAddress.zipCode = 3100;

    cout << s1.name << " lives in " << s1.studentAddress.city << endl;
    return 0;
}

