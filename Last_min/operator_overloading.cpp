/*
Operator overloading allows you to redefine the behavior of operators (+, -, *, etc.) for user-defined types (e.g., classes and structs). 
This makes your code more intuitive and easier to use when working with custom objects.


Why Use Operator Overloading?

    Improved Readability: Makes your classes behave like built-in types.
        Example: Adding two objects using + instead of a method like add(obj1, obj2).

    Custom Behavior: Define how operators work for your specific class, such as concatenating strings or comparing objects.


Rules for Operator Overloading

    Cannot Overload All Operators:
        Operators like . (member access), sizeof, typeid, and a few others cannot be overloaded.

    At Least One Operand Must Be a User-Defined Type:
        You can't change the behavior of operators for built-in types.

    Syntax Must Follow Language Rules:
        Overloaded operators follow C++ syntax (e.g., precedence and associativity remain unchanged).

Basic Syntax of Operator Overloading

To overload an operator, you define a special member function or a non-member function with the keyword operator.

For Member function
class ClassName {
public:
    ReturnType operator op(const Arguments) {
        // Implementation
    }
};

For Non-Member function
ReturnType operator op(const ClassName& obj1, const ClassName& obj2) {
    // Implementation
}




Step-by-Step Example: Adding Two Objects
Let's overload the + operator for a class that represents a 2D point.

Code Example:

#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {} // Constructor

    // Overloading the + operator as a member function
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3, 4), p2(1, 2);
    Point p3 = p1 + p2; // Using the overloaded + operator
    p3.display();       // Output: (4, 6)
    return 0;
}


Key Points in the Example

    operator+ Function:
        Defined as a member function.
        It takes another Point object as an argument.
        Returns a new Point object with the sum of x and y values.

    Usage:
        p1 + p2 is equivalent to p1.operator+(p2).






Commonly Overloaded Operators

    Arithmetic Operators: +, -, *, /
    Comparison Operators: ==, !=, <, >, <=, >=
    Assignment Operators: =, +=, -=, *=, /=
    Unary Operators: ++, --, !, ~
    Stream Operators: <<, >> (e.g., for printing and reading)
    Subscript Operator: [] (for array-like access)
    Function Call Operator: () (to make objects callable)


*/

/**
 *
 *TOPIC:MORE DETAILED OPERATOR OVERLOADING

 Take Example of ' + ' overloading

*/
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the + operator
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3, 4), p2(1, 2);

    // Using + operator
    Point p3 = p1 + p2;

    // Equivalent explicit function call
    Point p4 = p1.operator+(p2);

    // Both produce the same result
    p3.display(); // Output: (4, 6)
    p4.display(); // Output: (4, 6)

    return 0;
}

/*
   
   operators are just functions with a special syntax. When you write p1 + p2, the compiler translates this into a function call. 
   For classes, this involves calling the operator+ function, which you define in your class.
   
   For Example
   Point p3 = p1 + p2;

   The compiler interprets this as:
   Point p3 = p1.operator+(p2);

/**
 * 
 * More precise:
 *  Point p3 = p1 + p2;
 * The compiler recognizes this as an expression involving the + operator applied to two operands: p1 (the left operand) and p2 (the right operand). At this point
 * The compiler identifies the types of p1 and p2 as Point.
 * It knows that + is an operator, and it needs to resolve its meaning.
 * 
 * 
 * 2. Operator Overloading Resolution
 * Since Point is a user-defined type (a class), the compiler checks whether the + operator is overloaded for 
 * this type.
 * The compiler looks for a member function in the Point class definition called operator+:
 * Point operator+(const Point& p) const;
 * If it exists, the compiler binds the + operator to this function.
 * If no such function exists, the compiler raises an error: invalid operands to 
 * binary expression.
 * 
 * 
 * The compiler confirms that the function signature of operator+ matches the operation. It checks
 * Is operator+ accessible (e.g., public)?
 * Does it take one parameter (const Point&) that matches the right operand p2?
 * 
 * 
 * 3. Translating p1 + p2 to p1.operator+(p2)
 *  After resolving the operator, the compiler translates the expression:
 * p1 + p2; 
 * TO
 * p1.operator+(p2);
 * 
 * Here’s how this works internally:
 *  p1 becomes the calling object for the operator+ function
 *  p2 is passed as an argument to the function.
 * 
 * Point p3 = p1.operator+(p2);
 * 
 * 4. Executing the operator+ Function
 * 
 * When the program runs, the operator+ function executes. Inside this function:
 *  The values of p1 (this object) and p2 (parameter) are accessed
 *  The function performs the operation you defined (e.g., adding x and y coordinates):

  // return Point(x + p.x, y + p.y);

A new Point object is created with the result of the operation and returned to the caller.
 */


/*
Here’s what happens step by step:

Object on the Left (p1):
    p1 is an object of the Point class.
    Since + is applied to p1, the compiler checks if the Point class has an operator+ defined.

The Operand on the Right (p2):
    p2 is passed as an argument to the operator+ function.
    The type of p2 must match the parameter type of the operator+ function.

Calling the Function:
    The compiler translates p1 + p2 into a call to p1.operator+(p2).

*/


/**
 * Why can't pass two arguments in member function
 * Point operator+(const Point& p1, const Point& p2);'
 * 
 * 
 * You cannot pass two arguments like this in a member function because of how member functions work in C++
 * 
 * When you declare a member function in a class, it implicitly takes the calling object (this) as the first operand. This means that any operator 
 * overloading function declared as a member function must always have one fewer explicit argument than the total number of operands the operator works with
 * For a binary operator like +, which involves two operands:
 * 
 * In a member function, one operand (the calling object) is already implicitly passed as this. Therefore, you can only pass the second operand explicitly.
 * 
 * 
 * 
 * 
 * Why Passing Two Arguments in a Member Function is Not Allowed
 *If you try to declare Point::operator+(const Point& p1, const Point& p2) as a member function, the compiler will reject it because:*
 *The left-hand operand (p1 in p1 + p2) is always treated as the calling object*
 *The function signature would imply three operands*
 *The implicit this (left operand)*
 *p1 (the first argument)*
 *p2 (the second argument)*
 *Member Function Examp*
 *A binary operator as a member function is typically defined as:


 */