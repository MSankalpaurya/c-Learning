/**
 * //Topic Mutex std::mutex::try_lock
 * 
 * 1. try_lock() Tries to lock the mutex. Return immediately. On successful lock acquisition
 *    return true otherwise false
 * 2. if try_lock() is not able to lock mutex, then it does not get blocked that's why it is
 *    called non-blocking 
 * 3. If try_lock() called again by the same thread which owns the mutex, the behaiouris
 *    undefined // LIKE double try_lock();
 *    IT IS DEAD LOCK SITUATION WITH UNDEFINED BEHAIOUR. (IF YOU LOCK THE SAME MUTEX BE SAME THRAD
 *    MORE THAN ONE AT TIME THEN GO FOR RECURSIVE MUTEX)
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

int value = 0;
void increment(){
    for(int i= 0; i< 10000; i++){
        if(mtx.try_lock()){
            ++value;
            mtx.unlock();
        }
    }
}

int main (){
    thread t1 (increment);
    thread t2 (increment);

    t1.join();
    t2.join();
    // here t1 and t2 are using common resouces;
    cout << "value = " << value << endl;
    return 0;
}
