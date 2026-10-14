
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Queue {
    Node *headPtr;

    Queue() {
        headPtr = NULL;
        cout << "STL-Style Queue initialized!\n";
    }

    void push_back(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL;

        if (headPtr == NULL) {
            headPtr = newNode;
            return;
        }

        Node *cur = headPtr;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }


    int front() {
        if (headPtr == NULL) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return headPtr->val;
    }

    void pop_front() {
        if (headPtr == NULL) {
            cout << "Queue Underflow! Nothing to pop.\n";
            return;
        }

        Node *temp = headPtr;
        headPtr = headPtr->next;

        delete temp;
    }

    void printQueue() {
        if (headPtr == NULL) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue: ";
        Node *cur = headPtr;
        while (cur != NULL) {
            cout << cur->val;
            if (cur->next != NULL) cout << " <- ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;

    q.push_back(5);
    q.push_back(15);
    q.push_back(25);

    cout << "\nAfter pushing elements:\n";
    q.printQueue();

    cout << "\nFront element is: " << q.front() << "\n";
    cout << "Popping front element...\n";
    q.pop_front();

    cout << "\nAfter popping:\n";
    q.printQueue();

    cout << "\nFront element is now: " << q.front() << "\n";
    q.pop_front();
    q.pop_front();

    cout << "\nAfter popping all elements:\n";
    q.printQueue();

    return 0;
}
