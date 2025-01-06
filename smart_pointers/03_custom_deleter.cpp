/**
 *  TOPIC: Custom Deleter
 *   By default, std::unique_ptr uses delete to clean up the 
 *   resource. However, you can specify a custom deleter, 
 *   which is useful for resources like file handles or arrays.
 */

#include <iostream>
#include <memory>

struct FileDeleter {
    void operator()(FILE* file) {
        if (file) {
            fclose(file);
            std::cout << "File closed.\n";
        }
    }
};

int main() {
    std::unique_ptr<FILE, FileDeleter> file(fopen("example.txt", "w"), FileDeleter());
    if (file) {
        std::cout << "File opened.\n";
        fprintf(file.get(), "Hello, file!\n");
    }
    // File automatically closed when file goes out of scope
    return 0;
}
