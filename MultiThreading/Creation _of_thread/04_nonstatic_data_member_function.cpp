#include <iostream>
#include <thread>

using namespace std;

class base {
    public :
    void fun (int x){
        while (x-- > 0){
            cout << x << endl;
        }
    }

};
// non static member function
int main (){

    base b, c;
    std::thread t (&base::fun, &b, 10);
    t.join();

    return 0;
}