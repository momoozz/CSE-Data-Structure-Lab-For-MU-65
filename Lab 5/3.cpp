
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node*next;
};

struct Stack {
    Node*top;

    Stack() {
        top=NULL;
        cout<< "Linked List Stack initialized!\n";
    }

    void push(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = top;
        top = newNode;
    }


    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return -1;
        }

        Node *temp = top;
        int poppedVal = temp->val;

        top = top->next;
        delete temp;

        return poppedVal;
    }


    void printStack() {
        if (top == NULL) {
            cout << "Stack is Empty!\n";
            return;
        }

        cout << "Stack (Top to Bottom): ";
        Node *cur = top;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "\nAfter pushes:\n";
    s.printStack();

    cout << "\nPopped element: " << s.pop() << "\n";

    cout << "\nAfter popping:\n";
    s.printStack();

    return 0;
}
