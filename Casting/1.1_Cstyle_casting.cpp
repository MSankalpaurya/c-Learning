/**
 * TOPIC:C-Style Casting
 * 
 * C-style casting is a single, unified casting mechanism inherited from the 
 * C programming language. It allows converting one type to another
 * 
 * syntax:
 * (new_type) expression OR new_type(expression)
 * 
 * Purpose of C-Style Casting:
 *    C-style casting provides a way to:
 *      1. Convert Numeric Types:
 *          Example: Converting float to int, or int to double.
 * // int x = (int)3.14;  // Truncates to 3
 * 
 *      2. Cast Between Pointers:
 *          Example: Converting a void* to a specific pointer type. 
 * 
// void* ptr = malloc(100);
// int* intPtr = (int*)ptr;
 * 
 *  Force Type Compatibility:
 *   Used to override type system checks where needed.
 * 
 */
/**
 * Why C-Style Casting Was Introduced:
 *      C-style casting addressed the need for flexible and quick type conversions, 
 *      especially in a language like C, which lacked the concept of polymorphism and 
 *      runtime type safety.
 */
/**
 * Problems with C-Style Casting:
 *   Although functional, C-style casting has several significant limitations that 
 *   became apparent with the advent of object-oriented programming in C++:
 * 
 * 1. Ambiguity:
 *     A single syntax ((new_type)expression) performs multiple types of casts 
 *     (e.g., reinterpret_cast, static_cast, const_cast)
 *     There’s no clarity about what kind of cast is being performed, making code 
 *     harder to read and debug.
 */