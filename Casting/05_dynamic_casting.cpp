/**
 * TOPIC: Dynamic_cast in C++
 * 
 * Definition:
 *   dynamic_cast is used for runtime casting of pointers and references within a 
 *   class hierarchy. It performs a type-safe cast and checks if the conversion is 
 *   valid at runtime.
 * 
 * Key Characteristics:
 *     Primarily used with polymorphic classes (classes with at least one virtual function)
 *     It ensures that the object being cast is of the correct type or derives 
 *     from it
 *     If the cast is invalid
 *         For pointers: Returns nullptr
 *         For references: Throws a std::bad_cast exception.
 * 
 * 
 * Syntax:
 * dynamic_cast<type>(expression)
 *  type: The target type for the cast.
 *  expression: The value or pointer to be converted.
 */

#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Base* basePtr = new Base();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        cout << "Cast succeeded!" << endl;
    } else {
        cout << "Cast failed!" << endl;
    }

    delete basePtr;
    return 0;
}

/**
 *  Cast failed!
 * 
 * Explanation:
 * 
 *  1. Polymorphism Requirement:
 *       For dynamic_cast to work, the base class (Base) must be polymorphic. 
 *       This is true here because Base has a virtual destructor (virtual ~Base()).
 *  2. Downcasting:
 *       The pointer basePtr is pointing to an object of type Base, not Derived. 
 *       So, when you attempt to downcast basePtr to Derived* using:
 * 
 * // Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
 * 
 *     The dynamic_cast checks the actual type of the object basePtr points to at 
 *     runtime. Since it points to a Base object and not a Derived object, 
 *     the cast fails.
 * 
 * 3. Behavior on Failure:
 * 
 *     When the dynamic_cast fails for pointers, it returns nullptr.
 *     The if statement checks whether derivedPtr is nullptr:
 */  