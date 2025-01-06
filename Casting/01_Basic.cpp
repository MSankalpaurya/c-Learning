/**
 * 
 * 
 * What is Casting in C++?
 * Casting is the process of converting one data type to another in C++. 
 * This is necessary when performing operations between different types or 
 * accessing data in a specific form.
 * 
 * C++ supports two main types of casting:
 *      1. Implicit Castin
 *      2. Explicit Casting
 **/

/** 
 * TOPIC:Implicit Casting
 * 
 * Definition: Automatically performed by the compiler when converting data types that are compatible.
 *             Implicit casting, also known as type promotion, happens automatically by the 
 *             compiler. It converts a smaller data type to a larger data type or 
 *             from one compatible type to another.
 * Example: Converting a smaller data type to a larger one, such as int to float.
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    float b = a; // Implicit casting: int to float
    cout << "Integer: " << a << ", Float: " << b << endl;
//     return 0;
// }
/**
 * Rules for Implicit Casting
 *  1. Widening Conversions (Safe conversions):
 *     --> Smaller types to larger types (e.g., int to double).
 * Example
 * //float f = 3;  // int (3) promoted to float (3.0)
 * 
 * 
 * 
 *   2. Pointer Conversions:
 *      A derived class pointer can be implicitly converted to a base class pointer.
 *  Example:
 * // class Base {};
   // class Derived : public Base {};
   // Derived d;
   // Base* basePtr = &d;  // Implicit conversion


 *   3. Conversions between arithmetic types:
 *    Conversion happens when performing operations on mixed data types.
 *    Example:
 *   //  int x = 2;
     //  double y = 3.5;
     //  double result = x + y;  // x is promoted to double

 */

/**
 * TOPIC: Limitations of Implicit Casting
 * 
 * 1. Loss of Precision:
 *    When converting from a larger type to a smaller type (e.g., double to int), 
 *    implicit casting is not allowed because it might lead to data loss.
 * // double d = 4.99;
 * // int i = d;  // Compiler error
 * 
 * 2. Ambiguity in Pointers:
 *  Implicit casting might lead to subtle bugs when dealing with pointers, 
 *  especially in complex class hierarchies.
 */

/**
 *  TOPIC:Explicit Casting
 *  
 *  Definition: Manual casting, where you explicitly instruct the compiler to perform a type conversion.
 *  Why Needed?
 *   --> When converting between incompatible types (e.g., pointer types)
 *   --> To avoid implicit data loss in unsafe conversions (e.g., float to int)
 *   --> To make intentions clear to the reader and the compiler.
 *  TYPES:
 *  1. C-style casting:
 *  2. C++ casting operators:
 */
// #include <iostream>
// using namespace std;

// int main() {
    float C = 10.56;
    int D = (int)C; // C-style explicit cast
    int E = static_cast<int>(C); // C++ style explicit cast
    cout << "Float: " << C << ", Int (C-style): " << D << ", Int (C++ style): " << E << endl;
    return 0;
}

/**
 * TPOIC: Problems with C-style Casts:
 * 
 *  1. Ambiguity
 *    It was unclear whether the cast was for a reinterpretation of bits, 
 *    a conversion, or a pointer adjustment.
 * // int i = 5;
 * // void* ptr = (void*)&i;  // Is this safe? What does it mean?
 * 
 * 
 * 2. Lack of Safety:
 *   C-style casts bypass type safety checks, leading to potential runtime errors.
 *   // Base* b = new Derived();
 *   // Derived* d = (Derived*)b;  // Unsafe if `b` is not truly pointing to a `Derived`
 * 
 * 
 * 3. Difficult to Locate:
 *  It was hard to differentiate casts from normal operations in code, 
 *  making debugging more challenging.
 */


/**
 * Why Explicit Casting is Important
 *  Avoiding Ambiguity: Some type conversions are unsafe or unintended. Explicit casting avoids accidental misuse.
 *          Example: Casting a base class pointer to a derived class pointer requires explicit casting.
 *  Precision and Safety: Explicit casting helps manage operations like truncation, overflow, or data loss.
 *          Example: Truncating double to int removes fractional parts.
 * 
 */
