/**
 * Key Methods of std::weak_ptr

    lock():
        Returns a std::shared_ptr if the observed object is still available; otherwise, it returns nullptr.

    expired():
        Returns true if the observed object has been destroyed.

    reset():
        Releases the std::weak_ptr from observing the object.
 */
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sharedInt = std::make_shared<int>(10);
    std::weak_ptr<int> weakInt = sharedInt;

    if (!weakInt.expired()) {
        std::cout << "Value: " << *weakInt.lock() << "\n"; // Access shared object
    }

    sharedInt.reset(); // Destroy the shared object

    if (weakInt.expired()) {
        std::cout << "The object is no longer available.\n";
    }

    return 0;
}
