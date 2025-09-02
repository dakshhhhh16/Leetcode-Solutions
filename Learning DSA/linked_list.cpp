#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head; //which does not comes under public is considered as private
    Node* tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_fornt(int val) {
        Node* newNode= new Node (val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
    }
};

int main () {
    List ll ;
    return 0;  
};
