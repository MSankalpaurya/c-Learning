/**
 * TOPIC: Passing std::shared_ptr to Functions
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

void useShared(std::shared_ptr<Demo> ptr) {
    std::cout << "Inside function, reference count: " << ptr.use_count() << "\n";
    ptr->sayHello();
}

int main() {
    std::shared_ptr<Demo> ptr = std::make_shared<Demo>();
    std::cout << "Reference count before function: " << ptr.use_count() << "\n";

    useShared(ptr); // Passing a copy of the shared_ptr
    std::cout << "Reference count after function: " << ptr.use_count() << "\n";

    /**
     * OUTPUT:
     * Demo created
     * Reference count before function: 1
     * Inside function, reference count: 2
     * Hello from Demo
     * Reference count after function: 1
     * Demo destroyed

    */

    return 0;
}
