/**
 * TOPIC:Unique Lock   (std::unique_lock <mutex> lock(m1))
 *  It is template class  then you haved to pass the mutex
 * 
 * NOTES:
 * 1. The class unique lock is a mutex ownership wrapper
 * 2. It Allows:
 * a) can have different locking strategies
 * b) time constrained attemps at locking (try_lock_for, try_lock_until())
 * c) recursive locking
 * d) Transfer of lock ownership (move not copy)
 * e) Condition variable 
 * 
 * 
 * 3.Locking Stratgies:
 *       TYPE                                EFFECTS
 * 1.  defer_lock                     do not acquire ownership of the mutex
 * 2.  try_to_lock                    try to acquire ownership of the mutex without blocking.
 * 3.  adopt_lock                     assume the calling thread already has ownership of the mutex
 */

#include <iostream>
#include <thread> 
#include <mutex>

using namespace std;

std::mutex m1;

int buffer = 0;

/**
// EXAMPLE Simple unique_lock
void increment (const char* threadNumber, int loopfor){
   std::unique_lock <mutex> m (m1); // automatically calls lock on mutex m1
    for (int i = 0; i <loopfor; i++){
        buffer++;
        cout << "threadNumber = " << threadNumber << "  " << buffer << endl;
    }
}

int main (){
    thread t1 (increment, "T1", 10);
    thread t2 (increment, "T2", 10);

    t1.join();
    t2.join();  
    return 0;
}
*/

// EXAMPLE 2 [DEFER_LOCK]
void increment (const char* threadNumber, int loopfor){
   std::unique_lock <mutex> unique(m1, defer_lock); // does not call on mutex m1, beacuse used defer lock

   // HERE YOU CAN WRITE N NO. OF CODE WITHOUT LOCKING  Because it give flexbility to lock when you wanted but in lock_guard it lock immediatelly


   unique.lock(); // But then we will have explicitly tell to lock when ever we want to lock mutex m1
    for (int i = 0; i <loopfor; i++){
        buffer++;
        cout << "threadNumber = " << threadNumber << "  " << buffer << endl;
    }
}

int main (){
    thread t1 (increment, "T1", 10);
    thread t2 (increment, "T2", 10);

    t1.join();
    t2.join();  
    return 0;
}