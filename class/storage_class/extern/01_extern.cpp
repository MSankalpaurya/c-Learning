/**
 * TOPIC: extern 
 * extern keyword is used to declare a variable or function that 
 * is defined in another file or translation unit. 
 * It tells the compiler that the variable or function exists, 
 * but its memory allocation or actual definition is provided elsewhere. 
 * This keyword is especially useful for handling global variables and 
 * functions across multiple files, enabling modularity in code.
 * 
 * 
 * Key Features of extern:
 * Global Scope Access: The extern keyword allows a variable or function to be shared across different files.
 * Separation of Declaration and Definition: It separates the declaration (using extern) from the definition 
 * (where the actual storage is provided). 
 * The declaration informs the compiler about the existence of the variable or function, 
 * while the definition allocates memory for it.
 * 
 * 1. Extern Variables:
 * When you use extern with a variable, you declare it in one file 
 * and define it in another. This prevents redefinition errors 
 * and ensures that the variable has global linkage.
 * 
 * 
 * 2. Extern Functions:
 *    use extern with functions to declare them in one file and define them in another. 
 *    By default, functions have external linkage, so using extern is typically unnecessary
 *    unless you're dealing with C and C++ interoperability 
 * 
 * 3. extern and const Variables:
 *    Normally, const variables have internal linkage, meaning they are limited to the file
 *    in which they are defined. However, you we give a const variable external linkage using extern, 
 *    so it can be shared between files.
 * 
 * NOTE:
 * 4. extern and C++ with C Linkage (extern "C"):
 *    When writing C++ code that needs to interact with C code, the extern "C" syntax is used. 
 *    This is because C and C++ handle function name mangling differently, and extern "C" ensures 
 *    that the C++ compiler does not mangle the function names, allowing them to be linked with C code.
 * 
 * When to Use extern:
 * Global Variables Across Multiple Files: When you want a global variable to be accessible across multiple source files:
 * Function Declaration Across Multiple Files: When you want to declare a function in one file but define it in another:
 * Interfacing with C Code: When you are working with mixed C and C++ code and need to handle linkage differences.
 */

#include <iostream>

extern int num;  // extern int num; in 02_extern.cpp is a declaration, 
                 // informing the compiler that the variable num exists 
                 // somewhere else (in 01_extern.cpp), and the linker will 
                 // resolve the reference during linking.
              

void printnum (){
    std::cout << num << std::endl;
}
// Declaration of the function
extern void testextern();

// Definition of a const variable
extern const int MAX_VALUE = 100;

void printMaxValue() {
    std::cout << MAX_VALUE << std::endl;
}


int main () {
    // int num = 10; // you can not define here
    printnum(); // output will be 42
    testextern(); // test extern
    printMaxValue(); // print max value
    return 0;
}
