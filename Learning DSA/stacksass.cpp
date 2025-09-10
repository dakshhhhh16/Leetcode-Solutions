#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of Stack

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    // Function to check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Function to check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Function to push an element into stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Function to pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Function to peek top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};

// Driver Code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.peek();

    s.pop();
    s.peek();

    s.push(60);  // Should show overflow if full

    return 0;
}
//jhdsajhdak