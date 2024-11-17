/**
 * TOPIC:Stack Implementation Using a Linked List
 * 
 *   A linked list-based stack is dynamic and doesn't have the size limitation 
 *   that an array-based stack does. Each node stores data and a pointer 
 *   to the next node, making it more flexible.
 */

#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;
};

// Function to create a new node
StackNode* newNode(int data) {
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = nullptr;
    return stackNode;
}

class Stack {
    StackNode* top;

public:
    Stack() { top = nullptr; }

    // Function to push an element onto the stack
    void push(int data) {
        StackNode* stackNode = newNode(data);
        stackNode->next = top;
        top = stackNode;
        std::cout << data << " pushed to stack\n";
    }

    // Function to pop an element from the stack
    int pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        StackNode* temp = top;
        top = top->next;
        int popped = temp->data;
        delete temp;
        return popped;
    }

    // Function to view the top element
    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is empty\n";
            return 0;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << myStack.pop() << " popped from stack\n";  // Output: 30 popped from stack
    std::cout << "Top element is " << myStack.peek() << std::endl;  // Output: 20

    return 0;
}
