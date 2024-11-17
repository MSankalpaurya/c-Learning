/**
 * Type of thread creation in c++
 * //5 different types we can create threads in c++ using callable objects
 * 
 * 
 * Note :
 * if we create multiple threads at a same type it doesn't 
 * guarantee which one start first
 * 
 * 1. Function pointers
 * this is very basic form of thread creation
 */

#include <iostream>
#include <thread>

using namespace std;
// Example 1 Using the function pointers
void fun (int x){
    while (x-- > 0){
        cout << x <<endl;
    }
}

// Example 2 Lamda Function


int main () {


// we can directly inject lambda at thread creation time
    auto fun = [](int x){
        while(x-- > 0){
            cout << x << endl;
        }
    };


//can directly use to the thread also
    thread t([](int x)
{
    while (x-- > 0)
    {
        cout << x << endl;
    }
}, 10);

t.join();


    // thread t2 (fun ,11); // we are using function pointer to create thread
    // thread t1(fun , 10);
    
    // t1.join();
    // t2.join();
    
    return 0;
}


