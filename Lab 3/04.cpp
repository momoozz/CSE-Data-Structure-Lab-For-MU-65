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

    // Insert at end
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

    // Display list
    void printList() {
        node *cur = head;

        while (cur != NULL) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    // Insert after head
    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = head->next;
        head->next = cur;

        if (tail == head) tail = cur;
    }

    // Insert before tail
    void insertBeforeTail(int x) {
        if (head == NULL || head == tail) {
            node *cur = new node;
            cur->val = x;
            cur->next = head;
            head = cur;
            if (tail == NULL) tail = cur;
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

    // Delete head
    int dequeue() {
        if (head == NULL) return -1;

        node *cur = head;
        int x = cur->val;

        head = head->next;
        if (head == NULL) tail = NULL;

        delete cur;
        return x;
    }

    // Delete tail
    int deleteTail() {
        if (head == NULL) return -1;

        if (head == tail) {
            int x = head->val;
            delete head;
            head = tail = NULL;
            return x;
        }

        node *prev = head;
        while (prev->next != tail)
            prev = prev->next;

        int x = tail->val;
        delete tail;
        tail = prev;
        tail->next = NULL;

        return x;
    }

    // Delete node after head
    int deleteValAfterHead() {
        if (head == NULL || head->next == NULL)
            return -1;

        node *cur = head->next;
        int x = cur->val;

        head->next = cur->next;
        if (cur == tail) tail = head;

        delete cur;
        return x;
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);

    sl.insertAfterHead(15);
    sl.insertBeforeTail(25);

    cout << "Before deletion: ";
    sl.printList();

    sl.dequeue();
    cout << "After dequeue: ";
    sl.printList();

    sl.deleteTail();
    cout << "After deleteTail: ";
    sl.printList();

    sl.deleteValAfterHead();
    cout << "After deleteValAfterHead: ";
    sl.printList();

    return 0;
}
