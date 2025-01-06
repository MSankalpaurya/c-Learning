/**
 * TOPIC:  Pointer Casting with static_cast
 * 
 * 1. Upcasting in Inheritance
 *     -->Converting a derived class pointer to a base class pointer
 *     -->Safe and straightforward with static_cast.
 * 
 */
#include <iostream>
using namespace std;


class Base {
public:
    void baseMethod() { cout << "Base method\n"; }
};

class Derived : public Base {
public:
    void derivedMethod() { cout << "Derived method\n"; }
};



// Why Safe?
/**
 * Every Derived object is-a Base object. 
 * This relationship ensures that accessing the Base part of a 
 * Derived object is valid.
 */

// Understanding the "is-a" Relationship in Inheritance
/**
 *    n object-oriented programming, when a class Derived inherits 
 *    from another class Base, it creates an "is-a" relationship 
 *    between the two classes:
 *    Derived is-a Base: Every Derived object inherently contains 
 *    all the attributes and behaviors (data members and member functions) 
 *    of the Base class
 *    This relationship guarantees that any Derived object can be 
 *    treated as a Base object, as it contains all the features of 
 *    Base.
 */

// Why Can a Derived Object Be Safely Upcast to Base?

/**
 *  When you upcast a Derived object to a Base object, 
 *  you're essentially telling the compiler to "view" the Derived 
 *  object as if it were only a Base object. Since the Derived 
 *  class extends the Base class, it inherently contains everything 
 *  the Base class defines. Therefore, accessing the Base part of 
 *  the Derived object is always safe.
 * 
 */
int main() {
    Derived d;          // `d` is a Derived object
    Base* basePtr = &d; // Upcasting: Treat `d` as a Base object
    basePtr->baseMethod(); // Access Base class method

    // basePtr->derivedMethod(); // Error: Base doesn't know about Derived methods
    return 0;
}

/**
 * Key Observations:
 *    -->Derived inherits baseMethod() from Base. Thus, when basePtr 
 *    points to d, calling baseMethod() is valid
 *    -->The compiler ensures that only the Base part of the Derived 
 *    object is accessible through basePtr.
 * 
 */
