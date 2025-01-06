#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5); // Array of 5 integers
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    // Array is automatically deleted when `arr` goes out of scope
    return 0;
}
