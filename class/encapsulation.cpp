/**
 * Encapsulation in C++ is a fundamental object-oriented programming concept 
 * that involves bundling data (attributes) and methods (functions) 
 * that operate on that data into a single unit called a class. 
 * This bundling helps to protect the data from unauthorized access 
 * and ensures that data is modified only through well-defined methods
 * 
 * Key components of encapsulation:
      Class: A blueprint or template for creating objects. It defines the data members (attributes) 
      and member functions (methods) that an object will have.

      Object: An instance of a class. It represents a concrete realization of the class with its 
      own values for the data members.

      Data members: Variables that store the data associated with an object. 
      They can be public, private, or protected.

      Member functions: Functions that operate on the data members of an object. 
      They can be public, private, or protected.

 * Access modifiers:

      Public: Members can be accessed from anywhere in the program.

      Private: Members can only be accessed within the class itself.   

      Protected: Members can be accessed within the class itself and by derived classes.   
      Benefits of encapsulation:

 * Data hiding: Encapsulation prevents direct access to data members from outside the class, ensuring data integrity and preventing accidental modifications.
 * Modularity: Classes can be designed as self-contained units, making the code easier to understand, maintain, and reuse.
 * Abstraction: Encapsulation allows you to focus on the behavior of an object without worrying about its internal implementation details.
 * Reusability: Encapsulated classes can be reused in different parts of a program or even in other projects.
 */


#include <bits/stdc++.h>

using namespace std;

class Person {
/*Data Hiding*/
private:
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

int main()
 {
    Person person("Sankalp", 28);
    cout << person.getName() << endl; // Accessing public member function
    cout << person.name << endl; // Error: Cannot access private data member
    return 0;
}