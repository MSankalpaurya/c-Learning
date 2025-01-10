#include <iostream>

void fun (const int& a) {
    int b = (const int&) a;
    b = b+5;
    std::cout << b;
}
int main() {
    const  int a =10;
    fun(a);
 
    return 0;
}