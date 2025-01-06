/**
 * TOPIC: Unique Pointer
 *   std::unique_ptr is a smart pointer that provides exclusive 
 *   ownership of a dynamically allocated resource. This means:
 *             1. Only one unique_ptr can own a resource at any time
 *             2. The resource will be automatically deallocated 
 *                (freed) when the unique_ptr goes out of scope.
 * 
 * Key Features
 *   1. Non-Copyable: You cannot copy a std::unique_ptr to another std::unique_ptr. 
 *      This prevents accidental multiple ownerships of the same resource
 * 
 *   2. Transfer Ownership: Ownership can be transferred to another 
 *      std::unique_ptr using std::move
 * 
 *   3. Custom Deleter Support: You can specify how the resource is 
 *      cleaned up using a custom deleter.
 * 
 */
#include <iostream>
#include <memory>

class Demo {
public:
    Demo() { std::cout << "Demo created\n"; }
    ~Demo() { std::cout << "Demo destroyed\n"; }
    void sayHello() { std::cout << "Hello from Demo\n"; }
};

int main() {
    std::unique_ptr<Demo> ptr1 = std::make_unique<Demo>(); // Create unique_ptr
    ptr1->sayHello(); // Access the object
    // std::unique_ptr<Demo> ptr2 = ptr; // Not allowed to copy the unique pointer to
                                      // another unique pointers

    std::unique_ptr <Demo> ptr2 = std::move(ptr1); // Ownership is transferred to ptr2

    if (!ptr1) {
        std::cout << "ptr1 is now null.\n";
    }

    ptr2->sayHello();  // ptr2 is the new owner
    // ptr2 goes out of scope, and memory is automatically released
    return 0;
}
