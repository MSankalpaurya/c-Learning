#include <bits/stdc++.h>

using namespace std;

class A {

    public:

    virtual void fun (){
        cout << " Hi -A" << endl;
    }

};

class B: public A {

    public:

    void fun () {
        cout << " Hi -B"<< endl;
    }

};

void fun (){
        cout << " Hi -G"<< endl;
    }

int main (){

//    A *b = new B();
//    B *b1 = new B();

//    b->fun(); // call the function from A
//    b1->fun(); // call the function from B 
//    fun();     // call the function from Global


   /**
    * If the function fun is override in the base class
    * 
    * 
    */

   A *b = new B();
   B *b1 = new B();

   b->fun(); // call the function from B
   b1->fun(); // call the function from B 
   fun();     // call the function from Global156

   delete b;
    return 0;
}