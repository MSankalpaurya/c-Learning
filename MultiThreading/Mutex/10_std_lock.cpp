/**
 * TOPIC: std::lock()
 * 
 * it is used to lock multiple mutex at same time
 * 
 * //IMPORTANT 
 * SYNTEX ------> std::lock(m1,m2,m3,m4);
 * 1.0 All arguments are locked via a sequence of call to lock(), try_lock() or unlock on each 
 *     arguments
 * 2.0 Order of locking is not defined (it will try to lock provided mutex in any order and ensure
 *     that there is no dead lock)
 * 3.0 It is blocking call.
 * 
 * Exmple: 1
 *  No deadlock
 * 
 * Thread 1                           Thread 2
 * std::lock(m1,m2);              std::lock(m1,m2);
 * 
 * 
 * Exmple: 2
 *   No deadlock
 * 
 * Thread 1                           Thread 2
 * std::lock(m1,m2);              std::lock(m2,m1);
 * 
 * Exmple: 3
 *  No deadlock
 * 
 * Thread 1                           Thread 2
 * std::lock(m1,m2,m3,m4);              std::lock(m3,m4);
 *                                      std::lock(m1,m2); 
 * Exmple: 4
 *  Yes there is lock deadlock
 * 
 * Thread 1                           Thread 2
 * std::lock(m1,m2);              std::lock(m3,m4);
 * std::lock(m3,m4)               std::lock(m1,m2); 
 *
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mxt1,mxt2;

void task_a(){
    while (true)
    {
        std::lock(mxt1, mxt2);
        // mxt1.lock();
        // mxt2.lock();
        // mxt1.lock();  //  ========\
        mxt2.lock();  //     ========/  Cause the deadlock
        std::cout << "task a" << std::endl;
        mxt1.unlock();
        mxt2.unlock();
    }
    

}

void task_b(){
    while (true)
    {
        std::lock(mxt2, mxt1);
        // mxt2.lock();
        // mxt1.lock();
        std::cout << "task b" << std::endl;
        mxt2.unlock();
        mxt1.unlock();
    }
    

}

int main (){

    std::thread t1 (task_a);
    std::thread t2 (task_b);

    t1.join();
    t2.join();

    return 0;
}