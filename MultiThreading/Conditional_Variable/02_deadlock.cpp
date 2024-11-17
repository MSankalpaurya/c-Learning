/**
 * TOPIC: DEAD_LOCK
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mtx1,mtx2;

void fun1(){
    mtx1.lock();
    std::this_thread ::sleep_for(std::chrono::seconds(1)); // cause the deadlock
    mtx2.lock();
    cout << "critical section of fun1 thread one" <<endl;
    mtx1.unlock();
    mtx2.unlock();
}

void fun2(){
    mtx2.lock();
    std::this_thread ::sleep_for(std::chrono::seconds(1));
    mtx1.lock();
    cout << "critical section of fun2 thread two" <<endl;
    mtx2.unlock();
    mtx1.unlock();
}


int main (){

    thread t1 (fun1);
    thread t2 (fun2);

    t1.join();
    t2.join();

    return 0;
}