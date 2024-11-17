/**
 * TOPIC:stack
 * stack in C++. A stack is a linear data structure that follows the Last In, First Out (LIFO) principle, meaning the last element added is the first one to be removed.
 * Basic Operations on a Stack:
 *      1. Push: Add an element to the top of the stack
 *      2. Pop: Remove the top element of the stack
 *      3. Top: View the top element without removing it
 *      4. Empty: Check if the stack is empty.
 * 
 * C++ provides a built-in stack class in the Standard Template Library (STL).
 * createation and usese a stack in C++:
 * 
 */
#include <iostream>
#include <stack>  // Include the stack header

int main() {
    // Create a stack of integers
    std::stack<int> myStack;

    // Push elements into the stack
    myStack.push(10);  // Stack: [10]
    myStack.push(20);  // Stack: [10, 20]
    myStack.push(30);  // Stack: [10, 20, 30]

    // Print the top element of the stack
    std::cout << "Top element: " << myStack.top() << std::endl;  // Output: 30

    // Pop the top element
    myStack.pop();  // Stack: [10, 20] here 30 is removed

    // Print the top element again
    std::cout << "Top element after pop: " << myStack.top() << std::endl;  // Output: 20

/*

Here how you can print the stack
as it is not support the stack
    // Create a copy of the stack to iterate through
    std::stack<int> tempStack = myStack;

    // Iterate through the stack elements by popping them
    std::cout << "Stack elements:" << std::endl;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << std::endl;
        tempStack.pop();
    }
*/
    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;  // Output: Stack is not empty
    }

    return 0;
}
