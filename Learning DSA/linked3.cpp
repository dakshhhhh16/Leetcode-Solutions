//creating and printing a linked list
#include <iostream>
using namespace std;


struct Node { //This is the beginning of all node type programs
    int data;
    Node* next;
};

int main() {
    //creating 3 nodes
    Node* head = new Node(); //first node
    Node* second = new Node(); //second node
    Node* third = new Node(); //third node

    //assigning data values
    head->data = 10;
    second->data = 20;
    third->data = 30;

    //linking nodes
    head->next = second;
    second->next = third;
    third->next = nullptr;

    //printing the linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;

    return 0;
}
//Pointers required to understand linked list better
