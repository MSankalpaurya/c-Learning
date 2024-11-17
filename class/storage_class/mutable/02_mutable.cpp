/**
 * Use Cases for mutable:
 *        1.Caching: When a const function needs to store the result of a 
 *          computation, you can use mutable to allow caching without violating 
 *          the const keyword.
 *        2.Lazy Initialization: If a const function needs to initialize certain internal state only when accessed, 
 *          mutable allows you to do so without breaking the const nature of the object.
 *        3.Logging and Debugging: If you need to track how many times a const function is called or 
 *          perform logging operations that modify internal variables, mutable allows you to maintain 
 *          a const interface while still modifying these internal variables.
 */

#include <iostream>

class Data {
public:
    Data() : computedValue(0), isComputed(false) {}

    int getComputedValue() const {
        if (!isComputed) {
            computedValue = expensiveComputation();
            isComputed = true;
        }
        return computedValue;
    }

private:
    mutable int computedValue;
    mutable bool isComputed;

    int expensiveComputation() const {
        std::cout << "Performing expensive computation..." << std::endl;
        return 42;  // Simulated expensive computation
    }
};


int main() {

    /*
    
    The first call to getComputedValue() performs an expensive computation, 
    which is stored in computedValue.
    Subsequent calls return the cached value, avoiding the computation again.
    Both computedValue and isComputed are declared mutable to allow modification
    inside the const function getComputedValue().
    
     */
    const Data data;
    std::cout << "Computed value: " << data.getComputedValue() << std::endl;
    std::cout << "Computed value: " << data.getComputedValue() << std::endl;  // No recomputation
    return 0;
}
