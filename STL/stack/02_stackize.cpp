/**
 * TOPIC:stack size and iteration.
 * 
 * Stack Size and Iteration
 *   Size: You can check the number of elements in the stack using the size() function
 *   Iteration: Stacks don't support direct iteration like arrays or vectors, 
 *   but you can pop elements off one by one and process them.
 */

//Stack Size
//The size() function returns the number of elements currently in the stack.

#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Push elements into the stack
    myStack.push(100);
    myStack.push(200);
    myStack.push(300);

    //Stack Size
    //The size() function returns the number of elements currently in the stack.

    // Display the size of the stack
    std::cout << "Stack size: " << myStack.size() << std::endl;  // Output: 3


   //Iterating Through a Stack (Pop and Process)

   //Since stacks don't allow direct iteration, 
   //you have to pop each element and process it. 
   //This will remove elements from the stack.  
   int count = 0;
   // Pop and display elements until the stack is empty
    while (!myStack.empty()) {
        std::cout << "Top element: " << myStack.top() << std::endl;
        myStack.pop();
        count++;
    }
    std::cout << "Stack size: " << count << std::endl;

    // Stack is now empty
    std::cout << "Stack size after iteration: " << myStack.size() << std::endl;  // Output: 0


    return 0;
}
