#include <iostream>

int f(int &x, int c)
{
    c  = c - 1;
    std::cout << "value of c = " << c << std::endl;

    if (c == 0) return 1;

    x = x + 1;
    std::cout << "value of x = " << x << std::endl;
    std::cout << "value of f(" << x << ") = "<<x*x<<std::endl;
    return f(x, c) * x;
}
int main() {

    int p =4;
    int a = f(p , p);
    std::cout << "value of f() = " << a << std::endl;

    return 0;
}
