/**
 * TOPIC: stack implementation using array
 */
#include <iostream>
#define MAX 5  // Define the maximum size of the stack

class Stack {
    int arr[MAX];  // Array to store stack elements
    int size;       // Top of the stack (index)

public:
    Stack() { size = -1; }  // Constructor to initialize the top

    // Function to push an element onto the stack
    bool push(int x) {
        if (size >= (MAX - 1)) {
            std::cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++size] = x;  // Increment top and store element
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (size < 0) {
            std::cout << "Stack Underflow\n";
            return 0;
        } else {
            int x = arr[size--];  // Retrieve element and decrement top
            return x;
        }
    }

    // Function to view the top element
    int top(){
        if(size > 0){
            return arr[size];
        }
        else return -1;
    }
    

    // Function to check if the stack is empty
    bool isEmpty() {
        return (size < 0);
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    // myStack.push(20);
    // myStack.push(30);

    std::cout << myStack.pop() << " popped from stack\n";  // Output: 30 popped from stack

    std::cout << "Top element is " << myStack.top() << std::endl;  // Output: 20

    return 0;
}
