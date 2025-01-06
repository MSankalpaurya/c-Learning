/**
 * TOPIC:static_cast in C++
 * 
 *  The static_cast operator is one of the most commonly used explicit 
 *  casting methods in C++. It is used for performing well-defined 
 *  and compile-time checked type conversions. Unlike C-style casting, 
 *  static_cast ensures that only compatible types can be converted, improving code clarity and safety.
 * 
 *  1. Syntax :
 *     static_cast<target_type>(expression)
 * 
 * Key Features:
 * --> Converts between compatible types (e.g., int to float or pointer types within the same inheritance hierarchy)
 * --> Performs compile-time checks to ensure the conversion is safe
 * --> Does not check validity at runtime (use dynamic_cast for runtime type checking).
 * 
 * 2. Use Cases for static_cast
 *  a) Numeric Conversions : Converts between arithmetic types like int, float, double, etc.
 * 
 */
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() { cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void display() override { cout << "Derived class\n"; }
};

void printFloat(float value) {
    cout << "Float value: " << value << endl;
}

class MyClass {
public:
    explicit MyClass(int x) { cout << "MyClass constructed with " << x << endl; }
};

int main() {
/**
    Basic Type Conversions:
    Converts between arithmetic types.
*/
    double pi = 3.14159;
    int truncated = static_cast<int>(pi); // Truncate decimal part
    cout << "Original: " << pi << ", Truncated: " << truncated << endl;

    int y = 65;
    char ch = static_cast<char>(y); // Convert int to char
    cout << "Integer 65 as char: " << ch << endl;


/**
 * b) Converting Between Pointers [Pointer Conversions (Within Class Hierarchies)]:
 *    Used for casting pointers within the same inheritance hierarchy 
 *    (e.g., upcasting or downcasting)
 *    --> Upcasting: Converting a derived class pointer to a base class pointer is safe with static_cast
 *    --> Downcasting: Converting a base class pointer to a derived class pointer is unsafe 
 *        without runtime checks (dynamic_cast is safer for this).
 * 
 */
    Derived derivedObj;
    Base* basePtr = static_cast<Base*>(&derivedObj); // Upcasting
    basePtr->display(); // Output: Derived class

    Derived* derivedPtr = static_cast<Derived*>(basePtr); // Downcasting (unsafe, but works here)
    derivedPtr->display(); // Output: Derived class

/**
 * c) Removing Implicit Conversion Ambiguity:
 *    Sometimes, implicit conversions might lead to undesired behavior. 
 *    Using static_cast ensures explicitness.
 */

    int x = 10;
    // Implicit conversion
    printFloat(x); // Works but less clear

    // Explicit conversion
    printFloat(static_cast<float>(x)); // Clear intent

/**
 * d) Casting to void* and Back:
 * Allows casting any object pointer to void* and back to its 
 * original type.
 */
    int a = 42;
    void* ptr = static_cast<void*>(&a); // Cast to void*
    int* intPtr = static_cast<int*>(ptr); // Cast back to int*
    cout << "Original: " << a << ", From void*: " << *intPtr << endl;
/**
 * e) Converting Enums to Integers:
 *    Converts an enum to its underlying integer type.
 */
    enum Colors { RED = 1, GREEN = 2, BLUE = 3 };
    Colors color = GREEN;
    int colorValue = static_cast<int>(color); // Enum to int
    cout << "Color value: " << colorValue << endl;

/**
 * f) Disabling Implicit Constructor Calls:
 *    Explicitly cast a type when calling a constructor to prevent 
 *    unintended conversions.
 */

    MyClass obj = static_cast<MyClass>(5); // Explicitly call constructor
    return 0;
}

/**
 * 3. Advantages of static_cast
 *    Compile-Time Safety: Ensures that the conversion is between compatible types
 *    Improved Code Clarity: Clearly specifies the intent of the type conversion
 *    Avoids Implicit Conversions: Eliminates ambiguity and makes conversions explicit.
 * 
 * 
 * 4. Limitations of static_cast
 *    No Runtime Checks: If used for downcasting pointers, it cannot verify type 
 *    safety at runtime (use dynamic_cast for that)
 *    No Conversion Between Unrelated Types: For unrelated types, use reinterpret_cast.
 * 
 */

/**
 * Compile-Time Error Example:
 * If the types are incompatible, static_cast will fail at compile time, 
 * ensuring safety.
 * 
 * 
int main() {
    int num = 10;
    // char* ptr = static_cast<char*>(&num); // Error: Incompatible types
    return 0;
}

 */