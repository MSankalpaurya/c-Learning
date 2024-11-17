/**
 * Why use Mutex?
 * what is race condition and how to solve it ?
 * what is critical section ?
 * 
 * Mutex : Mutual Exclusion
 * 
 * Race Condition :
 * 1. Race condition is situation where two or more tread/process happened to change
 *    common data or resources at same time
 * 2. If there is a race condition  then we have to proctec it and protected section
 *    is called critical section/region
 * 
 * Mutex: 
 * 1. It is used to avoid race condition
 * 2. use lock(), unlock() on mutex to avoid race condition
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

int x = 0, value = 0;
void add(){
    for (int i= 0; i <100000; i++){
    mtx.lock();
    ++value;
    mtx.unlock();
    }
}

int main (){
    thread t1 (add);
    thread t2 (add);

    /**
     * Here 3 things happen
     * 1) Load -> Load the varible in Acumulate resister
     * 2) Operation -> Done the operation
     * 3) Store
     */

    t1.join();
    t2.join();
    // here t1 and t2 are using common resouces;
    cout << "value = " << value << endl;
    return 0;
}
