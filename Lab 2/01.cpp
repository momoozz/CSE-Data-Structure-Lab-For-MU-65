
#include <iostream>
using namespace std;

struct Student {
    int id;
    float cgpa;
};

int main() {
    Student s1;
    s1.id = 101;
    s1.cgpa = 3.75;

    cout << "ID: " << s1.id << ", CGPA: " << s1.cgpa << endl;
    return 0;
}
