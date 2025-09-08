#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Create initial list with some values
    void createInitialList() {
        int arr[] = {5, 15, 25, 35, 45};
        for (int i = 4; i >= 0; --i) {
            insertAtBeginning(arr[i]);
        }
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; ++i) temp = temp->next;
        if (!temp) {
            cout << "Position out of bounds.\n";
            return;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromPosition(int pos) {
        if (pos <= 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && temp->next && i < pos - 1; ++i) temp = temp->next;
        if (!temp || !temp->next) {
            cout << "Position out of bounds.\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    LinkedList list;
    list.createInitialList();
    cout << "Initial list created by program:\n";
    list.display();

    int choice, val, pos;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display the list\n";
        cout << "4. Search for an element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Insert Menu:\n1. At beginning\n2. At end\n3. At position\nEnter option: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;
                if (pos == 1) list.insertAtBeginning(val);
                else if (pos == 2) list.insertAtEnd(val);
                else if (pos == 3) {
                    cout << "Enter position: ";
                    cin >> pos;
                    list.insertAtPosition(val, pos);
                }
                else {
                    cout << "Invalid option.\n";
                    break;
                }
                cout << "Here is the final list: ";
                list.display();
                break;
            case 2:
                cout << "Delete Menu:\n1. From beginning\n2. From end\n3. From position\nEnter option: ";
                cin >> pos;
                if (pos == 1) list.deleteFromBeginning();
                else if (pos == 2) list.deleteFromEnd();
                else if (pos == 3) {
                    cout << "Enter position: ";
                    cin >> pos;
                    list.deleteFromPosition(pos);
                }
                else {
                    cout << "Invalid option.\n";
                    break;
                }
                cout << "Here is the final list: ";
                list.display();
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> val;
                if (list.search(val)) cout << "Found!\n";
                else cout << "Not found.\n";
                break;
            case 5:
                cout << "Exiting...\n";
                cout << "Here is the final list: ";
                list.display();
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}