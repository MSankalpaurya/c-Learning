/**
 * TOPIC:Const_cast in C++
 *  Definition:
 *   const_cast is used to remove or add constness from a variable. It is the only 
 *   cast in C++ that can explicitly modify the const or volatile qualifiers of a 
 *   variable.
 * 
 * Syntax:
 *  const_cast<type>(expression)
 *    type: The type you want to cast to, with or without the const qualifier.
 *    expression: The variable being cast.
 * 
 * Use Cases of const_cast:
 *   Removing Constness
 *       Allows modification of a const object. However, modifying an inherently 
 *       const object (declared as const originally) leads to undefined behavior.
 * 
void modify(const int* ptr) {
    int* nonConstPtr = const_cast<int*>(ptr);
    *nonConstPtr = 10;  // Undefined behavior if the original object was const
}

 *
 * 2. Passing const Data to Functions Expecting Non-const:
        Useful when dealing with legacy code that doesn’t properly use const.
 * 
void legacyFunction(char* str) {
    cout << str << endl;
}

void modernFunction(const char* str) {
    legacyFunction(const_cast<char*>(str));  // Remove constness to call legacy code
}

 *
 * 3. Restoring Constness:
 *       const_cast can also add constness to a variable, though this is less common.
 *
int x = 5;
const int* constPtr = const_cast<const int*>(&x);  // Adding constness
 */

/**
 * Important Notes:

    Safe Use:
        Only remove const if you are sure the object was not originally declared 
        as const.
        Modifying inherently const objects leads to undefined behavior:
 * 
const int val = 42;
int* ptr = const_cast<int*>(&val);
*ptr = 10;  // Undefined behavior!

 Does Not Change Object Type:
    const_cast doesn’t alter the type of the object at runtime; it only affects how you access it.

 */

#include <iostream>
using namespace std;

void printAndModify(const int* num) {
    cout << "Original value: " << *num << endl;
    int* modifiableNum = const_cast<int*>(num); // remove constness 
    *modifiableNum = 20;  // Modify value
}

int main() {
    int x = 10;
    printAndModify(&x);
    cout << "Modified value: " << x << endl;
    return 0;
}
/**
 * Important Point:

If the original object passed to the function were declared as const, like this:

const int x = 10;  // x is now const
printAndModify(&x);

Then modifying the value inside the function would result in undefined behavior, 
as you cannot legally modify a truly const object.


Undefined Behavior:

    While const_cast removes the const qualifier, the int x itself is stored in a read-only memory region, 
    meaning modifying it is not allowed.
    This leads to undefined behavior, which could manifest in various ways, such as:
        A crash (segmentation fault).
        No apparent change in the output.
        Other erratic behavior.

 * 
 */
