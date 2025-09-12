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

// Delete first occurrence of key
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // head updated
        delete temp;
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) return;

    // Unlink node
    prev->next = temp->next;
    delete temp;
}


int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);   // 10 -> 20 -> 30 -> NULL

    insertAtBeginning(&head, 5);
    printList(head);   // 5 -> 10 -> 20 -> 30 -> NULL

    deleteNode(&head, 20);
    printList(head);   // 5 -> 10 -> 30 -> NULL

    return 0;
}