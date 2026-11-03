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
        cout << "NULL\n";
    }

    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = head->next;
        head->next = cur;

        if (tail == head)
            tail = cur;
    }

    void insertBeforeTail(int x) {
        if (head == tail) {
            enqueue(x);
            return;
        }

        node *prev = head;

        while (prev->next != tail)
            prev = prev->next;

        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        prev->next = cur;
    }

    void insertAfterVal(int toFind, int toAdd) {
        node *cur = head;

        while (cur != NULL && cur->val != toFind)
            cur = cur->next;

        if (cur == NULL) {
            cout << "Value not found!\n";
            return;
        }

        node *newNode = new node;
        newNode->val = toAdd;
        newNode->next = cur->next;
        cur->next = newNode;

        if (cur == tail)
            tail = newNode;
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);

    sl.printList();

    sl.insertAfterHead(15);
    sl.printList();

    sl.insertBeforeTail(25);
    sl.printList();

    sl.insertAfterVal(15, 17);
    sl.printList();

    return 0;
}
