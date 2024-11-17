#include <bits/stdc++.h>

using namespace std;

class A {
    public:
    void f1 (){
        cout << "Hi I am f1 From A";
    }
    virtual void f2 (){
        cout << "Hi I am f2 From A";
    }
    virtual void f3 (){
        cout << "Hi I am f3 From A";
    }
   void f4 (){
        cout << "Hi I am f1 From A";
    }

};

class B : public A {
    public:
    void f1 (){
        cout << "Hi I am f1 From B";
    }
    void f2 (){
        cout << "Hi I am f2 From B";
    }
   void f4 (int a){
        cout << "Hi I am f1 From B";
    }

};

int main (){

    A *a = new (B);
    a->f2();
    return 0;
}