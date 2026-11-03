
#include <iostream>
using namespace std;

struct Node {
    int data;


    void printData() {
        cout << "The stored data is: " << data << endl;
    }
};

int main() {
    Node n1;
    n1.data = 25;

    n1.printData();

    return 0;
}
