#include <thread>
#include <iostream>
#include <mutex>
// using namespace std;

int count= 0;
std::mutex mtx;

void increment (int x){
    for (int i = 0; i< x; i++){
      mtx.lock();
      count ++;
      mtx.unlock();
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