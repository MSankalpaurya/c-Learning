/**
 * TOPIC: Cyclic References (Problem with std::shared_ptr)
 * 
 * If two std::shared_ptr instances reference each other, 
 * they will never be destroyed because their reference counts 
 * will never reach 0. This is called a cyclic reference.
 */
#include <iostream>
#include <memory>

class B; // FORWARD decleration

class A {
public:
    std::shared_ptr<B> b_ptr;
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

    a->b_ptr = b; // A owns B
    b->a_ptr = a; // B owns A

    // Memory leak! Neither A nor B is destroyed due to cyclic reference

    // (No output, as objects are never destroyed)
    return 0;
}
