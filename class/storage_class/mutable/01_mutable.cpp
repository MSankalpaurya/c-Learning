/**
 * TOPIC:mutable
 *       mutable keyword is used to modify the behavior of non-static member 
 *       variables within const objects. Normally, member variables of a const
 *       object cannot be modified, but with mutable, you can mark certain member
 *       variables to be modifiable even in a const.
 * 
 * NOTE:
 *     The mutable keyword is typically used when you want to allow some specific 
 *     internal state of a class to change, even if the object itself is marked as 
 *     constant. This is useful for situations where you want to keep certain internal 
 *     bookkeeping variables, such as caches, loggers, or counters, mutable, without 
 *     violating the const-ness of the object.
 * 
 * Key Features of mutable:
 *     Allows modification of member variables in a const object
 *     Only applicable to non-static member variables
 *     Useful in cases like caching, debugging, or keeping track of how often a const object 
 *     is accessed.
 * 
 * Summary of mutable:
 *     Purpose: Allows specific member variables to be modified even within const objects or const member functions
 *     Scope: Only applies to <non-static> member variables of a class
 *     Common Uses: Caching, logging, tracking internal state, lazy initialization
 *     In summary, the mutable keyword provides a way to make certain member variables modifiable within const 
 *     functions or objects, giving you greater flexibility in managing internal state without breaking the contract of const-ness.
 * 
 * 
 */

#include <iostream>

class MyClass {
public:
    mutable int accessCount;  // Mutable variable
    MyClass() : accessCount(0) {}

    void display() const {
        accessCount++;  // Allowed because accessCount is mutable
        std::cout << "Display function called " << accessCount << " times." << std::endl;
    }
};

class Logger {
public:
    mutable bool logWritten;  // Can be modified in a const object

    Logger() : logWritten(false) {}

    void writeLog() const {
        if (!logWritten) {
            std::cout << "Writing log..." << std::endl;
            logWritten = true;  // Allowed because logWritten is mutable
        } else {
            std::cout << "Log already written." << std::endl;
        }
    }
};

int main() {

    /*
    Usage of mutable in a Class:

    In this example, we mark the accessCount variable as mutable. 
    Even though the display() function is a const member function 
    (which guarantees not to modify the object), accessCount can '
    still be modified due to the mutable keyword.
    
    */
    const MyClass obj;  // Constant object (HERE WE ARE CREATING THE CONST OBJECT)
    
    /*
    obj is a const object, meaning you generally cannot modify its members.
    However, the accessCount variable, which is declared mutable, 
    can be incremented inside the display() function even though display() 
    is marked const.
    */
    obj.display();  // Even though obj is const, accessCount can be modified
    obj.display();  //Display function called 1 times.
                    //Display function called 2 times.


    /*
    The mutable keyword becomes useful when you have const member functions, 
    but you still want to modify some internal data without violating the 
    const qualifier.
    */
    const Logger logger;
    logger.writeLog();  // Writes log, modifies logWritten
    logger.writeLog();  // Now logWritten prevents re-writing

    return 0;
}
