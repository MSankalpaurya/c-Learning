/**
 * TOPIC:Recusive mutex
 * 
 * NOTES:
 * 1. Same as mutex but, same thread can lock one mutex multiple times using recursive_mutex
 * 2. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1,
 *    now as T1 is running in recusion T1 can lock/try_lock any number of times
 *    there is no issue
 * 3. But if T1 have acquired 10 times lock/try_lock on mutex m1 then thread T1 will have to 
 *    unlock it 10 times otherwise no thread will be able to lock mutex m1.
 * 4. Hpw many time we can lock recursive_mutex is not defined but when that number reaches and
 *    if we were calling lock(), it will return std::system_error OR if were calling try_lock(),
 *    then it will return false
 * 
 * BOTTOMLINE:
 * 1. It is similer to mutex but have extra facitility that it can be locked multiple time by same 
 *    thread
 * 2. If we can avoide the recursive mutex then we should because it brings overhead to system
 * 3. it can be used in loop also
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::recursive_mutex m1;
// std::mutex m1;

int buffer = 0;

void recusion (char c, int loopfor){
    if (loopfor < 0){
        return;
    }
    m1.lock();
    cout << "Thread ID : "<< c <<" " << buffer++ <<endl;
    recusion(c, --loopfor); 
    m1.unlock();
}

int main (){
    thread t1 (recusion, '0', 10);
    thread t2 (recusion, '1', 10);

    t1.join();
    t2.join();

/**
 *  g++ 07_Recursive_mutex.cpp 
 *  jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Mutex$ ./a.out 
 *  Thread ID : 1 0
 *  Thread ID : 1 1
 *  Thread ID : 1 2
 *  Thread ID : 1 3
 *  Thread ID : 1 4
 *  Thread ID : 1 5
 *  Thread ID : 1 6
 *  Thread ID : 1 7
 *  Thread ID : 1 8
 *  Thread ID : 1 9
 *  Thread ID : 1 10
 *  Thread ID : 0 11
 *  Thread ID : 0 12
 *  Thread ID : 0 13
 *  Thread ID : 0 14
 *  Thread ID : 0 15
 *  Thread ID : 0 16
 *  Thread ID : 0 17
 *  Thread ID : 0 18
 *  Thread ID : 0 19
 *  Thread ID : 0 20
 *  Thread ID : 0 21 
 */    
    return 0;
}