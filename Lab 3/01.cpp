#include<iostream>
using namespace std;


struct node {
    int val;
    node *next;
};

struct SinglyLinkedlist{
      node *head, *tail;

      SinglyLinkedlist(){
        head = NULL ;
        tail = NULL ;
        cout << "SinglyLinkedList Initialized"<< endl;
      }

};
int main (){
    SinglyLinkedlist s1;
}
