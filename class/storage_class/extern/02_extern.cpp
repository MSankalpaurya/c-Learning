#include <iostream>

using namespace std;

int num = 42;   //is the definition of the variable, where memory is allocated.

// Declaration of the const variable
extern const int MAX_VALUE;

// Definition of the function
void testextern(){
    std::cout << "Hello I am testing extern" << std::endl;
}

