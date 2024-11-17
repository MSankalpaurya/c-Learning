/**
 * Stacks are typically implemented using non-contiguous memory blocks in C++. 
 * The stack data structure (as implemented in the C++ Standard Template Library (STL)) 
 * uses an underlying container (like deque or vector), which can manage memory 
 * either contiguously (like vector) or non-contiguously (like deque). 
 * However, the stack class itself is an adapter that doesn't enforce a specific
 * memory layout.
 * 
 * std::vector (if used as the underlying container) provides a contiguous memory block.
 * std::deque (the default underlying container for std::stack) generally uses non-contiguous memory, 
 * so a stack based on deque would be non-contiguous.
 * 
 * by default, stacks are non-contiguous, but you can make them contiguous by 
 * using std::vector as the underlying container.
 */

#include <iostream>
#include <stack>
#include <vector>

int main() {
    // Stack with vector (contiguous memory)
    std::stack<int, std::vector<int>> myStack;

    myStack.push(10);
    myStack.push(20);
    
    std::cout << "Top element: " << myStack.top() << std::endl;  // Output: 20
    
    return 0;
}
