/**
 * TOPIC:C++ casting operators:
 * 
 * casting operators are used to convert a variable of one data type into another data type. 
 * There are five main casting operators in C++:

    1) static_cast  : General type conversions, related pointer conversions
    2) dynamic_cast : Safe downcasting in inheritance hierarchies
    3) const_cast   : Add or remove const or volatile qualifiers
    4) reinterpret_cast : Bitwise reinterpretation, conversions between unrelated types
    5) C-style cast : Old style cast, less safe and expressive
 */

#include <iostream>

using namespace std;
class Base {
    public:
    void show () {
        cout << "i am from Base" << endl;
    }
};
class Derived : public Base {
    public:
    void show () {
        cout << "i am from Derived" << endl;
    }
};

int main () {

    int x = 10;
    double y = static_cast<double>(x); // Converts int to double

    Base* b = new Derived();
    Derived* d = static_cast<Derived*>(b); // Converts Base* to Derived*
}