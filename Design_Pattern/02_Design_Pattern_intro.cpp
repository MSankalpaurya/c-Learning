/**
 * TOPIC: Design Patterns in C++
 * 
 *  Design patterns are proven solutions to common software design problems. 
 *  They provide templates for solving issues related to object creation, 
 *  structure, and behavior, enhancing code readability, flexibility, and scalability.
 * 
 *  A design pattern is a general, reusable solution to a commonly 
 *  occurring problem in software design. It’s not code itself but 
 *  a blueprint or guideline to write better, more maintainable code.
 * 
 * 
 * 2. Key Concepts Behind Design Patterns:
 *    To understand design patterns thoroughly, you need to grasp 
 *    the following object-oriented programming principles, 
 *    as they form the foundation:
 * 
 * 
 * Key Principles and Their Relation to Design Patterns
      A. Encapsulation

         Bundling data (variables) and methods (functions) into one unit (class).
         Example: Protecting the internal state of an object and 
         allowing controlled access via getters/setters.

      B. Inheritance

         Mechanism for creating a new class (derived) based on an 
         existing class (base).
         Helps reuse common functionality.

      C. Polymorphism

         The ability to use a derived class object where a base class 
         object is expected.
         Example: Overriding a base class method to provide specific 
         behavior in the derived class.

      D. Composition Over Inheritance

         Instead of inheriting from a class, use an instance of 
         another class to achieve functionality (i.e., "has-a" relationship vs. "is-a" relationship).
         This leads to better flexibility and less rigid hierarchies.

      E. Dependency Inversion Principle

         High-level modules should not depend on low-level modules. 
         Both should depend on abstractions.
         This is often implemented via interfaces or abstract base classes.
 * 
 * 
 * 5. Approach to Solve Problems with Patterns:
 *    We’ll apply a systematic method to solve problems using design 
 *    patterns:

    1. Understand the Problem: Analyze the requirements and constraints.
    2. Abstract the Problem: Generalize the challenge beyond its specifics.
    3. Choose the Right Pattern: Identify the most suitable pattern based on the problem type.
 *
 *
 *
 * Problem Statement:
 *  You are building a notification system where you need to send 
 *  alerts via Email, SMS, or Push Notifications. The system must:
 *   --> Support multiple notification types
 *   --> Be extensible (e.g., add new notification types later)
 *   --> Avoid hardcoding specific notification types in the main logic
 *
 * Step 2: Generalize the Problem:
 *  Instead of hardcoding specific notification types, abstract the 
 *  notification process using interfaces. This adheres to 
 *  Dependency Inversion and Open/Closed Principle.
 * 
 * Step 3: Solution with a Pattern:
 * We’ll implement this using Encapsulation and Polymorphism.
 *
 */

#include <iostream>
#include <memory>
using namespace std;

// Abstract Base Class (Notification Interface)
class Notification {
public:
    virtual void send(const string& message) const = 0; // Pure virtual method
    virtual ~Notification() {}
};

// Concrete Notification Types
class EmailNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "Sending Push Notification: " << message << endl;
    }
};

// Client Code
class NotificationService {
private:
    unique_ptr<Notification> notification; // Encapsulates the Notification type

public:
    // Constructor to accept any notification type
    NotificationService(unique_ptr<Notification> notif) : notification(move(notif)) {}

    void notify(const string& message) const {
        notification->send(message); // Polymorphism in action
    }
};

int main() {
    // Create notification objects dynamically
    auto email = make_unique<EmailNotification>();
    auto sms = make_unique<SMSNotification>();
    auto push = make_unique<PushNotification>();

    // Send notifications using the service
    NotificationService emailService(move(email));
    emailService.notify("Meeting at 10 AM");

    NotificationService smsService(move(sms));
    smsService.notify("Don't forget to pick up groceries.");

    NotificationService pushService(move(push));
    pushService.notify("Your package has been delivered!");

    return 0;
}
