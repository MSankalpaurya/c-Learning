#include <iostream>

class Rectangle {
private:
    int width;
    int height;

public:
    // Primary constructor
    Rectangle(int w, int h) : width(w), height(h) {
        std::cout << "Rectangle created with width: " << width << " and height: " << height << std::endl;
    }

    // Delegating constructor
    Rectangle(int size) : Rectangle(size, size) { // Delegates to the primary constructor
        std::cout << "Square created with size: " << size << std::endl;
    }

    void display() {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    // Rectangle rect1(10, 5);  // Calls the primary constructor
    Rectangle square(4);      // Calls the delegating constructor

    // rect1.display();
    square.display();

    return 0;
}
