/**
 * Type Deduction Rules:
 * The type deduction for auto follows some specific rules:
 * 1. Basic Deduction: The compiler deduces the type based on the initializer.
 * 2. References and Pointers: If you use auto with references or pointers, 
 *    the deduced type includes these qualifiers
 *    NOTE: To keep the reference, you should use auto&
 * 3. Const Qualifiers: If the initializer is const, the deduced type reflects that
 * 4. Type Modifiers (* and &): You can use auto with pointers and references
 * 5. Function Return Types: When used with functions, auto allows for easier type management, 
 *    especially with template-heavy code or lambdas.
 * 
 * 
 * NOTE:
 * No Deduction Without Initializer: You can't use auto without an initializer, 
 * as the compiler needs the initializer to deduce the type.
 * 
 *   auto x;  // Error: no initializer, type cannot be deduced
 */

#include <bits/stdc++.h>

using namespace std;

    //point 5

    auto add(int a, int b) {
      return a + b;
    }

int main () {

    // point 1

    auto x = 42;        // int
    auto y = 3.14;      // double
    auto z = "Hello";   // const char*

    // point 2

    int a = 5;
    int& ref = a;
    auto x = ref;   // x is an int, not an int&

    // to keep the reference use the auto&
    auto& y = ref;     // y is an int&

    // point 3

    const int x = 42;
    auto y = x;         // y is an int (const is dropped)
    const auto z = x;   // z is const int

    
    // point 4
    int a = 42;
    int* p = &a;
    auto q = p;   // q is an int*
    

    return 0;
}