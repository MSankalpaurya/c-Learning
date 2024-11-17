/**
 * TOPIC: Thread or process synchronization
 * 
 * POINTS:
 * 1.0 thread or process synchronize to access critical section.
 * 2.0 Critical section is one or collection of program statements which should be executed by only one thread
 *     or process at a time
 */

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

long long bankBalance = 0;

void addMoney (long long val){
    mtx.lock(); // grant the chance only one at one time
    bankBalance += val;
    mtx.unlock();
}

int main (){
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney,200);

    t1.join();
    t2.join();

    std::cout << "Final bank balance: " << bankBalance <<std::endl;

 return 0;
}