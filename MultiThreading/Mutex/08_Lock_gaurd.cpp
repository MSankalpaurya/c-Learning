/**
 * TOPIC:Lock_gaurd   (std::lock_gaurd<mutex> lock (m1))
 *                                              ||  |->mutex object
 *                                            Object  
 *  It is template class  then you haved to pass the mutex
 * 
 * NOTES:
 * 1. It is very light weight wrapper for owning mutex on , scoped basis
 * 2. It acquires mutex lock the moment you create the object of lock_gaurd
 * 3. It automatically remove the lock while goes out of scope
 * 4. you can not explicitly unlock the lock_gaurd
 * 5. You can not copy lock gaurd
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;

int buffer = 0;

void increment (const char* threadNumber, int loopfor){
   // m1.lock(); INSTEAD WRITE LOCK GUARD ===> here no need to lock at time of creation it locks automatically
   std::lock_guard <mutex> m (m1);
    for (int i = 0; i <loopfor; i++){
        buffer++;
        cout << "threadNumber = " << threadNumber << "  " << buffer << endl;
    }
    //m1.unlock(); no need to unlock when you are using the lock_gaurd
}

int main (){
    thread t1 (increment, "T1", 10);
    thread t2 (increment, "T2", 10);

    t1.join();
    t2.join();  
    return 0;
}