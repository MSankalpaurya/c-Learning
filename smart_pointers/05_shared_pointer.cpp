/**
 * TOPIC: std::shared_ptr: Shared Ownership
 * 
 *   std::shared_ptr is another type of smart pointer that allows 
 *   multiple shared ownership of the same resource. 
 *   The resource is destroyed only when the last std::shared_ptr 
 *   owning it is destroyed.
 * 
 * Key Features
 * 
 * Reference Counting:
        1. std::shared_ptr maintains a reference count to track how many shared_ptr 
           instances are pointing to the same resource.
        2. When a new shared_ptr is created, the reference count increases.
        3. When a shared_ptr is destroyed, the reference count decreases.
        4. The resource is destroyed when the reference count reaches 0.
* Copyable:
        You can copy a std::shared_ptr, unlike std::unique_ptr.

* Thread-Safe Reference Counting:
        The reference count updates are thread-safe.
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
    std::shared_ptr<Demo> ptr1 = std::make_shared<Demo>(); // Create shared_ptr
    {
        std::shared_ptr<Demo> ptr2 = ptr1; // Shared ownership
        ptr2->sayHello();
        std::cout << "Reference count: " << ptr1.use_count() << "\n"; // Show ref count
    } // ptr2 goes out of scope, but resource is not destroyed

    std::cout << "Reference count after ptr2 is out of scope: " << ptr1.use_count() << "\n";
    // ptr1 goes out of scope, and the resource is destroyed
    return 0;
}
