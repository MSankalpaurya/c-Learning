/**
 * TOPIC: Understanding the SOLID Principles in C++
 * 
 *       The SOLID principles are five design principles that help 
 *       create scalable, maintainable, and robust object-oriented 
 *       software. Let's break them down one by one, with simple 
 *       explanations and practical C++ examples.
 * **********************************************************************
 * TOPIC: 1. Single Responsibility Principle (SRP)
 * 
 *    Definition:
 *               A class should have only one reason to change. 
 *               It should focus on a single responsibility or task.
 *    Why?
 *        1. Keeps code modular and easy to understand
 *        2. Reduces the impact of changes in the system.
 * 
 *   Example:
 *        Imagine a Report class that both stores data and prints 
 *        the report. This violates SRP because it has two 
 *        responsibilities: data management and report formatting.
 * 
 * 
    Bad Example (Violating SRP):
    class Report {
    public:
        void addData(const std::string& data) {
            content += data;
        }
        void printReport() {
            std::cout << "Report Content: " << content << std::endl;
        }

    private:
        std::string content;
    };

 */
// Fixed Example (Following SRP):
//Split responsibilities into two classes:

#include <bits/stdc++.h>

using namespace std;

// First Class
class Report {
public:
    void addData(const std::string& data) {
        content += data;
    }

    std::string getContent() const {
        return content;
    }

private:
    std::string content;
};

// second class
//Now, if the printing logic changes (e.g., format to PDF), 
//you modify ReportPrinter without affecting Report.
class ReportPrinter {
public:
    void printReport(const Report& report) {
        std::cout << "Report Content: " << report.getContent() << std::endl;
    }
};
/**
 * *********************************************************************
 * TOPIC: 2. Open/Closed Principle (OCP)
 * Definition: 
 * A class should be open for extension but closed for modification.
 * 
 * Why?
 *  1. Encourages adding new functionality without changing 
 *     existing code
 *  1. Reduces the risk of introducing bugs.
 * 
 * Example:
 *  Let’s say you have a Shape class that calculates areas 
 *  for various shapes. Adding new shapes by modifying the 
 *  class violates OCP.
 * // Bad Example (Violating OCP):
class Shape {
public:
    double calculateArea(const std::string& shapeType, double dimension) {
        if (shapeType == "Circle") {
            return 3.14 * dimension * dimension;
        } else if (shapeType == "Square") {
            return dimension * dimension;
        }
        return 0;
    }
};

 * 
 */
// Fixed Example (Following OCP):
// Use polymorphism to extend functionality without modifying 
// existing code.
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double calculateArea() const override {
        return side * side;
    }
};
//***********************************************************************
// Now, adding a new shape like a triangle means creating a new 
// class without changing existing ones.

/**
 * **********************************************************************
 * TOPIC: 3. Liskov Substitution Principle (LSP)
 * 
 * Definition:
 *  Derived classes must be substitutable for their base classes.
 *  Why?
      Ensures that derived classes don’t break the functionality of the base class.

Example:
 Imagine a Bird base class. Not all birds can fly (e.g., penguins), 
 but if you design the Bird class assuming all birds can fly, 
 you violate LSP.
 */

// Bad Example (Violating LSP):
/** 
 class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        std::cout << "Penguins can't fly!" << std::endl;
    }
};
  This breaks the LSP because calling fly() on a 
  Penguin produces unexpected behavior.

*/

// Fixed Example (Following LSP):
// Refactor the design to reflect reality:

class Bird {
public:
    virtual void move() const = 0;
    virtual ~Bird() {}
};

class FlyingBird : public Bird {
public:
    void move() const override {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Penguin : public Bird {
public:
    void move() const override {
        std::cout << "Penguin is swimming" << std::endl;
    }
};

//**********************************************************************
/**
 * TOPIC: 4. Interface Segregation Principle (ISP)
 ***********************************************************************
 * Definition:
    A class should not be forced to implement interfaces it 
    doesn’t use.

Why?

    1. Avoids creating bloated interfaces.
    2. Keeps code clean and focused.
// Example:
// Suppose you have a Worker interface that forces all workers 
// to implement code and test.
// Bad Example (Violating ISP):
   
class Worker {
public:
    virtual void code() = 0;
    virtual void test() = 0;
};

class Developer : public Worker {
public:
    void code() override {
        std::cout << "Developer is coding" << std::endl;
    }
    void test() override {
        // Not relevant for Developer
    }
};
*/

// Fixed Example (Following ISP):
// Split the interface into smaller, focused ones:

class Coder {
public:
    virtual void code() = 0;
    virtual ~Coder() {}
};

class Tester {
public:
    virtual void test() = 0;
    virtual ~Tester() {}
};

class Developer : public Coder {
public:
    void code() override {
        std::cout << "Developer is coding" << std::endl;
    }
};

//**********************************************************************
// Now, classes implement only the methods they need.

/***********************************************************************
 * TOPIC: 5. Dependency Inversion Principle (DIP)
 * 
 * Definition:
   High-level modules should not depend on low-level modules. 
   Both should depend on abstractions.
Why?

    1. Reduces coupling between modules.
    2. Makes code easier to change and test.

Example:
Imagine a Light class controlled by a Switch. If the Switch depends
directly on the Light, it violates DIP.

Bad Example (Violating DIP):

class Light {
public:
    void turnOn() {
        std::cout << "Light is On" << std::endl;
    }
};

class Switch {
    Light& light;
public:
    Switch(Light& l) : light(l) {}
    void toggle() {
        light.turnOn();
    }
};

 */
// Fixed Example (Following DIP):
// Depend on an abstraction (Device):
class Device {
public:
    virtual void turnOn() = 0;
    virtual ~Device() {}
};

class Light : public Device {
public:
    void turnOn() override {
        std::cout << "Light is On" << std::endl;
    }
};

class Switch {
    Device& device;
public:
    Switch(Device& d) : device(d) {}
    void toggle() {
        device.turnOn();
    }
};

// Now, the Switch works with any Device, not just Light.
//**********************************************************************