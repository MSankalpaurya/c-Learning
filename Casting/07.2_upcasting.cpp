/**
 * TOPIC: Upcasting with virtual function
 * 
 * When Base has a virtual function, the Derived class can override 
 * it to provide its own implementation. The "is-a" relationship ensures 
 * that when you call a function on a Base*, the correct 
 * implementation (based on the actual object) is called.
 * 
 * Why need to upcast in the first place and the benefits it provides in certain 
 * scenarios. Let’s explore this in detail.
 * 
 * 1.) To Treat Objects Uniformly (Polymorphism):
 *     Upcasting is often used in polymorphism, where you treat a group 
 *     of objects derived from the same base class in a unified way, 
 *     regardless of their specific types.
 * 
 * 2.)To Decouple Logic From Specific Types By upcasting to the 
 *    base type, you can write generic code that doesn’t depend on 
 *    the details of the derived classes. This makes your program 
 *    easier to maintain and extend.
 * 
 * 3.) To Simplify Storage in Containers Imagine you want to store 
 *     a collection of objects, but these objects belong to 
 *     different derived classes. By upcasting, you can store all 
 *     these objects as base class pointers in a single container.
 * 
 class Animal {
    public:
    virtual void sound() const = 0;
};

class Dog : public Animal {
    public:
    void sound() const override { cout << "Dog barks\n"; }
};

class Cat : public Animal {
    public:
    void sound() const override { cout << "Cat meows\n"; }
};

int main() {
    std::vector<Animal*> animals;

    Dog dog;
    Cat cat;

    animals.push_back(&dog);  // Upcasting
    animals.push_back(&cat);  // Upcasting

    for (const auto& animal : animals) {
        animal->sound();  // Calls the appropriate derived method
    }
    return 0;
}

 */
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class\n"; }
};

int main() {
    Derived d;          // `d` is a Derived object
    Base* basePtr = &d; // Upcasting: Treat `d` as a Base object
    basePtr->show();    // Calls Derived's `show()` due to polymorphism
    return 0;
}

/**
 * Key Observations:
 *  --> Even though basePtr is of type Base*, it points to an 
 *      actual Derived object
 *  --> Because show() is virtual, the correct Derived 
 *      implementation is called at runtime.
 */
// What Does It Mean to "Access the Base Part of a Derived Object"?

/**
 * When you upcast, the compiler ensures that the memory layout 
 * and type compatibility are respected. Consider the following:
 * Memory Layout:
 * 
 class Base {
    public:
        int a;
    };

 class Derived : public Base {
    public:
        int b;
    };

///////////////////////////////////////////////////////////////////
An object of Derived might look like this in memory:   
 | Base.a | Derived.b | 

The Base part (a) exists at the beginning of the Derived object.
When you cast Derived* to Base*, the compiler adjusts the pointer 
to point to the Base part of the object.
///////////////////////////////////////////////////////////////////
int main() {
    Derived d;
    d.a = 10; // Base member
    d.b = 20; // Derived member

    Base* basePtr = &d; // Upcasting
    cout << "Base part: " << basePtr->a << endl;

    // cout << basePtr->b; // Error: Base doesn't know about Derived.b
    return 0;
}

 // Here:
    basePtr points to the Base part of the Derived object
    The Derived-specific member b is inaccessible through basePtr.
 */

/**
 * Summary
 *     --> A Derived object is-a Base object because it inherits 
 *         all members and behaviors of Base.
 *     --> Upcasting (Derived* to Base*) is always safe because 
 *         you're restricting access to the Base part of the object.
 *     --> static_cast is a way to explicitly perform this type of 
 *         cast, making the code more readable and preventing accidental misuse.
 * 
 */