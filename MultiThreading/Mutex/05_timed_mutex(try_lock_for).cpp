/**
 * Topic Timed Mutex i.e. std::timed_mutex
 * 
 * NOTES:
 * 1. std::mutex is blocked till timeout timeor the lock is aquired and 
 * return true if success otherwise false
 * 
 * MEMBER FUNCTION:
 * 1. lock       (same lock that i know)
 * 2. try_lock   (same try_lock that i know)
 * 3.try_lock_for   -------\   Thee two function make it different from mutex
 * 4.try_lock_until -------/
 * 5. unlock     (same unlock that i know)
 */

// try_lock_for

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
// mutex mtx;
std::timed_mutex m; // we are using timed_mutex

int value = 0;
/**
 * ///////////////////////////Case1/////////////////////////////////////
void increment(int i){
    if(m.try_lock_for(std::chrono::seconds(2))){   // locked for 2 second
            ++value;
            std::this_thread::sleep_for(std::chrono::seconds(3)); // sleep for 3 sec means t2 will be waiting
            cout << "Thread " << i << " Entered "<< endl;
            m.unlock();
    }
    else{
        cout << "Thread " << i << " couldn't enter "<< endl;
    }
}
*/

/////////////////////////////////Case2////////////////////////////////////
void increment(int i){
    if(m.try_lock_for(std::chrono::seconds(2))){   // locked for 2 second
            ++value;
            std::this_thread::sleep_for(std::chrono::seconds(1)); // sleep for 1 sec means t2 will be entered
            cout << "Thread " << i << " Entered "<< endl;
            m.unlock();
    }
    else{
        cout << "Thread " << i << " couldn't enter "<< endl;
    }
}

int main (){
    thread t1 (increment,1);
    thread t2 (increment,2);

    t1.join();
    t2.join();

    //////////////////////////////case1//////////////////////////////
/**
    g++ 05_timed_mutex.cpp 
    jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$ ./a.out  
    Thread 2 couldn't enter 
    Thread 1 Entered 
    value = 1
    jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$ ./a.out  
    Thread 2 couldn't enter 
    Thread 1 Entered 
    value = 1
    jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$ ./a.out  
    Thread 1 couldn't enter 
    Thread 2 Entered 
    value = 1
    jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$
*/
    cout << "value = " << value << endl;
    return 0;
}