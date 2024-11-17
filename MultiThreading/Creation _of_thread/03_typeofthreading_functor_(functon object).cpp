#include <iostream>
#include <thread>

using namespace std;
//Functor (Function Object)
class Base {
    public :
    void fun (){
        cout << "hi am function";
    }
    void operator ()(int x){
        while(x-- > 0){
            cout << x <<endl;
        }
    }
};

int main (){
    Base b;
    thread t (Base(), 10);
    t.join();

    return 0;
}