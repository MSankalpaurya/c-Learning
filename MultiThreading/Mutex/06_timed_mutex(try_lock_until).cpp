/**
 * Topic Timed Mutex i.e. std::timed_mutex
 * try_lock_until()
 * It wait until specified timeout time has been reached or the lock is aquired,
 * whichever comes first.
 * 
 * On successful lock acqusition returns true, otherwise return false.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
// mutex mtx;
std::timed_mutex m; // we are using timed_mutex

int value = 0;
/**
///////////////////////////Case1/////////////////////////////////////
void increment(int i){
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(2))){   // locked for 2 second from reference time
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
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(2))){   // locked for 2 second
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
    $ g++ 06_timed_mutex\(try_lock_until\).cpp
    jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$ ./a.out 
    Thread 2 couldn't enter 
    Thread 1 Entered 
    value = 1
    jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$
*/
    cout << "value = " << value << endl;
    return 0;
}