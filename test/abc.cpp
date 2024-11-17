#include <bits/stdc++.h>

using namespace std;

class A {
    public:
    A(){
        cout << "from A"<<endl;
    }
    A(int a){
        cout << "para from A"<<endl;
    }

    A(const A& obj){
        cout << "copy from A"<<endl;
    }

    ~A(){
        cout << "from A Des"<<endl;
    }


};

class B : public A {
    public:
    B(){ 
        cout << "from B"<<endl;
    }

    B(int a){
        cout << "para from B"<<endl;
    }
    B(const B& obj){
        cout << "copy from B"<<endl;
    }
    ~B(){
        cout << "from B Des"<<endl;
    }

};

class C : public B {
    public:
    C(){ 
        cout << "from C"<<endl;
    }

    C(int a){
        cout << "para from C"<<endl;
    }

    C(const C& obj){
        cout << "copy from C"<<endl;
    }
    ~C(){
        cout << "from C Des"<<endl;
    }

};

int main (){
    C c1;
    C c2 = c1; 
    C c3(6);

    return 0;
}

