/**
 * Cyclic references occur when two objects reference each other 
 * with std::shared_ptr, causing a memory leak. 
 * Here's how std::weak_ptr can solve this:
 */

#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::weak_ptr<B> b_ptr; // Use weak_ptr to break cyclic dependency
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->b_ptr = b; // A observes B
    b->a_ptr = a; // B owns A

    // No cyclic dependency; A and B will be destroyed when shared_ptrs go out of scope
    return 0;
}
