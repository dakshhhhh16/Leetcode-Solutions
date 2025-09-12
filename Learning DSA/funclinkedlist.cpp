//Here I am making some reusable funtions for linked list
#include <iostream>
using namespace std;
//Node Structure
struct Node {
    int data;   //value stored in the node
    Node* next; //pointer to the next node
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {  //traversing the linked list
        cout << temp->data << " -> "; //printing the data of current node
        temp = temp->next;  //moving to the next node
    }
    cout << "NULL" << endl; 
}

//Insert at beginning
void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node(); //create a new node
    newNode->data = newData; // Assign data to the new node
    newNode->next = *head; // New node points to the old head
    *head = newNode;    //head is updated
}

//Insert at end
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node(); //create a new node
    new_node->data = new_data; // Assign data to the new node
    new_node->next = NULL; // New node is going to be the last node, so make next of it as NULL

    if (*head_ref == NULL) { // If the Linked List is empty, then make the new node as head
        *head_ref = new_node;  //head is updated
        return; //exit from the function
    }

    Node* temp = *head_ref; // Else traverse till the last node
    while (temp->next != NULL) {   //traversing the linked list
        temp = temp->next; //moving to the next node
    }
    temp->next = new_node; // Change the next of last node
}