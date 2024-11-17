#include <iostream>
#include <utility>  // For std::move
using namespace std;

class Example {
public:
    int data;

    // 1. Default constructor
    Example() {
        data = 0;
        cout << "Default constructor called, data = " << data << endl;
    }

    // 2. Parameterized constructor (single parameter)
    Example(int val) {
        data = val;
        cout << "Single-parameter constructor called, data = " << data << endl;
    }

    // 3. Parameterized constructor (two parameters)
    Example(int val1, int val2) {
        data = val1 + val2;
        cout << "Two-parameter constructor called, data = " << data << endl;
    }

    // 4. Copy constructor
    Example(const Example &obj) {
        data = obj.data;  // Copying value directly
        cout << "Copy constructor called, data = " << data << endl;
    }

    // 5. Move constructor
    Example(Example &&obj) noexcept {
        data = obj.data;  // Moving value (though simple in this case)
        obj.data = 0;  // Reset the source object's data
        cout << "Move constructor called" << endl;
    }

    // 6. Destructor (no dynamic memory, so nothing to delete)
    ~Example() {
        cout << "Destructor called, data = " << data << endl;
    }
};

int main() {
    // 1. Default constructor
    Example obj1;

    // 2. Single-parameter constructor
    Example obj2(20);

    // 3. Two-parameter constructor
    Example obj3(5, 10);  // Now providing both arguments explicitly

    // 4. Copy constructor
    Example obj4 = obj2;  // Copying obj2 into obj4

    // 5. Move constructor
    Example obj5 = std::move(obj2);  // Moving obj2 into obj5

    return 0;
}
