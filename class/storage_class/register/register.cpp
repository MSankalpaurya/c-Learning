/**
 * TOPIC: register
 * 
 *  register keyword is used as a storage class specifier to suggest to the compiler that
 *  a variable should be stored in a CPU register, rather than in memory, 
 *  to optimize access speed. Since CPU registers are much faster than memory, 
 *  variables stored in registers can be accessed more quickly, 
 *  especially in performance-critical code like loops.
 * 
 * NOTE:
 *  However, it's important to note that modern compilers largely ignore the register keyword, 
 *  because they are highly optimized and can automatically decide which variables should be 
 *  placed in registers based on usage patterns. In fact, 
 *  the register keyword was deprecated in C++11 and completely removed in C++17.
 * 
 * 1. How register Works:
 *     When you declare a variable with the register keyword, you're telling the compiler that 
 *     this variable will be used frequently, so it should ideally be stored in a CPU register
 *     for faster access.
 *   Scope: It behaves like an automatic (local) variable. It can only be declared inside a function,
 *          not at global scope
 *   Restrictions: Since registers are limited in size, there are a few restrictions when using register::
 *     1. You cannot take the address of a register variable, because it's stored in a CPU register, not in memory.:
 *     2. The actual placement of the variable in a register is up to the compiler, and the register keyword is just a suggestion.
 * 
 * 
 * 5. Modern Compilers and Optimization:
 *    Modern compilers are very good at optimizing code, so they automatically place frequently used variables 
 *    in registers without needing the register keyword. In most cases, you don't need to explicitly use register, 
 *    as the compiler will handle register allocation during the optimization phase.
 *    With the removal of the register keyword in C++17, the use of this keyword has become obsolete. 
 *    Nowadays, it's more common to rely on the compiler's optimization capabilities rather than 
 *    explicitly suggesting which variables should be placed in registers.
 */

#include <iostream>

using namespace std;

void function() {
    register int counter = 0;  // Suggests the compiler store `counter` in a CPU register
    for (counter = 0; counter < 10; ++counter) {
        std::cout << counter << std::endl;
    }
}

int main () {

    function(); 
/*
   No Addressing: Since a register variable is not guaranteed to be stored in memory, 
you cannot take its address using the & operator.
*/
    register int x = 10;
    int* ptr = &x;  // Error: Cannot take the address of a `register` variable


    return 0;
}