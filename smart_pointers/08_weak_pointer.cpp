/**
 * TOPIC: std::weak_ptr: Non-Owning Reference
 * 
 * std::weak_ptr is a smart pointer that provides a non-owning 
 * reference to an object managed by a std::shared_ptr. 
 * It helps in scenarios where you need to break cyclic 
 * dependencies or check the existence of a managed object 
 * without affecting its lifetime.
 * 
 * Key Features
    Non-Owning:
        A std::weak_ptr does not increase the reference count of 
        the std::shared_ptr it observes.
        It allows you to reference the shared object without 
        influencing its lifetime.

    Breaking Cyclic Dependencies:
        When two objects hold std::shared_ptr to each other, 
        it creates a cyclic dependency, preventing the objects 
        from being destroyed. Using std::weak_ptr in such cases 
        resolves the issue.

    Object Access:
        To access the object, you need to "lock" the std::weak_ptr 
        to obtain a std::shared_ptr. This ensures the object is 
        valid and not destroyed.
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
    std::shared_ptr<Demo> sharedDemo = std::make_shared<Demo>();
    std::weak_ptr<Demo> weakDemo = sharedDemo; // Create weak_ptr observing sharedDemo

    if (auto lockedDemo = weakDemo.lock()) { // Lock weak_ptr to access the object
        lockedDemo->sayHello();
    } else {
        std::cout << "Object is no longer available.\n";
    }

    sharedDemo.reset(); // Destroy the shared_ptr
    if (auto lockedDemo = weakDemo.lock()) {
        lockedDemo->sayHello();
    } else {
        std::cout << "Object is no longer available.\n";
    }

    return 0;
}
