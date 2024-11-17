#include <bits/stdc++.h>
 using namespace std;


 class A {
    public:
    int a;
    static int b;

    A(){
        cout << "Default Constructor" << endl;
    }

    A (const A &obj){
        this->a = obj.a;
        this->b = b;
        cout << "Copy Constructor"<<endl;

    }

    A (const A &&obj) noexcept{
      a = obj.a;
      cout << "Move Constructor"<<endl;
    }

    A(int a){
        this->a = a;
        cout << "parameterized Constructor" << endl;
    }

    A& operator=(const A& obj) {
        this->a = obj.a;
        cout << "Copy Assignment Operator" << endl;
        return *this;
    }

    A& operator=(const A&& obj) noexcept {   
        this->a = obj.a;
        cout << "Move Assignment Operator" << endl;
        return *this;
    } 

    void fun (){
        cout << "void function"<<endl;
    }
    virtual void fun1 (){
        cout << "virtual void function"<<endl;
    }
    static void fun2 (){
        cout << "static void function"<<endl;
    }

 };
 int A::b;

 int main (){
    A a;
    A b1;
    A c = std::move(b1);
    A d = b1;
    a = b1;
    a = std::move(c);

 }