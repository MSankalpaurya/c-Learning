/**
 * 
 * TOPIC: Upcasting
 * 
 * Definition:
 *   Upcasting refers to converting a derived class pointer or reference to a 
 *   base class pointer or reference.
 * 
 * Characteristics:
 * Safe and Implicit:
 *  Upcasting is always valid and doesn't require explicit casting. 
 *  The compiler performs this conversion automatically.
 */
#include <iostream>
using namespace std;
class Base {
public:
    virtual void show() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived" << endl; }
};

int main() {
    Derived d;
    Base* basePtr = &d;  // Implicit upcasting
    basePtr->show();     // Output: Derived (polymorphism)
    return 0;
}

/**
 *     Purpose:
        Enables polymorphism by allowing base class pointers to point to derived class objects.
        Useful for writing generic code that works with base class types.

    Dynamic Behavior:
        When using virtual functions, the actual implementation from the derived class is called at runtime.


 */
