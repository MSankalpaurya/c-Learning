#include <iostream>

#include <thread>

using namespace std;

class base {
    public :
    static void fun (int x){
        while (x-- > 0){
            cout << x << endl;
        }
    }

};
// for ststic member function we do not need to provide address of the object
int main (){
    std::thread t (&base::fun, 10);
    t.join();

    
    return 0;
}
