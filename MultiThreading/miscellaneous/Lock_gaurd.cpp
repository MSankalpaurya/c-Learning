#include <thread>
#include <iostream>
#include <mutex>

int count= 0;
std::mutex mtx;

void increment (int x){
    for (int i = 0; i< x; i++){

    // lock guard is light weight wrapper class of mutex
    // it acquires the lock every time it makes the object
    // when the object gets out of scope, the lock releases
    // there is no mechanism to unlock it
    // lock cannot be moved as well
      std::lock_guard <std::mutex> m(mtx);
      count ++;
    }
}

int main () {

    std::thread t1;
    t1 = std::thread(increment,10000);
    std::thread t2(increment,10000);

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    // return 0;

}