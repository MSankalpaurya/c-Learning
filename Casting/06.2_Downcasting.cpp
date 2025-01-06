/**
 * TOPIC: Downcasting in Inheritance
 * 
 *  Downcasting refers to converting a pointer or reference of a 
 *  base class to a derived class. This is the opposite of 
 *  upcasting, and it can be riskier because the base class does 
 *  not inherently "know" about its derived classes.
 * 
 * Why Downcasting is Used
 *  Downcasting is typically needed when:
 *       --> You need to access members or methods that exist only 
 *           in the derived class
 *       --> A base class pointer or reference is pointing to 
 *           a derived class object, and you want to work with the 
 *           derived class's specific features.
 * 
 */
// How Downcasting Works
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

/**
 * If you upcast a Derived object to a Base pointer, 
 * and then want to access derivedMethod(), it need to be
 * downcast back to a Derived pointer.
 * 
 * Risk in Downcasting ??
 *   Downcasting is unsafe if:
 *     -->The base class pointer does not actually point to a 
 *        derived class object
 *     -->You attempt to access derived-specific members on an 
 *        invalid downcast.
 */
//Example of a Bad Downcast:
int main () {
    Base b;
    Base* basePtr = &b;    // Pointer to a Base object
    Derived* derivedPtr = static_cast<Derived*>(basePtr); // Unsafe downcast
    derivedPtr->derivedMethod(); // Undefined behavior: `b` is not a Derived object!
    // Here, the basePtr actually points to a Base object, 
    // not a Derived object. Attempting to use a downcasted 
    // pointer can cause undefined behavior.
    return 0;
}
/**
 * Using static_cast for Downcasting:
 *  You can use static_cast for downcasting, but it does not 
 *  perform runtime checks. This makes it faster but riskier.

 Base* basePtr = &d; // Base pointer to a Derived object
 Derived* derivedPtr = static_cast<Derived*>(basePtr);
 derivedPtr->derivedMethod(); // Assumes `basePtr` points to a Derived object

 * 
    -->Safe only if you’re certain the base pointer actually 
       points to a derived object.
    -->Use this when type safety is guaranteed through logic, 
       such as checking object types beforehand.
 */

/**
 * Safe Downcasting with dynamic_cast:
 *  The dynamic_cast operator ensures that a pointer or reference being downcast is 
 *  valid at runtime. If the cast is invalid, dynamic_cast:
 *  Returns nullptr for pointers
 *  Throws a std::bad_cast exception for references.
 * 
 */
