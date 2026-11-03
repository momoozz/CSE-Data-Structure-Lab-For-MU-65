#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

struct SinglyLinkedList {
    node *head, *tail;

    SinglyLinkedList() {
        head = tail = NULL;
    }

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;

        if (head == NULL) {
            head = tail = cur;
            return;
        }

        tail->next = cur;
        tail = cur;
    }

    void printList() {
        node *cur = head;

        while (cur != NULL) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }

        cout << "NULL";
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);

    sl.printList();

    return 0;
}
