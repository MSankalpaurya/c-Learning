/**
 * TOPIC: static
 * static keyword is used to modify the behavior of variables and functions,
 *  and its meaning varies depending on where it is applied.
 *  The keyword controls the lifetime, scope, and linkage of variables or functions. Let's explore the various uses of static in C++:
 * 
 * 1. Static Variables Inside Functions:
 *    When a variable is declared as static inside a function, it retains its value between function calls. 
 *    Unlike normal local variables that are created and destroyed each time the function is called, 
 *    static variables are only initialized once and persist for the lifetime of the program:
 *    Key Points:
 *     1. The variable's value is preserved between function calls
 *     2. It is initialized only once, when the function is first called
 *     3. Its scope is limited to the function where it's defined, but its lifetime extends until the program ends.
 * 
 * 2. Static Variables Inside Classes:
 *    A static variable in a class is shared by all objects of that class. Instead of having separate copies of the 
 *    variable for each instance, there is only one shared copy. Static class variables are also sometimes called class variables:
 *    Key Points:
 *     1. Belongs to the class rather than any object of the class
 *     2. Shared by all instances of the class
 *     3. Can be accessed using the class name
 *     4. Must be defined outside the class.
 * 
 * 3. Static Member Functions in Classes:
 *    static member functions in a class can be called without creating an object of the class. These functions can only access static members (variables or functions) of the class, as they do not operate on specific instances of the class:
 *    Key Points:
 *     1. Can be called using the class name, without creating an object
 *     2. Can only access other static members of the class.
 * 
 * 4. Static Variables at Global or File Scope:
 *    A static variable defined outside a function or class (i.e., at the global or file scope) has internal linkage. 
 *    This means it is limited to the file in which it is declared, and 
 *    cannot be accessed from other files, even if declared with extern:
 *    Key Points:
 *     1. The scope is limited to the file where it is defined
 *     2. Provides internal linkage, making the variable invisible to other translation units (files).
 * 
 * 5. Static Keyword with Functions:
 *    When applied to a function at global or file scope, static restricts the visibility of the function to the file in which it is declared. 
 *    This provides internal linkage, meaning the function cannot be called from other files:
 *    Key Points:
 *     1. The function is visible only within the file where it is declared
 *     2. Provides internal linkage, similar to static variables at file scope.
 * 
 */

#include <iostream>

using namespace std;

class A {
public:
    static int count;

    static void showCount() {
        std::cout << "Count: " << count << std::endl;
    }
};

class AA {
public:
    static int count;  // Static variable declaration
    AA() {
        count++;
    }
};
// Definition of the static variable FOR Class A
int A::count = 5;

// Definition of the static variable FOR Class AA
int AA::count = 0;

void testStatic1() {
    int count = 0;  // non Static variable
    count++;
    std::cout << "Count: " << count << std::endl;
}

void testStatic() {
    static int count = 0;  // Static variable
    count++;
    std::cout << "Count: " << count << std::endl;
}

int main () {
    /*
     the variable count is initialized to 0 only once. Each time testStatic() is called, 
     the value of count persists between function calls, 
     resulting in incremented values.
    */
    // non static member
    testStatic1();  // Output: Count: 1
    testStatic1();  // Output: Count: 1
    testStatic1();  // Output: Count: 1
    // static variable
    testStatic();  // Output: Count: 1
    testStatic();  // Output: Count: 2
    testStatic();  // Output: Count: 3

    // CLASS STATIC MEMBER
    /*
    count is shared across all instances of Counter.
     No matter how many objects are created, the value of 
     count is updated for all of them, because count 
     belongs to the class and not to individual objects.
    */
    AA obj1, obj2, obj3;
    std::cout << "Number of objects: " << AA::count << std::endl;  // Output: 3

    // CLASS Static function
    /*
     showCount() is a static member function, 
     and it can be called without creating an instance of A.
      It only works with the static member count.
    
    */
    A::showCount();  // Output: Count: 5

    return 0;
}