/**
 * TOPIC:Downcasting:
 *  Definition:
 *  Downcasting refers to converting a base class pointer or reference back to a 
 *  derived class pointer or reference.
 * 
 * Characteristics:
 * Explicit and Risky
 *     Downcasting isn't always safe because the base class pointer may not 
 *     actually point to an object of the derived class. This requires explicit 
 *     casting.
 * 
 * Achieved via dynamic_cast or static_cast:
 *  dynamic_cast
 *      Safe but has runtime overhead
 *      Performs a runtime check to ensure the object type is valid
 *      Returns nullptr (for pointers) or throws std::bad_cast (for references) 
 *      if the cast fails.
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
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Safe downcast
    if (derivedPtr) {
        cout << "Downcast succeeded!" << endl;
    }
    return 0;
}
/**
 * 
 * static_cast:
 *     Faster, as it performs no runtime checks
 *     Should be used only when you are certain of the object type
 *     Example:
 * 
 *     Derived* derivedPtr = static_cast<Derived*>(basePtr);  // Assumes basePtr is actually Derived*
 * 
 *   Purpose:
 *     Access members specific to the derived class.
 * 
 * class Base {
    public:
        virtual ~Base() {}
    };

    class Derived : public Base {
    public:
        void derivedFunc() { cout << "Derived-specific function" << endl; }
    };

    int main() {
        Base* basePtr = new Derived();
        Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
        if (derivedPtr) {
            derivedPtr->derivedFunc();  // Access derived-specific function
        }
        delete basePtr;
        return 0;
    }

 */