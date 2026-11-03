#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node n1, n2;

    n1.data = 10;
    n2.data = 20;

    n1.next = &n2;

    cout << "Accessing n2's data through n1: " << n1.next->data << endl;

    return 0;
}

