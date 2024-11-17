/**
 * Puspose of storage class :
 * storage class defines the scope, visibility, and lifetime 
 * of variables or functions within a program. It determines 
 * how memory is allocated and how long that memory remains in 
 * use during program execution
 * 
 * TOPIC:auto (Automatic Storage)
 * AUTO:
 *  Scope: Local to the block where the variable is declared (i.e., the function or block in which it appears).
 *  Lifetime: Exists only within the block and is automatically destroyed when the block is exited.
 *  Visibility: Not accessible outside the block.
 *  Default behavior for local variables if no storage class is explicitly mentioned.
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int main () {

    int a = 10; // here if you do not decleared then it treated as 
                // auto int a =10;
    /**
     * When you declare a variable using auto, the compiler examines the type of the 
     * initializer (the value on the right-hand side of the assignment) and deduces 
     * the type of the variable accordingly. The type deduction happens at compile-time, 
     * meaning that the compiler determines the type before the program is run. 
     */

    auto a = 42;        // int
    auto b = 3.14;      // double
    auto c = 'A';       // char
    auto d = "Hello";   // const char*
    // Here, the type of a, b, c, and d is deduced automatically based on the values assigned to them.

    /**
     * Why use of auto?
     * 
     * 1. Code Simplification: It saves the programmer from explicitly writing the types, 
     * especially when dealing with complex types such as iterators, 
     * function pointers, or lambdas.
     * 
     */
    std::vector <int> vec = {1,2,3,4,5,6};
    std::vector<int>::iterator it = vec.begin();  // Before C++11 need to define the type of iterator
    auto it = vec.begin();                        // With auto no need to define the type of iterator

    /**
     * 2.  Enhanced Code Maintainability: If the type of an expression changes (due to refactoring or other reasons),
     *     using auto can help prevent errors. The compiler will automatically deduce the new type, 
     *     making the code more resilient to changes.
     */

    std::vector<std::pair<int, std::string>> vec; //here vector type changes
    auto it = vec.begin();  // No need to change if vector type changes


}  