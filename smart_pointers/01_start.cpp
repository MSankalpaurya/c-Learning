/**
 * TOPIC:SMART POINTERS
 *       A smart pointer is an object that behaves like a pointer 
 *       but manages the lifetime of the object it points to. 
 *       Smart pointers are part of the Standard Template Library (STL) 
 *       and are defined in the <memory> header.
 * 
 * 2. Why use Smart Pointers?
 *    1. Automatic memory management: No need to call delete
 *    2. Avoid memory leaks: Ensures memory is deallocated even if exceptions occur
 *    3. Ownership semantics: Helps you manage who owns the memory and when it should be freed.
 * 
 * Types of Smart Pointers in C++
 *   1. std::unique_ptr:
 *          Owns a resource exclusively.
 *          No copying is allowed, but ownership can be transferred.
 *   2. std::shared_ptr
 *          Shared ownership of a resource
 *          Reference count keeps track of how many shared pointers are using the same resource.
 *   3. std::weak_ptr:
 *          Non-owning reference to a std::shared_ptr.
 *          Helps avoid cyclic references.
 * 
 * 
 *      Using std::unique_ptr (Example Of Smart Pointers)
 */

#include <iostream>
#include <memory> // Required for smart pointers

class Demo {
public:
    Demo() { std::cout << "Demo created\n"; }
    ~Demo() { std::cout << "Demo destroyed\n"; }
    void show() { std::cout << "Hello from Demo!\n"; }
};

int main() {
    std::unique_ptr<Demo> ptr = std::make_unique<Demo>(); // Create a unique_ptr
    ptr->show(); // Use the object through the smart pointer
    return 0; // The resource is automatically freed here
}
