#include <bits/stdc++.h>

class A {
    public:

     void fun (){
        std::cout << "hi from a";
    }
};

class B : public A{
    public:
    void fun (){
        std::cout << "hi from b";
    }
};

int main () {

A *a = new B();
a->fun();
}

