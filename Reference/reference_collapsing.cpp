#include <iostream>
#include <utility>

// Forward declarations of the bar functions
void bar(int& x);
void bar(int&& x);


// A simple function to demonstrate reference collapsing
template <typename T>
void foo(T&& arg) {
    bar(std::forward<T>(arg));
}

void bar(int& x) {
    std::cout << "Lvalue reference called\n";
}

void bar(int&& x) {
    std::cout << "Rvalue reference called\n";
}

int main() {
    int a = 5;
    bar(a);  // Passes an lvalue
    bar(10); // Passes an rvalue
    return 0;
}
