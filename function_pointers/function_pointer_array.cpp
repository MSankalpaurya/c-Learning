/**
 * An array of function pointers in C++ is essentially an array where each element is a pointer to a function.
 *  This can be useful for scenarios where you need to call different functions based on some index or condition dynamically.
   Concept

To declare an array of function pointers:

    1) Define the function pointer type.
    2) Declare an array of that type.
    3) Each element of this array can then point to different functions, allowing you to call a set of functions dynamically based on an index.
       Syntax

    Here's the basic syntax for declaring an array of function pointers:

    /////////////return_type (*array_name[])(parameter_list) = { &function1, &function2, ... };////////////////////////////////////////////////


    return_type (*array_name[])(parameter_list) = { &function1, &function2, ... };

    Where:

    return_type is the return type of the functions.
    parameter_list is the list of parameters the functions accept.
    array_name is the name of the array.
    function1, function2, etc., are the functions to which the pointers in the array point.
 */

#include <bits/stdc++.h>

using namespace std;

// Define some functions
void func1() {
    cout << "Function 1 called" << endl;
}

void func2() {
    cout << "Function 2 called" << endl;
}

void func3() {
    cout << "Function 3 called" << endl;
}

// Define an array of function pointers

void (*funcArray[])() = { func1, func2, func3 };

int main() {
    // Call functions using the function pointer array
    for (int i = 0; i < 3; ++i) {
        funcArray[i](); // Calls func1, func2, func3 respectively
    }

    return 0;
}
